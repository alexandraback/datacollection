#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int int64;

int n, m;
int64 countA[100], countB[100];
int kindA[100], kindB[100];

int64 memo[100][100];

int64 dfs(int a, int b)
{
	int64 ret = 0;
	
	if(a >= n || b >= m)
		return 0;
		
	if(memo[a][b] != -1)
		return memo[a][b];
	
	if(kindA[a] != kindB[b]) {
		
		int64 t1 = dfs(a + 1, b);
		int64 t2 = dfs(a, b + 1);
		
		ret = max(t1, t2);
		
	} else {
	
		int64 useA = 0;
		int64 useB = 0;
		
		int k = kindA[a];
	
		for(int i = a; i < n; ++i) {
			
			if(kindA[i] == k) {
				
				useA += countA[i];
				useB = 0;
			
				for(int j = b; j < m; ++j) {
					
					if(kindB[j] == k) {
					
						useB += countB[j];
						
						int64 t1 = dfs(i + 1, j + 1) + min(useA, useB);
						ret = max(ret, t1);
					}
				}
			}
		}
	}
	
	return memo[a][b] = ret;
}


int main()
{
	int t;
	
	scanf("%d", &t);
	
	for(int time = 1; time <= t; ++time) {
		
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i)
			scanf("%I64d%d", &countA[i], &kindA[i]);
		for(int i = 0; i < m; ++i)
			scanf("%I64d%d", &countB[i], &kindB[i]);
			
		memset(memo, -1, sizeof(memo));
			
		int64 ans = dfs(0, 0);
		
		printf("Case #%d: %I64d\n", time, ans);
	}
	
	return 0;
}