#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 1000010
int s[MAX];
int T;
int X,Y;
int res = 0;

void printStep(int step, int Y, int minus, const char*letter) {	
	int idx = 0;
	if (Y < 0) idx = 1;
	if (step == minus) idx = idx^1;
	printf("%c",letter[idx]);
}

int main() {
	scanf("%d",&T);
	
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d%d",&X,&Y);
		int total = abs(X) + abs(Y);
		int step = 1;
		int cur = 1;
		while (cur < total) {
			step++;
			cur += step;
		}
		while ((cur - total) % 2) {
			step++;
			cur += step;
		}
		int minusElement = (cur-total)/2;
		bool overshoot2 = false;
		if (minusElement > step){ 
			minusElement -= step;
			overshoot2 = true;
			}
		//printf("minusElement is %d\n",minusElement);
		//plus from 1 to step inclusive except minusElement
		memset(s, 0, sizeof(s));
		int small = min( abs(X), abs(Y));
		int i = 1;
		cur = 0;
		while (cur < small) {
			cur += (i == minusElement) ? -i : i; 
			s[i] = 1;
			//printf("add to small %d\n",i);
			i++;
		}
		if (cur > small) {
			int takeoff = cur-small;
			//printf("takeoff is %d\n",takeoff);
			if (takeoff != minusElement) {
				s[takeoff] = 0;
			} else {
				s[i] = 1;
				s[i-1] = 0;
				s[takeoff+1] = 0;
			}
		}
		printf("Case #%d: ", tc);
		bool horiz = (small == abs(X));
		for (int i = 1; i <= step; i++) {
			//printf("s[%d]=%d\n",i,s[i]);	
			if (i == step && overshoot2) {
				minusElement =  step;
				//continue;
			}			
			if (s[i] == 0) {
				if (horiz) {
					printStep(i,Y,minusElement,"NS");					
				} else 
					printStep(i,X,minusElement,"EW");
			}else {
				if (horiz) {
					printStep(i,X,minusElement,"EW");					
				} else 
					printStep(i,Y,minusElement,"NW");
			}
		}
		printf("\n");
	}
	
	return 0; 
}
