#include "graphics.h" 
#include <bits/stdc++.h> 
using namespace std; 

//animated swapping of the function 
void swap2(int i, int j, int x, int y, int size) {
    int steps = 20; 
    int dx = (j - i) / steps; 
    int dy1 = (y - x) / steps; 
    int dy2 = (x - y) / steps; 
    
    for (int step = 0; step < steps; ++step) {
        setcolor(BLACK);
        line(i + step * dx, size, i + step * dx, size - (x + step * dy1));
        line(j - step * dx, size, j - step * dx, size - (y + step * dy2));
        
        setcolor(WHITE);
        line(i + (step + 1) * dx, size, i + (step + 1) * dx, size - (x + (step + 1) * dy1));
        line(j - (step + 1) * dx, size, j - (step + 1) * dx, size - (y + (step + 1) * dy2));
        delay(10);
    }
    
    setcolor(BLACK);
    line(i + steps * dx, size, i + steps * dx, size - (x + steps * dy1));
    line(j - steps * dx, size, j - steps * dx, size - (y + steps * dy2));
    
    setcolor(WHITE);
    line(i, size, i, size - y);
    line(j, size, j, size - x);
}

void swap(int i, int j, int x, int y, int len){ 
	//marking the lines to be swapped
	setcolor(RED);
	line(i, len, i, len - x);
	setcolor(YELLOW);
	line(j, len, j, len - y);
	delay(400);

	//erasing the marked lines
	setcolor(BLACK);
	line(i, len, i, len - x);
	setcolor(BLACK);
	line(j, len, j, len - y);
	delay(200);

	//printing the lines after swapping
	setcolor(WHITE);
	line(i, len, i, len - y);
	setcolor(WHITE);
	line(j, len, j, len - x);
	delay(400);
} 

void f(int len, int gap, vector<int> &arr) { 
	for (int i = 0; i < len; i++) { 
		for (int j = 0; j < len-i-1; j++) { 
			if (arr[j] > arr[j + 1]) { 
				swap(1+gap*j, gap*(j + 1)+1, arr[j],arr[j+1], len); 
				arr[j] = (arr[j]*arr[j+1])/(arr[j+1]=arr[j]); 		//swapping for future swappings
			} 
		} 
	} 
} 

int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	int len = 200, gap=5;
	vector<int> arr;
	
	int width = initwindow(gap * len, len); 
	setcurrentwindow(width); 
    
	for(int i=0;i<len;i++) arr.push_back(rand()%len);
	//plotting the lines as the array elements
	for(int i=1;i<len*gap;i+=gap){
		line(i, len, i, len - arr[i/gap]);
		delay(10); 
	}
	delay(1000);
	f(len, gap, arr); 
	delay(5000);

	return 0; 
} 
