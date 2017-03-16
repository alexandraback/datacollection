#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;

int main(){
	int tcase;
	vector<string> ans;			
	int R, C, M, OM, lR = -1, lC = -1;
	bool poss;
	cin >> tcase;	
	
	for(int casen = 0; casen < tcase; ++casen)
	{
		cout << "Case #" << casen + 1 << ":" << endl;
		lR = lC = -1;
		cin >> R >> C >> M;
		OM = M;
		poss = true;
		ans.resize(R,"");
		for(int i = 0; i < R; ++i) {
			ans[i] = string(C, '.');
			assert(ans[i].size() == C);
		}
		if (OM == R*C - 1) {
			for (int i = 0 ; i < R ; i++) {
				for (int j = 0 ; j < C ; j++){
					if (i == R-1 && j == C-1) cout << 'c'; 
					else cout << '*';
				}
				cout << endl;
			}
			continue;
		}
		
		ans[R-1][C-1] = 'c';
		for(int i = 0; i < R - 2 && M; ++i) {	
			for(int j = 0; j < C - 2 && M; ++j) {
				if (i == R-3 && j == C-3) continue;
				assert(ans[i][j] == '.');
				lR = i;	
				lC = j;
				ans[i][j] = '*';
				M--;
			}
		}
		
		
		for (int i = 0; i < R - 3 && M; ++i) {
			for (int j = max(0,C - 2); j < C && M; ++j) {
				assert(ans[i][j] == '.');
				lR = i;	
				lC = j;
				ans[i][j] = '*';
				M--;				
			}
		}
		
		for (int j = 0; j < C - 3 && M; ++j) {
			for (int i = max(R - 2, 0); i < R && M; ++i) {
				assert(ans[i][j] == '.');
				lR = i;	
				lC = j;
				ans[i][j] = '*';
				M--;								
			}
		}

		if (M == 0) {
			cerr << "Easy Case" << endl;
			if ((lC != -1 && lC == C-2) || (lR != -1 && lR == R-2)) {
				if (C == 2 || R == 2) poss = false;
				else if (C != 1 && R != 1){
					assert(R >= 3 && C >= 3);
					ans[lR][lC] = '.';
					if (lR == R-2) {
						for (int i = 0 ; i < C ; i++) {
							if (ans[lR-1][i] == '.'){
								ans[lR-1][i] = '*';
								break;
							}
						}
					}
					else if (lC == C-2) {
						for (int i = 0 ; i < R ; i++) {
							if (ans[i][lC-1] == '.'){
								ans[i][lC-1] = '*';
								break;
							}
						}
					}
				}
			}
		} else {
			cerr << "Smaller Problem" << endl;
			// min(3, R) x min(3, C) with M problem
			if (min(R,C) == 1) {
				if (R == 1) for (int i = lC+1 ; i < C && M ; ++i) {ans[0][i] = '*'; M--;}
				else for (int i = lR+1 ; i < R && M ; ++i) {ans[i][0] = '*'; M--;}
			} else if (min(R,C) == 2) {
				if (M % 2 || OM > R * C - 4) poss = false;
				else {
					if (R == 2)	for (int i = lC+1 ; i < C && M ; ++i) {ans[0][i] = ans[1][i] = '*'; M-=2;}
					else for (int i = lR+1 ; i < R && M ; ++i) {ans[i][0] = ans[i][1] = '*'; M-=2;}					
				}
			} else {
				assert(R >= 3 && C >= 3);				
				if (M == 1 || M == 3 || M == 5) {
					for(int i = 3 ; i > 0 && M; --i) {
						ans[R-3][C-i] = '*';
						M--;
					}
					if (M) {ans[R-2][C-3] = ans[R-1][C-3] = '*'; M-=2; }
				} else poss = false;
			}
		}
		
		if (poss){
			assert (M == 0);
			// for(int i = 0; i < R; ++i) for(int j = 0; j < C; ++j) if(ans[i][j]=='*')M++;
			for(int i = 0; i < R; ++i) {
				// std::cout << ans[i].size() << endl;
				assert(ans[i].size() == C);
				cout << ans[i] << endl;
			}			
			// assert (M == OM);			
		}
		else
			cout << "Impossible" << endl;
	}
	

	return 0;
}
