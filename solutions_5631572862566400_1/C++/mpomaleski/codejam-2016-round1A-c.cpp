#include <bits/stdc++.h>

using namespace std;

int next[1500];
int status[1500];
int circleSize[1500];
int starter;
int numCircles[1500];
int maxCircle2[1500];

int calculateCircleSize(int x, int pSize){
	status[x] = pSize;
	if(status[next[x]] != 0){
		circleSize[x] = status[x]-status[next[x]]+1;
		if(circleSize[x] != 2){
			numCircles[circleSize[x]]++;
			//printf("Circle %d\n", circleSize[x]);
		}
		return circleSize[x];
	}
	circleSize[x] = calculateCircleSize(next[x], pSize+1);
	if(circleSize[x] == 2){
		if(maxCircle2[x] == 0){
			numCircles[2]++;
		}
		circleSize[x] = pSize+1;
		if(maxCircle2[x] < pSize+1){
			maxCircle2[x] = pSize+1;
		//	printf("Circle2[%d] %d\n", x, maxCircle2[x]);
		}
	}
	return circleSize[x];
}

int main(){
	int t;
	scanf(" %d", &t);
	for(int k = 1; k <= t; k++){
		int n;
		scanf(" %d", &n);
		for(int i = 1; i <= n; i++){
			scanf(" %d", &(next[i]));
			circleSize[i] = -1;
			maxCircle2[i] = 0;
			numCircles[i] = 0;
		}
		for(int i = 1; i <= n; i++){
			if(circleSize[i] == -1){
				for(int j = 1; j <= n; j++){
					status[j] = 0;
				}
				calculateCircleSize(i, 1);
			}
		}
		int maxCircleSize = 0;
		for(int i = 1; i <= n; i++){
			if(numCircles[i] > 0){
				maxCircleSize = i;
			}
		}
		int numCircle2Size = 0;
		for(int i = 1; i <= n; i++){
			numCircle2Size += maxCircle2[i];
			if(maxCircle2[i] != 0 && maxCircle2[next[i]] != 0)
				numCircle2Size--;
	//		printf("%d %d\n", numCircle2Size, i);
		}
		int res = maxCircleSize;
		if(numCircle2Size > maxCircleSize){
			res = numCircle2Size;
		}
		printf("Case #%d: %d\n", k, res);
	}
	return 0;
}