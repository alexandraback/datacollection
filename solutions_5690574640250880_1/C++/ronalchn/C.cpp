#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int T, X;
	char grid[50][51];
  cin >> T;
  for (int t=1;t<=T;t++) {
		int R, C, M;
		cin >> R >> C >> M;
		for (int i=0;i<R;i++) {
			for (int j=0;j<C;j++) grid[i][j]='*';
			grid[i][C]=0;
		}

		// Lots of edge cases when there are few free spaces
		int N = R*C;
		int free = N-M;
		bool possible = true;
		printf("Case #%d:\n", t);
		if (free == 1) {
			grid[0][0]='c';
		}
		else if (R==1) {
			for (int i=0;i<free;i++) grid[0][i]='.';
			grid[0][0]='c';
		}
		else if (C==1) {
			for (int i=0;i<free;i++) grid[i][0]='.';
			grid[0][0]='c';
		}
		else if (free < 4 || free == 5 || free == 7) possible = false;
		else if (R == 2 || C == 2) {
			if (free%2==1) possible = false;
			else {
				for (int i=0;i<free/2;i++) {
					if (R==2) grid[0][i]=grid[1][i]='.';
					else grid[i][0]=grid[i][1]='.';
				}
				grid[0][0]='c';
			}
		}
		else if (free < R*2+2) {
			if (free%2==1) {
				grid[0][2]='.';
				grid[1][2]='.';
				grid[2][2]='.';
				free-=3;
			}
			if (free%2==0) for (int i=0;i<free/2;i++) {
				grid[i][0]=grid[i][1]='.';
			}
			grid[0][0]='c';
		}
		else {
			int col = 0;
			while (free >= R) {
				for (int i=0;i<R;i++) grid[i][col] = '.';
				free-=R;
				col++;
			}
			if (free == 1) {
				grid[0][col] = grid[1][col] = '.';
				grid[R-1][col-1] = '*';
			}
			else {
				for (int i=0;i<free;i++) grid[i][col] = '.';
			}
			grid[0][0]='c';
		}

		if (possible) {
			for (int i=0;i<R;i++) cout << grid[i] << endl;
			int count = 0;
			for (int i=0;i<R;i++) {
				for (int j=0;j<C;j++) if (grid[i][j]=='*') count++;
			}
			if (count != M) {
				cout << "FAIL" << endl;
				return 1;
			}
		}
		else cout << "Impossible" << endl;
	}

  return 0;
}
