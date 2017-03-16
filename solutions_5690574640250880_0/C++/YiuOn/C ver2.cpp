#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	freopen("C-small-attempt4.in", "r", stdin);
	freopen("C out.txt", "w", stdout);

	/*for(int i=0; i<5; i++){
		for(int j =0; j<5; j++){
			for(int k =0; k<=(i+1)*(j+1); k++){
				cout << i+1 << " " << j+1  << " " << k << endl;;
			}
		}
	}
	return 0;*/

	int T,count,R,C,M;
	char** grid;
	
	scanf("%d", &T);
	
	count = 1;
	while(T--){
		bool possible = false;
		scanf("%d %d %d", &R, &C, &M);
		//cout << R << " " << C << " " << M << endl;
		int space = R*C-M;

		grid = new char*[R];
		for(int i=0; i<R; i++){
			grid[i] = new char[C];
			for(int j=0; j<C; j++){
				grid[i][j] = '*';
			}
		}
		
		if(M == 0){
			possible = true;
			for(int i=0; i<R; i++){
				for(int j=0; j<C; j++){
					grid[i][j] = '.';
				}
			}
			grid[0][0] = 'c';
		}else if(M == R*C){
			possible = false;
		}else if(R == 1 || C == 1){
			int countSpace = 0;
			for(int i=0; i<R; i++){
				for(int j=0; j<C; j++){
					if(countSpace < space){
						grid[i][j] = '.';
						countSpace++;
					}
				}
			}
			grid[0][0] = 'c';
			possible = true;
		}else if(space == 1){
			grid[0][0] = 'c';
			possible = true;
		}else if(R == 2 || C == 2){
			if(space == 2){
				possible = false;
			}else if(space%2 == 0){
				int length = space/2;
				if(R == 2){
					for(int i=0; i<R; i++){
						for(int j=0; j<length; j++){
							grid[i][j] = '.';
						}
					}
					grid[0][0] = 'c';
				}else{
					for(int i=0; i<length; i++){
						for(int j=0; j<C; j++){
							grid[i][j] = '.';
						}
					}
					grid[0][0] = 'c';
				}
				possible = true;
			}else{
				possible = false;
			}
		}else{
			if(space >= 4){
				possible = true;
				int row = 2;
				int col = space/row;
				while(col >= C){
					row++;
					col = space/row;
				}
				int remain = space-row*col;

				bool down = true;
				if(col == C){
					down = true;
				}else if(row == R){
					down = false;
				}

				int borrow = 0;
				if(remain == 1){
					if(row == R){
						if(col > 2){
							remain++;
							borrow++;
							if(remain > row-1){
								possible = false;
							}
						}else{
							remain += col;
							row--;
							if(remain > row){
								possible = false;
							}
						}
					}else if(col == C){
						if(row > 2){
							remain++;
							borrow++;
							if(remain > col-1){
								possible = false;
							}
						}else{
							remain += row;
							col--;
							if(remain > col){
								possible = false;
							}
						}
					}else{
						if(row > col){
							if(col > 2){
								remain++;
								borrow++;
								if(remain > row-1){
									possible = false;
								}
							}else{
								remain += col;
								row--;
								if(remain > row){
									possible = false;
								}
							}
						}else{
							if(row > 2){
								remain++;
								borrow++;
								if(remain > col-1){
									possible = false;
								}
							}else{
								remain += row;
								col--;
								if(remain > col){
									possible = false;
								}
							}
						}
					}
				}

				if(row == 1 || col == 1){
					possible = false;
				}
				if(row > R || col > C){
					possible = false;
				}
				//down = true;
				if(row == R){
					down = false;
				}else if(col == C){
					down = true;
				}else if(remain > row){
					down = true;
				}else if(remain > col){
					down = false;
				}

				if(possible){
					for(int i=0; i<row; i++){
						for(int j=0; j<col; j++){
							grid[i][j] = '.';
						}
					}
					if(borrow == 1){
						grid[row-1][col-1] = '*';
					}
					if(down){
						for(int i=0; i<remain; i++){
							grid[row][i] = '.';
						}
					}else{
						for(int i=0; i<remain; i++){
							grid[i][col] = '.';
						}
					}

					grid[0][0] = 'c';
				}
			}else{
				possible = false;
			}
		}

		// print
		printf("Case #%d:\n", count++);
		if(possible){
			for(int i=0; i<R; i++){
				for(int j=0; j<C; j++){
					printf("%c", grid[i][j]);
				}
				printf("\n");
			}
		}else{
			printf("Impossible\n");
		}

		/*for(int i=0; i<R; i++){
			delete grid[i];
		}*/
		delete [] grid;
	}
	

	return 0;
}