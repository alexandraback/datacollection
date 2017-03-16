
/*
 * 	FILENAME - FILEDESCRIPTION
 *		Programmed by kcrt <kcrt@kcrt.net>
 */

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int DebugPrint(int c[][100], int x, int y){

	printf("x, y = %d, %d\n", x, y);

	for(int _y=0; _y<y; _y++){
		for(int _x=0; _x<x; _x++){
			printf("%3d ", c[_x][_y]);
		}
		printf("\n");
	}

	return 1;
}

bool IsPossible(int t[100][100], int cX, int cY){

	for(int x=0; x<cX; x++){
		for(int y=0; y<cY; y++){
			int XCheckOK = 1;
			int YCheckOK = 1;
			// 縦 と 横、ともに自分より高い奴がいる→無理
			for(int i = 0; i < cX; i++){
				if(t[i][y] > t[x][y]){
					XCheckOK = 0;
					break;
				}
			}
			for(int i = 0; i < cY; i++){
				if(t[x][i] > t[x][y]){
					YCheckOK = 0;
					break;
				}
			}
			if(!XCheckOK && !YCheckOK){
				return false;
			}
		}
	}
	return true;
}

int main(){

	int testcase;
	int t[100][100];
	int cX, cY;
	int highest;

	scanf("%d", &testcase);

	for(int i = 0; i < testcase; i++){
		scanf("%d %d", &cY, &cX);
		for(int y=0; y<cY; y++){
			for(int x=0; x<cX; x++){
				scanf("%d", &t[x][y]);
			}
		}
		//DebugPrint(t, cX, cY);;

		printf("Case #%d: %s\n", i+1, IsPossible(t, cX, cY) ? "YES" : "NO");
	}

}
