#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int gp[105][105],c[105],r[105],n,m;
bool check() {
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			if(gp[i][j] < c[i] && gp[i][j] < r[j])
				return false;
		}
	return true;
}
int main () {
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int cas = 1; cas <= T; cas++) {
		scanf("%d%d",&n,&m);
		for(int i = 0; i< n; i++) {
			for(int j = 0; j < m; j++)
				scanf("%d",&gp[i][j]);
		}
		for(int i = 0; i < n; i++) {
			c[i] = gp[i][0];
			for(int j = 0; j < m; j++) {
				c[i] = max(c[i],gp[i][j]);
			}
		}
		for(int i = 0; i < m; i++) {
			r[i] = gp[0][i];
			for(int j = 0; j < n; j++) {
				r[i] = max(r[i],gp[j][i]);
			}
		}
		printf("Case #%d: ",cas);
		if(check()) 
			puts("YES");
		else puts("NO");
	}
	return 0;
}