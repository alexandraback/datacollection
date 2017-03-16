#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int N = 111;
int a[N][N], n, m;

bool ok(int x, int y, int k){
	int cnt = 0;
	for(int i = 1; i <= m; i++)
		if(a[x][i] <= k)cnt++;
	if(cnt == m)return 1;
	cnt = 0;
	for(int i = 1; i <= n; i++)
		if(a[i][y] <= k)cnt++;
	if(cnt == n)return 1;
	return 0;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t;
	scanf("%d", &t);
	for(int tc = 1; tc <= t; tc++){
		printf("Case #%d: ", tc);
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				scanf("%d", &a[i][j]);
		int yes = 1;
		for(int i = 1; i <= n && yes; i++)
			for(int j = 1; j <= m && yes; j++)
				if(!ok(i, j, a[i][j]))yes = 0;
		if(!yes)puts("NO");else puts("YES");
	}
	
	return 0;
}
