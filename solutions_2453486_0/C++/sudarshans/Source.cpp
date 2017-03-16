#include <cstdio>
#include <ciso646>
#include <iostream>

using namespace std;

void printArray( int arr[4][4] ) 
{
	for(int row=0;row<4;row++,putchar('\n'))
		for(int col=0;col<4;col++)
			putchar(arr[row][col]==1?'Y':'N');
}

int win(int arr[4][4]){
	//check rows for win
	for(int row=0;row<4;row++)
		if(arr[row][0]==1 and arr[row][1]==1 and arr[row][2]==1 and arr[row][3]==1)
			return 1;

	//check cols for win
	for(int col=0;col<4;col++)
		if(arr[0][col]==1 and arr[1][col]==1 and arr[2][col]==1 and arr[3][col]==1)
			return 1;

	//check 2 diagonals
	if(arr[0][0]==1 and arr[1][1]==1 and arr[2][2]==1 and arr[3][3]==1)
		return 1;

	if(arr[0][3]==1 and arr[1][2]==1 and arr[2][1]==1 and arr[3][0]==1)
		return 1;

	return 0;
}

int draw(int x[4][4], int y[4][4]){
	//check for draw ie no empty slots and neither win
	for(int row=0; row<4; row++)
		for(int col=0; col<4; col++)
			if(x[row][col]==0 and y[row][col]==0)
				return 0;
	return 1;
}

int main(){
	int numCases;
	scanf("%d",&numCases);
	for(int i=0;i<numCases;i++){
		int X[4][4],O[4][4];
		for(int row=0,col=0;;){
			char ch=getchar();
			switch(ch){
			case 'X':
				X[row][col]=1;
				O[row][col]=0;
				col++;
				if(col>3) col=0,row++;
				if(row>3) goto read;
				break;
			case 'O':
				O[row][col]=1;
				X[row][col]=0;
				col++;
				if(col>3) col=0,row++;
				if(row>3) goto read;
				break;
			case 'T':
				X[row][col]=1;
				O[row][col]=1;
				col++;
				if(col>3) col=0,row++;
				if(row>3) goto read;
				break;
			case '.':
				X[row][col]=0;
				O[row][col]=0;
				col++;
				if(col>3) col=0,row++;
				if(row>3) goto read;
				break;
			}
		}
read:
	if(win(X))
		printf("Case #%d: X won\n",i+1);
	else if(win(O))
		printf("Case #%d: O won\n",i+1);
	else if(draw(X,O))
		printf("Case #%d: Draw\n",i+1);
	else
		printf("Case #%d: Game has not completed\n",i+1);
	}
	return 0;
}