#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TestCases, TCCount;
int Map[120][120];
int Rows, Columns, Min, TryY, TryX, TryMin;
int MinX[120];
int MinY[120];
int x, y;

int Ans(){
	TryMin = 1000;
	Min = 1000;
	TryY = 1000;
	TryX = 1000;
	
	for (y=0; y<Rows; y++) if (MinY[y]<Min){
		TryMin = MinY[y];
		for (x=0; x<Columns; x++){
			if (Map[y][x]==MinY[y]) continue;
			else break;
		}
		if (x==Columns){
			Min = MinY[y];
			TryY = y;
			TryX = 1000;
		}
	}
	for (x=0; x<Columns; x++) if (MinX[x]<Min){
		TryMin = MinX[x];
		for (y=0; y<Rows; y++){
			if (Map[y][x]==MinX[x]) continue;
			else break;
		}
		if (y==Rows){
			Min = MinX[x];
			TryY = 1000;
			TryX = x;
		}
	}
	if (TryX==1000) if (TryY==1000) return 0;
	if (TryY<1000) if (TryMin!=MinY[TryY]) return 0;
	if (TryX<1000) if (TryMin!=MinX[TryX]) return 0;
	
	if (TryY<1000){
		Rows--;
		for (x=0; x<Columns; x++) Map[TryY][x] = Map[Rows][x];
		MinY[TryY] = MinY[Rows];
		for (x=0; x<Columns; x++){
			MinX[x] = 1000;
			for (y=0; y<Rows; y++) if (Map[y][x]<MinX[x]) MinX[x] = Map[y][x];
		}
		return 1;
	}
	if (TryX<1000){
		Columns--;
		for (y=0; y<Rows; y++) Map[y][TryX] = Map[y][Columns];
		MinX[TryX] = MinX[Columns];
		for (y=0; y<Rows; y++){
			MinY[y] = 1000;
			for (x=0; x<Columns; x++) if (Map[y][x]<MinY[y]) MinY[y] = Map[y][x];
		}
		return 1;
	}
}

int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	
	scanf("%d", &TestCases);
	for (TCCount=1; TCCount<=TestCases; TCCount++){
		printf("Case #%d: ", TCCount);
		scanf("%d%d", &Rows, &Columns);
		for (y=0; y<Rows; y++) for (x=0; x<Columns; x++) scanf("%d", &Map[y][x]);
		
		for (y=0; y<Rows; y++){
			MinY[y] = 1000;
			for (x=0; x<Columns; x++) if (Map[y][x]<MinY[y]) MinY[y] = Map[y][x];
		}
		for (x=0; x<Columns; x++){
			MinX[x] = 1000;
			for (y=0; y<Rows; y++) if (Map[y][x]<MinX[x]) MinX[x] = Map[y][x];
		}
		
		while(Rows&&Columns){
			if (Ans()) continue;
			else break;
		}
		
		if (Rows&&Columns) printf("NO\n");
		else printf("YES\n");
		
	}
	
	return 0;
}

