#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
	int T; cin >> T;

	for(int t=0; t<T; t++){
		cout << "Case #" << t+1 << ": " << endl;

		int R,C,M; cin >> R >> C >> M;
		int total_m = M;

		char board[R][C];
		for(int r=0; r<R; r++){
			for(int c=0; c<C; c++){
				board[r][c] = '.';
			}
		}
		board[R-1][C-1] = 'c';

		if(R==1 || C==1){
			for(int r=0; r<R; r++){
				for(int c=0; c<C; c++){
					if(0<M--) board[r][c] = '*';
				}
			}

			for(int r=0; r<R; r++){
				for(int c=0; c<C; c++){
					cout << board[r][c];
				}
				cout << endl;
			}

			continue;
		}
	
		for(int r=0; r<R-2; r++){
			for(int c=0; c<C-2; c++){
				if(M==0) break;
				if(r==R-3 && c==C-3) break;
				board[r][c] = '*';
				M--;
			}
			if(M==0) break;
		}

		for(int c=0; c<C-3;c++){
			if(M<=1) break;
			board[R-2][c] = '*';
			board[R-1][c] = '*';
			M-=2;
		}

		for(int r=0; r<R-3; r++){
			if(M<=1) break;
			board[r][C-2] = '*';
			board[r][C-1] = '*';
			M-=2;
		}

		if(R>2){
			if(C>2 && M==2 || C==2 && M==1){
				cout << "Impossible" << endl;
				continue;
			}
			for(int c=C-3; c<C; c++){
				if(c<0) continue;
				if(M<=0) break;
				board[R-3][c] = '*';
				M--;
			}
		}

		if( M==0 || M==5 || (C==2 && M==3) || (C>2 && M==2) ) {
			for(int c=C-3; c<C; c++){
				if(c<0) continue;
				for(int r=R-2; r<R; r++){
					if(M<=0) break;
					board[r][c] = '*';
					M--;
				}
			}

			int count = 0;
			for(int r=0; r<R; r++){
				for(int c=0; c<C; c++){
					cout << board[r][c];
					if(board[r][c] == '*') count++;
				}
				cout << endl;
			}

			if(count != total_m){
				cout << "ERROR" << endl;
				cout << "total_m=" << total_m << endl;
				cout << "on_field="<< count << endl;
				cout << "M="<< M << endl;
			}

		} else { //impossible
			cout << "Impossible" << endl;
		}
	}
	return 0;
}
