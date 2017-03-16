//============================================================================
// Name        : C.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;

int main() {
	freopen("output.txt", "w", stdout);
	int R,C,M;
	int t, tc = 0;
	cin>>t;
	while (tc++ < t) {
		cin>>R>>C>>M;
		int AR = R;
		int AC = C;
		bool possible = true;
		char matrix[R][C];
		int i, j;
		for (i = 0; i < R; i++)
			for (j = 0; j < C; j++)
				matrix[i][j] = '.';
		
		
		
		int r, c;
		r = c = 0;
		while (M > 0) {
			bool cutRow = AR > AC;
			int minN = min(AR,AC);
			if (M >= minN) {
				if (cutRow) {
					for (i = c; i < C; i++)
						matrix[r][i] = '*';
					r++;
					M -= minN;
					AR--;
				} else {
					for (i = r; i < R; i++)
						matrix[i][c] = '*';
					c++;
					M -= minN;
					AC--;
				}
			} else {
				int counter = 0;
				j = 1;
				matrix[r][c] = '*';
				M--;
				if (AR <= 2 || AC <= 2) {
					possible = false;
					break;
				}
				while (M > 0) {
					if (AR == 3 && AC == 3) {
						possible = false;
						M = 0;
						break;
					}
					
					if (cutRow) {
						matrix[r + j][c] = '*';
						cutRow = false;
					} else {
						matrix[r][c + j] = '*';
						cutRow = true;
					}
					counter++;
					M--;
					if (counter == 2) {
						j++;
						counter = 0;
					}
						
				}
				
			}

		}
		if (AR == 1) {
			if (R > 1 && AC > 1) possible = false;
		} else if (AC == 1) {
			if (C > 1 && AR > 1) possible = false;
		}
		
		printf("Case #%d:\n", tc);
		
		if (possible) {
			matrix[R - 1][C - 1] = 'c';
			for (i = 0; i < R; i++) {
				for (j = 0; j < C; j++)
					cout<<matrix[i][j];
				cout<<endl;
			}
		} else {
			cout<<"Impossible"<<endl;
		}
	}
	return 0;
}
