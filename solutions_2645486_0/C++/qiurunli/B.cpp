/*************************************************************************
    > File Name: B.cpp
    > Author: hnu0314
    > Mail: hnu0314@126.com 
    > Created Time: 2013/4/27 10:36:19
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int MAXN = 20; 
const int INF = 0;

int dp[2][MAXN];

int n, R, E, v[MAXN];

int main(){

	int test, cas(1);
	freopen("B-small.in", "r", stdin);
	freopen("B-small.out", "w", stdout);
	scanf("%d", &test);
	while(test--){
		scanf("%d%d%d", &E, &R, &n);
		for(int i = 0; i < n; ++i)  scanf("%d", v + i);
		
		memset(dp, -1, sizeof(dp));
		dp[1][E] = 0;
		int now(0);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j <= E; ++j)  dp[now][j] = -1;
			for(int j = 0; j <= E; ++j){
				if(dp[!now][j] == -1)  continue;
				for(int k = 0; k <= j; ++k){
					int nk = min(E, j - k + R);
					dp[now][nk] = max(dp[now][nk], dp[!now][j] + k * v[i]); 
				}
			}
			now = !now;
		}
		int res(0);
		for(int i = 0; i <= E; ++i)  res = max(res, dp[!now][i]);
		printf("Case #%d: %d\n", cas++, res);
	}
    
		return 0;
}
