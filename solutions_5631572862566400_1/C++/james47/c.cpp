/*************************************************************************
    > File Name: c.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sat Apr 16 10:33:22 2016
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 1100;
int n;
int f[maxn];
vector<int> g[maxn];
bool used[maxn];

int getmax(int x, int y){
	int ret = 1;
	for (int i = 0; i < g[x].size(); i++)
		if (g[x][i] != y)
			ret = max(ret, getmax(g[x][i], y) + 1);
	return ret;
}

int loop(int st, int cur){
	if (used[cur]){
		if (cur != st) return -1;
		return 0;
	}
	used[cur] = true;
	int ret = loop(st, f[cur]);
	if (ret != -1) return ret + 1;
	return -1;
}

int main()
{
	int T, cas = 0;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			g[i].clear();
		for (int i = 1; i <= n; i++){
			scanf("%d", &f[i]);
			g[f[i]].push_back(i);
		}
		int ans = 0, tot = 0;
		for (int i = 1; i <= n; i++){
			memset(used, false, sizeof(used));
			int len = loop(i, i);
			if (len != -1){
				ans = max(len, ans);
				if (len == 2)
					tot += getmax(i, f[i]);
			}
		}
		ans = max(ans, tot);
		printf("Case #%d: %d\n", ++cas, ans);
	}
	return 0;
}
