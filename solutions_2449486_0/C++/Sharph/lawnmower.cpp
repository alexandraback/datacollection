#include <iostream>
#include <climits>

int main() {
	int T;
	std::cin >> T;
	for(int t = 0; t < T; ++t) {
		int N, M;
		std::cin >> N >> M;
		
		int a[100][100];
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < M; ++j) {
				std::cin >> a[i][j];
			}
		}
		
		int rowmax[100];
		int colmax[100];
		for(int i = 0; i < N; ++i) {
			rowmax[i] = INT_MIN;
			for(int j = 0; j < M; ++j) {
				rowmax[i] = std::max(rowmax[i], a[i][j]);
			}
		}
		for(int j = 0; j < M; ++j) {
			colmax[j] = INT_MIN;
			for(int i = 0; i < N; ++i) {
				colmax[j] = std::max(colmax[j], a[i][j]);
			}
		}
		
		bool possible = true;
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < M; ++j) {
				if(a[i][j] != rowmax[i] && a[i][j] != colmax[j]) {
					possible = false;
				}
			}
		}
		std::cout << "Case #" << t + 1 << ": ";
		if(possible) {
			std::cout << "YES";
		} else {
			std::cout << "NO";
		}
		std::cout << "\n";
	}
	
	return 0;
}