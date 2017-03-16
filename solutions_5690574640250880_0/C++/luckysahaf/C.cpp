#include <iostream>
using namespace std;

void add_adjacency(char **grid,int row,int col,int rows,int cols){
	if(col-1 >= 0 && grid[row][col-1] != '*')
		grid[row][col-1] += (char)1;
	if(row-1 >= 0 && grid[row-1][col] != '*')
		grid[row-1][col] += (char)1;
	if(row-1 >= 0 && col-1 >=0 && grid[row-1][col-1] != '*')
		grid[row-1][col-1] += (char)1;
	if(row+1 < rows && col-1 >=0 && grid[row+1][col-1] != '*')
		grid[row+1][col-1] += (char)1;
	if(row-1 >= 0 && col+1 < rows && grid[row-1][col+1] != '*')
		grid[row-1][col+1] += (char)1;
}

bool is_discoverable(char **grid,int row,int col,int rows,int cols){
	if((grid[row][col] == '0') || (col-1 >= 0 && grid[row][col-1] == '0') || (row-1 >= 0 && grid[row-1][col] == '0') || (row-1 >= 0 && col-1 >=0 && grid[row-1][col-1] == '0')
		|| (row+1 < rows && col-1 >=0 && grid[row+1][col-1] == '0') || (row-1 >= 0 && col+1 < rows && grid[row-1][col+1] == '0') ){
		return true;
	}
	return false;
}

bool solve(char **grid, int rows,int cols,int mines){
	if(mines == (rows*cols)-1){
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				grid[i][j] = '*';
			}
		}
		grid[0][0] = 'c';
		return true;
	}

	int current_row = rows-1;
	int current_col = cols-1;
	while(mines >= min(current_col+1,current_row+1)){
		if(current_row <= current_col){
			if(mines >= current_row+1){
				for(int i=current_row;i>=0;i--){
					grid[i][current_col] = '*';
					add_adjacency(grid,i,current_col,rows,cols);
				}
				current_col--;
				mines -= (current_row+1);
			}
			else{
				for(int i=current_col;i>=0;i--){
					grid[current_row][i] = '*';
					add_adjacency(grid,current_row,i,rows,cols);
				}
				current_row--;
				mines -= (current_col+1);
			}
		}
		else{
			if(mines >= current_col+1){
				for(int i=current_col;i>=0;i--){
					grid[current_row][i] = '*';
					add_adjacency(grid,current_row,i,rows,cols);
				}
				current_row--;
				mines -= (current_col+1);
			}
			else{
				for(int i=current_row;i>=0;i--){
					grid[i][current_col] = '*';
					add_adjacency(grid,i,current_col,rows,cols);
				}
				current_col--;
				mines -= (current_row+1);
			}
		}
	}

	for(int i=mines;i>0;i--){
		if(current_row <= current_col){
			if(i%2){
				grid[current_row-(i/2)][current_col] = '*';
				add_adjacency(grid,current_row-(i/2),current_col,rows,cols);
			}
			else{
				grid[current_row][current_col-(i/2)] = '*';
				add_adjacency(grid,current_row,current_col-(i/2),rows,cols);
			}
		}
		else{
			if(i%2){
				grid[current_row][current_col-(i/2)] = '*';
				add_adjacency(grid,current_row,current_col-(i/2),rows,cols);
			}
			else{
				grid[current_row-(i/2)][current_col] = '*';
				add_adjacency(grid,current_row-(i/2),current_col,rows,cols);
			}
		}
	}
	for(int i=0;i<rows;i++){
		for (int j=0;j<cols;j++){
			if(grid[i][j] != '*'){
				if(!is_discoverable(grid,i,j,rows,cols))
					return false;
			}
		}
	}

	grid[0][0] = 'c';
	return true;
}

int main(){
	int T,R,C,M;
	cin >> T;
	char **grid;
	for(int i=0;i<T;i++){
		cin >> R >> C >> M;
		grid = new char*[R];
		for(int j=0;j<R;j++){
			grid[j] = new char[C];
			for(int k=0;k<C;k++){
				grid[j][k] = '0';
				
			}
		}
		bool possible = solve(grid,R,C,M);
		if(possible){
			cout << "Case #" << i+1 << ":" << endl;
			for(int i=0;i<R;i++){
				for(int j=0;j<C;j++){
					if(grid[i][j] == '*' || grid[i][j] == 'c')
						cout << grid[i][j];
					else
						cout << ".";
				}
				cout << endl;
			}
		}
		else{
			cout << "Case #" << i+1 << ":\nImpossible" << endl;
		}
	}
}