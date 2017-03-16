# include <bits/stdc++.h>
using namespace std;

int main()
{
	int T; cin >> T;
	for(int T_=1; T_<=T; ++T_) {
		int b, m; cin >> b >> m;
		
		int64_t mx = (1LL << (b - 2));
		if (mx < m) {
			printf("Case #%d: IMPOSSIBLE\n", T_);
			continue;
		}
		
		vector<vector<bool>> mp(b, vector<bool>(b, false));
		for(int i=0; i<b; ++i) {
			for(int k=i+1; k<b; ++k) {
				mp[i][k] = true;
			}
		}
		
		for(int i=2; i<b; ++i) {
			int64_t pt = (1 << (b - 1 - i));
			if (m + pt <= mx) {
				mp[0][i-1] = false;
				mx -= pt;
			}
		}
		
		printf("Case #%d: POSSIBLE\n", T_);
		for(int i=0; i<b; ++i) {
			for(int k=0; k<b; ++k) {
				printf("%d", (int)mp[i][k]);
			}
			printf("\n");
		}
	}
	return 0;
}