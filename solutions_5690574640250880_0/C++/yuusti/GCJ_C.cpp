#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

char ans[55][55];

int main(){
	int T;
	cin >> T;
	for (int Case = 1; Case <= T; ++Case){
		printf("Case #%d:\n", Case);
		int R, C, M;
		cin >> R >> C >> M;
		bool ok = false;
		if (M == 0 || R == 1 || C == 1 || (R*C - 1 == M)){
			ok = true;
			for (int r = 0; r < R; ++r){
				for (int c = 0; c < C; ++c){
					if (r*C + c < M) ans[r][c] = '*';
					else ans[r][c] = '.';
				}
			}
			ans[R - 1][C - 1] = 'c';
		}
		else{
			int space = R*C - M;
			vector<int> num(R);
			for (int x = C; x >= 2; --x){	// first two spaces
				num[0] = num[1] = x;
				int rest = space - x * 2;
				if (rest < 0) continue;
				for (int r = 2; r < R; ++r){
					if (rest < 2){
						num[r] = 0;
					}
					else{
						rest -= 2;
						num[r] = 2;
					}
				}
				for (int r = 2; r < R; ++r){
					while (rest > 0 && num[r] >= 2 && num[r] < x){
						++num[r];
						--rest;
					}
				}
				if (rest == 0){
					ok = true;
					break;
				}
			}
			
			for (int r = 0; r < R; ++r){
				for (int c = 0; c < C; ++c){
					if (c < num[r]) ans[r][c] = '.';
					else ans[r][c] = '*';
				}
			}
			ans[0][0] = 'c';
		}

		if (!ok) cout << "Impossible" << endl;
		else{
			for (int r = 0; r < R; ++r){
				for (int c = 0; c < C; ++c){
					cout << ans[r][c];
				}
				cout << endl;
			}
		}
	}

	return 0;
}