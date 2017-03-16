#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std;

int main(){
	int tcase;
	cin >> tcase;
	
	for(size_t casen = 0; casen < tcase; ++casen)
	{
		int N, M;
		cin >> N >> M;
		int mat[N][M];
		int sol[N][M];		
		bool flag = false;
		for(size_t i = 0; i < N; ++i) {
			for(size_t j = 0; j < M; ++j) {
				cin >> mat[i][j];
				if (mat[i][j] > 100 || mat[i][j] < 1) flag = true;
			}
		}
		
		for(size_t i = 0; i < N; ++i) {
			int row = 0;
			for(size_t j = 0; j < M; ++j) {
				row = max(mat[i][j], row);
			}
			for(size_t j = 0; j < M; ++j) {
				sol[i][j] = row;
			}
		}
		
		for(size_t i = 0; i < M; ++i) {
			int col = 0;
			for(size_t j = 0; j < N; ++j) {
				col = max(mat[j][i], col);
			}
			for(size_t j = 0; j < N; ++j) {
				sol[j][i] = min(col, sol[j][i]);
			}
		}
		
		for(size_t i = 0; i < N; ++i) {
			for(size_t j = 0; j < M; ++j) {
				if (sol[i][j] != mat[i][j]) flag = true;
			}
		}
		
		cout << "Case #" << casen + 1 << ": ";
		if (!flag) cout << "YES" << endl;
		else cout << "NO" << endl;
		
	}
	

	return 0;
}
