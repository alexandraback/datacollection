// Compiler: g++-4.8 (Ubuntu/Linaro 4.8.1-10ubuntu9) 4.8.1
// Flags: -O2 -Wall -g -std=c++0x
// Aina häviää

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int R, C, M, O;
bool G[50][50];

int main() {
	cin.sync_with_stdio(false);
	
	int T;
	cin >> T;
	
	for(int t = 0; t < T; ++t) {
		cin >> R >> C >> M;
		O = R * C - M;
		
		bool ok = false;
		if(R == 1) {
			for(int i = 0; i < C; ++i) {
				G[0][i] = i < O;
			}
			ok = true;
		} else if(C == 1) {
			for(int i = 0; i < R; ++i) {
				G[i][0] = i < O;
			}
			ok = true;
		} else if(O == 1) {
			for(int i = 0; i < R; ++i) {
				for(int j = 0; j < C; ++j) {
					G[i][j] = i == 0 && j == 0;
				}
			}
			ok = true;
		} else {
			for(int s = 2; s <= C && 2 * s <= O; ++s) {
				if(s * R < O) continue;
				int fulls = O / s;
				int left = O % s;
				
				if(left == 1) {
					if(s > 2 && fulls > 2) {
						memset(G, 0, 50 * 50);
						for(int i = 0; i < fulls - 1; ++i) {
							for(int j = 0; j < s; ++j) G[i][j] = true;
						}
						for(int j = 0; j < s - 1; ++j) G[fulls - 1][j] = true;
						G[fulls][0] = true;
						G[fulls][1] = true;
						ok = true;
						break;
					}
				} else {
					memset(G, 0, 50 * 50);
					for(int i = 0; i < fulls; ++i) {
						for(int j = 0; j < s; ++j) G[i][j] = true;
					}
					for(int j = 0; j < left; ++j) G[fulls][j] = true;
					ok = true;
					break;
				}
			}
		}
		
		cout << "Case #" << t + 1 << ":\n";
		if(ok) {
			for(int i = 0; i < R; ++i) {
				for(int j = 0; j < C; ++j) {
					if(i == 0 && j == 0) {
						cout << "c";
					} else if(G[i][j]) {
						cout << ".";
					} else {
						cout << "*";
					}
				}
				cout << "\n";
			}
		} else {
			cout << "Impossible\n";
		}
	}
	
	return 0;
}
