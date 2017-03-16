#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;
ll dp[31][8];

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int caseNum = 1; caseNum <= T; ++caseNum){
		int a, b, k;
		cin >> a >> b >> k;
		--a; --b; --k;
		memset(dp, 0, sizeof(dp));
		dp[30][7] = 1;
		for(int i = 29; i >= 0; --i){
			for(int j = 0; j < 8; ++j){
				for(int bits = 0; bits < 4; ++bits){
					const int x = bits & 1;
					const int y = (bits >> 1) & 1;
					const int z = x & y;
					if((j & 1) && x && !(a & (1 << i))){ continue; }
					if((j & 2) && y && !(b & (1 << i))){ continue; }
					if((j & 4) && z && !(k & (1 << i))){ continue; }
					int t = j;
					if((a & (1 << i)) && !x){ t &= ~1; }
					if((b & (1 << i)) && !y){ t &= ~2; }
					if((k & (1 << i)) && !z){ t &= ~4; }
					dp[i][t] += dp[i + 1][j];
				}
			}
		}
		ll answer = 0;
		for(int i = 0; i < 8; ++i){ answer += dp[0][i]; }
		cout << "Case #" << caseNum << ": " << answer << endl;
	}
	return 0;
}

