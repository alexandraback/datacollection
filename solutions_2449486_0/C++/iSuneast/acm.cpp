#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

#define LOWBIT(v) ((v)&(-(v)))
#define KTH_BIT(v, k) ((v) & (1<<(k)))
#define MERGE_BIT(v, k) ((v) | (1<<(k)))

#define MAXN 103
#define MOD 
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int g[MAXN][MAXN];
int key[2][MAXN];
int n, m;

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in", "r", stdin);
	freopen("C:\\Users\\suneast\\Downloads\\B-small-attempt0.in", "r", stdin);
	freopen("C:\\Users\\suneast\\Downloads\\B-small-attempt0.out", "w", stdout);
#endif
	
	int dataset;
	scanf("%d", &dataset);
	for(int cas=1; cas<=dataset; ++cas) {
		scanf("%d %d", &n, &m);
		memset(key, 0, sizeof(key));
		for(int i=0; i<n; ++i) {
			for(int j=0; j<m; ++j) {
				scanf("%d", &g[i][j]);
				key[0][i] = max(key[0][i], g[i][j]);
				key[1][j] = max(key[1][j], g[i][j]);
			}
		}
		bool ok = true;
		for(int i=0; i<n; ++i) {
			for(int j=0; j<m; ++j) {
				if(g[i][j] < key[0][i] && g[i][j] < key[1][j]) {
					ok = false;
				}
			}
		}
		printf("Case #%d: %s\n", cas, ok? "YES": "NO");
	}

	return 0;
}
