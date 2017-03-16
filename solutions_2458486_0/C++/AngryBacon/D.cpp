#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MP make_pair
#define PB push_back
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin(); e!=x.end(); ++e)

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int MAX_N = 200 + 10;
const int MAX_S = 1024 * 1024;
int n, k;
int t[MAX_N];
int key[MAX_N];
int tot[MAX_N];
int kic[MAX_N][MAX_N];
int vis[MAX_S];
int path[MAX_N];
int choose[MAX_N];

int dfs(int cur, int state)
{
	if (cur == n) {
		for(int i = 0; i < n; ++ i) {
			printf("%d", path[i] + 1);
			if (i != n - 1)
				printf(" ");
			else
				printf("\n");
		}
		return true;
	}
	
	if (vis[state]) return false;
	vis[state] = true;
	
	for(int i = 0; i < n; ++ i)
		if (! choose[i] && key[t[i]]) {
			choose[i] = true;
			-- key[t[i]];
			
			for(int j = 0; j < tot[i]; ++ j)
				++ key[kic[i][j]];
			
			path[cur] = i;
			if (dfs(cur + 1, state + (1 << i)))
				return true;
			
			for(int j = 0; j < tot[i]; ++ j)
				-- key[kic[i][j]];
			
			++ key[t[i]];
			choose[i] = false;
		}
	
	return false;
}

void solve(int test)
{
	printf("Case #%d: ", test);
	scanf("%d%d", &k, &n);
	memset(key, 0, sizeof key);
	memset(vis, 0, sizeof vis);
	memset(choose, 0, sizeof choose);
	
	int u;
	for(int i = 0; i < k; ++ i) {
		scanf("%d", &u);
		++ key[u];
	}
	
	for(int i = 0; i < n; ++ i) {
		scanf("%d%d", &t[i], &tot[i]);
		for(int j = 0; j < tot[i]; ++ j)
			scanf("%d", &kic[i][j]);
	}
	
	if (! dfs(0, 0)) 
		puts("IMPOSSIBLE");
}

int main()
{
	//freopen("D.in", "r", stdin); freopen("D.out", "w", stdout);
	freopen("D-small-attempt0.in", "r", stdin); freopen("D-small-attempt0.out", "w", stdout);
	//freopen("D-large.in", "r", stdin); freopen("D-large.out", "w", stdout);
	int testcase; scanf("%d", &testcase);
	for(int i = 1; i <= testcase; ++ i) solve(i);
	fclose(stdout);
	return 0;
}
