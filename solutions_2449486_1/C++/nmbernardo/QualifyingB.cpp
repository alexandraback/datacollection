/*
 * QualifyingB.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: Neil
 */



#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>


using namespace std;

#define SIZE 121
#define REMOVED -1

#define INF (1 << 28)

int T;
int N;
int M;

int grid[SIZE][SIZE];

int row_count[SIZE];
int col_count[SIZE];

int main() {




	freopen("test.in","r",stdin);
	freopen("B.out","w",stdout);
	cin >> T;


	for(int t= 1; t <= T; t++) {
		cin >> N >> M;


		memset(grid,0,sizeof(grid));
		memset(row_count,0,sizeof(row_count));
		memset(col_count,0,sizeof(col_count));


		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++)
				cin >> grid[i][j];
		}


		for(int i = 0; i < N; i++) {
			row_count[i] = M;
		}

		for(int i = 0; i < M; i++) {
			col_count[i] = N;
		}




		cout << "Case #" << t << ": ";


		while(true) {



			int min_val = INF;
			int min_r = 0;
			int min_c = 0;

			for(int i =0 ; i < N; i++) {
				for(int j = 0; j < M; j++) {
					if(grid[i][j] < min_val && grid[i][j] != REMOVED) {
						min_val = grid[i][j];
						min_r = i;
						min_c = j;
					}
				}
			}


			if(min_val == INF) {
				cout << "YES" << endl;
				break;
			}



			int c_count=  0;

			for(int i = 0; i < N; i++) {
				if(grid[i][min_c] == min_val) {
					c_count++;
				}
			}

			int r_count = 0;

			for(int i = 0; i < M; i++) {
				if(grid[min_r][i] == min_val) {
					r_count++;
				}
			}



			if(r_count != row_count[min_r] && c_count != col_count[min_c]) {
				cout << "NO" << endl;
				break;
			}


			if(r_count == row_count[min_r]) {
				for(int i = 0; i < M; i++) {
					if(grid[min_r][i] != REMOVED) {
						col_count[i]--;
						grid[min_r][i] = REMOVED;
					}
				}

				row_count[min_r] = 0;
			}


			if(c_count == col_count[min_c]) {
				for(int i = 0; i < N; i++) {
					if(grid[i][min_c] != REMOVED) {
						row_count[i]--;
						grid[i][min_c] = REMOVED;
					}
				}

				col_count[min_c] = 0;
			}
		}

		//check_col





	}



	return 0;
}
