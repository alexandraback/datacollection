#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <limits>
using namespace std;
vector<int> b;
int tc, tcn, a[101],dp[101];

void solve(){
	scanf("%d", &tc);
	while (tc--){
		int c, d, v;
		scanf("%d %d %d", &c, &d, &v);
		for (int i = 0; i < d; i++){
			scanf("%d", &a[i]);

		}
		int re = v;
		
		for (int i = 1; i <= (1<<16); i++){
			b.clear();
		
			for (int j = 0; j < d; j++){
				b.push_back(a[j]);				
			}

			for (int j = 1,k=1; j <= i; j<<=1,k++){
				if (j & i)
					b.push_back(k);
			}
			sort(b.begin(), b.end());
			b.erase(unique(b.begin(), b.end()), b.end());

			memset(dp, 0, sizeof(dp));
			dp[0] = 1;
			for (int j = 0; j < b.size(); j++){
				for (int k = v; k >= b[j]; k--){
					dp[k] |= dp[k - b[j]];
				}
			}

			int pos = 1;
			for (int j = 1; j <= v; j++){
				if (!dp[j])
					pos = 0;
			}
			if (!pos)
				continue;
			re = min(re, (int)b.size()-d);

		}

		printf("Case #%d: %d\n", ++tcn, re);
	}
}

int main(void){
	//freopen("C-small-attempt3.in", "r", stdin);
	
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}