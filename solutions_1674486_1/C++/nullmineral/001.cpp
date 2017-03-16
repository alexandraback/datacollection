#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int int64;

int n;
static int m[1000];
static int f[1000][10];

static int memo[1000][1000];

int dfs(int from, int to)
{
	if(from == to)
		return 1;
		
	if(memo[from][to] != -1)
		return memo[from][to];
		
	int ret = 0;
	
	for(int i = 0; i < m[to]; ++i)
		ret += dfs(from, f[to][i]);
	
	//printf("[%d -> %d]%d\n", from, to, ret);
	
	return memo[from][to] = ret;
}

int main()
{
	int t;
	
	scanf("%d", &t);
	
	for(int time = 1; time <= t; ++time) {
		
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &m[i]);
			for(int j = 0; j < m[i]; ++j) {
				scanf("%d", &f[i][j]);
				f[i][j] -= 1;
			}
		}
		
		memset(memo, -1, sizeof(memo));
		
		bool ans = false;
		
		for(int i = 0; i < n && !ans; ++i) {
			for(int j = 0; j < n && !ans; ++j) {
				
				if(1 < dfs(i, j))
					ans = true;
			}
		}

		printf("Case #%d: %s\n", time, ans ? "Yes" : "No");
	}
	
	return 0;
}