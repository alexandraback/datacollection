#include <stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
#include <vector>
#include <algorithm>
#include <math.h>
FILE *in, *out;
using namespace std;

int hit(int width,int ship){
	if (width == ship || ship == 1|| width-ship==1){
		return width;
	}
	if (width <ship){
		return ship;
	}
	return 1 + hit(width - ship, ship);
}


int main(){
	out = fopen("1.out", "w");
	int T; int ans = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		int R, C, W;
		scanf("%d %d %d", &R,&C,&W);
		int ans = hit(C, W) + (R - 1)*(C / W);


		printf("Case #%d: %d\n", i + 1, ans);
		fprintf(out, "Case #%d: %d\n", i + 1,ans );
	}
	return 0;
}