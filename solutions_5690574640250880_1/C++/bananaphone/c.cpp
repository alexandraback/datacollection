#include <iostream>
#include <vector>

using namespace std;

void doprob(int R, int C, int M, int index){
	int i, j, k;
	cout << "Case #" << index << ":" << endl;
	if(R == 1){
		for(i=0; i<C; ++i){
			if(i<M){
				cout << "*";
			}
			else if(i != C-1){
				cout << ".";
			}
			else{
				cout << "c" << endl;
			}
		}
		return;
	}
	if(C == 1){
		for(i=0; i<R; ++i){
			if(i<M){
				cout << "*" << endl;
			} else if(i != R-1){
				cout << "." << endl;
			} else{
				cout << "c" << endl;
			}
		}	
		return;
	}
	if(R == 2){
		if((M%2 != 0 || M == 2*C-2) && M != 2*C-1){
			cout << "Impossible" << endl;
			return;
		} else if(M != 2*C-1){
			for(i=0; i< C; ++i){
				if(i<M/2){
					cout << "*";
				}
				else{
					cout << ".";
				}
			}
			cout << endl;
			for(i=0; i< C; ++i){
				if(i<M/2){
					cout << "*";
				}
				else if (i != C -1){
					cout << ".";
				} else{
					cout << "c" << endl;
				}
			}
			return;
		} else{
			for(i=0; i<C; ++i){
				cout << "*";
			}
			cout << endl;
			for(i=0; i<C-1; ++i){
				cout << "*";
			}
			cout << "c" << endl;
			return;
		}
	}
	if(C == 2 ){
		if((M%2 != 0 || M == 2*R-2) && M != 2*R-1){
			cout << "Impossible" << endl;
			return;
		} else if(M != 2*R-1){
			for(i=0; i<R; ++i){
				if(i < M/2){
					cout << "**" << endl;
				} else if(i != R-1){
					cout << ".." << endl;
				} else {
					cout << ".c" << endl;
				}
			}
			return;
		} else{
			for(i=0; i< R; ++i){
				if(i != R-1){
					cout << "**" << endl;
				}
				else{
					cout << "*c" << endl;
				}
			}
			return;
		}
	}

	int empty = R*C-M;
	if(M <= (R-2)*(C-2)){
		k=0;
		for(i=0; i<R; ++i){
			for(j=0; j<C; ++j){
				if(j < C-2 && k < M){
					cout << "*";
					k++;
				} else if (i != R-1 || j != C-1) {
					cout << ".";
				} else {
					cout << "c";
				}
			}
			cout << endl;
		}
		return;
	}

	int excess = M - (R-2)*(C-2);
	if (empty >= 8){
		if(excess %2 == 0){
			k=0;
			for(i=0; i<R-2; ++i){
				for(j=0; j<C; ++j){
					if( j < C-2){
						cout << "*";
					} else if(k < excess){
						cout << "*";
						k++;
					} else{
						cout << ".";
					}
				}
				cout << endl;
			}
			for(i=0; i<C; ++i){
				if(i < (excess-k)/2){
					cout << "*";
				}
				else{
					cout << ".";
				}
			}
			cout << endl;
			for(i=0; i<C; ++i){
				if(i < (excess-k)/2){
					cout << "*";
				}
				else if(i != C-1){
					cout << ".";
				}
				else {
					cout << "c" << endl;
				}
			}
			return;
		}
		else{
			k=-1;
			for(i=0; i<R-3; ++i){
				for(j=0; j<C; ++j){
					if( j < C-2){
						cout << "*";
					} else if(k < excess){
						cout << "*";
						k++;
					} else{
						cout << ".";
					}
				}
				cout << endl;
			}
			for(i=0; i<C; ++i){
				if(i < C-3){
					cout << "*";
				}
				else{
					cout << ".";
				}
			}
			cout << endl;
			for(i=0; i<C; ++i){
				if(i < (excess-k)/2){
					cout << "*";
				}
				else{
					cout << ".";
				}
			}
			cout << endl;
			for(i=0; i<C; ++i){
				if(i < (excess-k)/2){
					cout << "*";
				}
				else if(i != C-1){
					cout << ".";
				}
				else {
					cout << "c" << endl;
				}
			}
			return;
		}
	}

	if(empty == 2 || empty == 3 || empty == 5 || empty == 7){
		cout << "Impossible" << endl;
		return;
	}
	if(empty == 1){
		for(i=0; i<R; ++i){
			for(j=0; j<C; ++j){
				if(i != R-1 || j != C-1){
					cout << "*";
				}
				else{
					cout << "c";
				}
			}
			cout << endl;
		}
		return;
	}
	if(empty == 4){
		for(i=0; i<R; ++i){
			for(j=0; j<C; ++j){
				if(i < R-2 || j < C-2){
					cout << "*";
				}
				else if(i != R -1 || j != C -1){
					cout << ".";
				} else {
					cout << "c";
				}
			}
			cout << endl;
		}
		return;
	}
	if(empty = 6){
		for(i=0; i<R; ++i){
			for(j=0; j<C; ++j){
				if(i < R-2 || j < C-3){
					cout << "*";
				}
				else if(i == R - 2 || j != C -1){
					cout << ".";
				} else {
					cout << "c";
				}
			}
			cout << endl;
		}
		return;
	}

}



int main(){
	int i;
	int cases;
	int R, C, M;
	cin >> cases;
	for(i=1; i<=cases; ++i){
		cin >> R >> C >> M;
		doprob(R, C, M, i);
	}
	return 0;
}
