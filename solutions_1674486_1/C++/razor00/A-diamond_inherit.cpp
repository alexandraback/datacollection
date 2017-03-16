#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <bitset>
#include <string>
#include <algorithm>

#define tr(c, i) for(typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
#define all(c) (c).begin(),(c).end()
#define sz(c) int((c).size())
#define INF 1000000000
#define EPS 1e-9
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

int T, n, m;
int dp[1005], ed;
vector <int> g[1005];

int f(int u) {
	if(u == ed) return 1;
	
	int &ret = dp[u];
	if(ret != -1) return ret;
	
	ret = 0;
	for(int j = 0; j < sz(g[u]); ++j)
		ret = min(ret + f(g[u][j]), 2);
	
	return ret;
}

int main() {
	scanf("%d", &T);
	
	for(int tc = 0; tc < T; ++tc) {
		scanf("%d", &n);
		
		for(int i = 1; i <= n; ++i) g[i].clear();
		
		for(int i = 1; i <= n; ++i) {
			int m, v;
			scanf("%d", &m);
			
			for(int j = 0; j < m; ++j) {
				scanf("%d", &v);
				g[i].PB(v);	
			}
		}	
		
		bool ans = 0;
		for(int j = 1; !ans && j <= n; ++j) {	// brute force semua titik akhir
			memset(dp, -1, sizeof(dp));
			ed = j;
			
			for(int i = 1; i <= n; ++i)	// titik awal
				if(f(i) >= 2) {
					ans = 1;
					break;	
				}
		}
				
		printf("Case #%d: %s\n", tc + 1, ans ? "Yes" : "No");
	}
	
	return 0;
}
