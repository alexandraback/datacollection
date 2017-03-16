#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN = 2500;
const int MAXC = 50;

int R, C, M, N;

int possible[MAXN+1][MAXC+1][MAXC+1];
//[n left][r left][c left], -1 unexplored

inline void printCell(int times, char type, bool newline){
	for(int i=0; i<times; i++)
		printf("%c", type);
	if (newline)
		cout << endl;
}

bool getPossible(int n, int r, int c){
	if (n < 0 || r < 0 || c < 2)
		return false;
	if (n == 0)
		return true;
	if (possible[n][r][c] != -1)
		return (possible[n][r][c] > 0);
	return (possible[n][r][c] = (getPossible(n-c, r-1, c) || getPossible(n, r, c-1)));
}

int main(){
	int T;
	cin >> T;
	for(int t=0; t<T; t++){
		printf("Case #%d: \n", t+1);
		cin >> R >> C >> M;
		N = R*C-M;

		if (N == 1){
			cout << "c";
			printCell(C-1, '*', true);
			for(int i=0; i<R-1; i++)
				printCell(C, '*', true);
		} else if (C == 1){
			cout << "c" << endl;
			for(int i=0; i<N-1; i++)
				printCell(1, '.', true);
			for(int i=0; i<M; i++)
				printCell(1, '*', true);
		} else if (R == 1){
			cout << "c";
			printCell(N-1, '.', false);
			printCell(M, '*', true);
		} else {
			memset(possible, -1, sizeof(possible));
			bool isPossible = false;
			for(int c0=C; c0>=2; c0--)
				//watch for negative n
				if (getPossible(N-c0*2, R-2, c0)){
					isPossible = true;
					cout << 'c';
					printCell(c0-1, '.', false);
					printCell(C-c0, '*', true);
					printCell(c0, '.', false);
					printCell(C-c0, '*', true);
					int n = N-2*c0, r = R-2, c = c0;
					while (n > 0){
						//printf("test: %d, %d, %d, %d", n-c, r-1, c, getPossible(n-c, r-1, c));
						//cout << endl;
						if (getPossible(n-c, r-1, c)){
							printCell(c, '.', false);
							printCell(C-c, '*', true);
							n -= c;
							r -= 1;
						} else
							c--;
					}
					for(int i=0; i<r; i++)
						printCell(C, '*', true);
					break;
				}
			if (!isPossible)
				cout << "Impossible" << endl;
		}
	}
}

