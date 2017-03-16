#include <cstdio>
#include <ciso646>
#include <iostream>

using namespace std;

int lawn[101][101];
int rowMax[101];
int colMax[101];

int calculateColMax(int col, int rows){
	int currentMax=lawn[0][col];
	for(int row=1; row<rows; row++)
		if(lawn[row][col]>currentMax)
			currentMax=lawn[row][col];
	return currentMax;
}

int calculateRowMax(int row, int cols){
	int currentMax=lawn[row][0];
	for(int col=1; col<cols; col++)
		if(lawn[row][col]>currentMax)
			currentMax=lawn[row][col];
	return currentMax;
}

int possible(int rows, int cols){
	for(int row=0; row<rows; row++)
		for(int col=0; col<cols; col++){

			//if less than row maximum, everything in column must be <= this
			//therefore maximum in column must be <= this
			if(lawn[row][col]<rowMax[row])
				if(colMax[col]>lawn[row][col])
					return 0;

			//if less than col maximum, everything in row must be <= this
			//therefore maximum in row must be <= this
			if(lawn[row][col]<colMax[col])
				if(rowMax[row]>lawn[row][col])
					return 0;
		}
	return 1;
}

int main(){
	int numCases;
	cin>>numCases;
	for(int i=0;i<numCases;i++){
		int rows,cols;
		cin>>rows>>cols;
		for(int row=0;row<rows;row++)
			for(int col=0;col<cols;col++)
				cin>>lawn[row][col];

		for(int col=0; col<cols; col++)
			colMax[col]=calculateColMax(col,rows);

		for(int row=0; row<rows; row++)
			rowMax[row]=calculateRowMax(row,cols);

		if(possible(rows,cols))
			printf("Case #%d: YES\n",i+1);
		else
			printf("Case #%d: NO\n",i+1);
	}
	return 0;
}