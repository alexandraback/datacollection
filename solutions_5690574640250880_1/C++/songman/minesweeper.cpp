#include <iostream>
using namespace std;

#define DEBUG cout << "DEBUG" << caseNum << endl;

void impossible(int caseNum){
	cout << "Case #" << caseNum << ":" << endl << "Impossible" << endl;
}

void possible(int caseNum, char ** grid, int r, int c){
	cout << "Case #" << caseNum << ":" << endl;

		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
				{
					cout << grid[i][j];
				}
				cout << endl;
		}
}

bool solveCase(char ** grid, int left, int  top, int rows, int cols, int mines){
	if(mines == 0)
		return true;

	if(rows <= 0 || cols <= 0)
		return false;

/*cols*/
	for(int i=0;i<cols-2 && mines != 0;i++,mines--){
		grid[top][left+i] = '*';
	}

	if(mines == 0)
		return true;

	if(mines >= 2){
		for(int i=cols-2;i<cols;i++){
			grid[top][left+i] = '*';
		}	
		mines-=2;
	
		if(mines == 0)
			return true;

		if(solveCase(grid,left,top+1,rows-1,cols,mines))
			return true;
	}
	else
	{
		if(solveCase(grid,left,top+1,rows-1,cols-2,mines))
			return true;
	}

/*roll back*/
	for(int i=0;i<cols;i++){
		if(grid[top][left+i] == '*'){
			grid[top][left+i] = '.';
			mines++;
		}
	}

/*rows*/
	for(int i=0;i<rows-2 && mines != 0;i++,mines--){
		grid[top+i][left] = '*';
	}

	if(mines == 0)
		return true;

	if(mines >= 2){
		for(int i=rows-2;i<rows;i++){
			grid[top+i][left] = '*';
		}	
		mines-=2;
	
		if(mines == 0)
			return true;

		if(solveCase(grid,left+1,top,rows,cols-1,mines))
			return true;
	}
	else
	{
		if(solveCase(grid,left+1,top,rows-2,cols-1,mines))
			return true;
	}
/*roll back*/
	for(int i=0;i<rows;i++){		
		if(grid[top+i][left]  == '*'){
			grid[top+i][left]  = '.';
			mines++;
		}
	}

	return false;
}


void solveCase(int caseNum){


	int R, C, M;

	cin >> R >> C >> M;

//	if(caseNum!=5) return;


	char ** grid  = new char * [R];
	for(int i=0;i <R;i++){
		grid[i] = new char[C];
		for(int j=0;j<C;j++)
			grid[i][j] = '.';
	}

	grid[R-1][C-1] ='c';

	if(M==0){
		possible(caseNum,grid,R,C);
		return;
	}

	if(R*C-1==M){
		for(int i=0;i <R;i++)
			for(int j=0;j <C;j++)
			{
				grid[i][j] = '*';
			}

		grid[R-1][C-1] ='c';		
		possible(caseNum,grid,R,C);
		return;
	}
	
	if(R==1){
		
		for(int i =0;i < M;i++)
			grid[R-1][i] = '*';

		possible(caseNum,grid,R,C);
		return;
	}

	if(C==1){
		
		for(int i =0;i < M ;i++)
			grid[i][C-1] = '*';

		possible(caseNum,grid,R,C);
		return;
	}

	if(R==2){
		if(M % 2 != 0){
			impossible(caseNum);
			return;
		}
		else
		{

			if(C*2 - M < 4){
				impossible(caseNum);
				return;
			}

			for(int i =0;M!=0;i++){
				grid[R-1][i] = '*';
				grid[R-2][i] = '*';
				M-=2;
			}
		}
		possible(caseNum,grid,R,C);
		return;
	}

	if(C==2){
		if(M % 2 != 0){
			impossible(caseNum);
			return;
		}
		else
		{
			if(R*2 - M < 4){
				impossible(caseNum);
				return;
			}

			for(int i =0;M!=0;i++){
				grid[i][C-1] = '*';
				grid[i][C-2] = '*';
				M-=2;
			}
		}
		possible(caseNum,grid,R,C);
		return;
	}

	int mtmp = M;

	for(int i=0;i<(C-2) && mtmp!=0;i++){
		for(int j=0;j<(R-2) && mtmp!=0;j++){
			grid[j][i] = '*';
			mtmp--;
		}	
	}

	
	if(M<=(C-2)*(R-2)){
		
		possible(caseNum,grid,R,C);
		return;
	}

	int rm = M - (C-2)*(R-2);

	if(rm % 2 == 0){
		for(int i=0;i<R-2 && rm != 0;i++){
			grid[i][C-2] = '*';
			grid[i][C-1] = '*';
			rm-=2;
		}

		for(int i=0;i<C-2 && rm != 0;i++){
			grid[R-2][i] = '*';
			grid[R-1][i] = '*';
			rm-=2;
		}

		if(rm){
			impossible(caseNum);
		}
		else
		{
			possible(caseNum,grid,R,C);
		}
		return;
	}
	else {
		rm++;
		grid[R-3][C-3] = '.';
		for(int i=0;i<C-3 && rm != 0;i++){
			grid[R-2][i] = '*';
			grid[R-1][i] = '*';
			rm-=2;
		}

		for(int i=0;i<R-3 && rm != 0;i++){
			grid[i][C-2] = '*';
			grid[i][C-1] = '*';
			rm-=2;
		}

		if(rm){
			impossible(caseNum);
		}
		else
		{
			possible(caseNum,grid,R,C);
		}
	}

	
}




int main(){
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		solveCase(i+1);
	}	
	return 0;
}