#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef unsigned long long llong;
llong dp[50][2][2][2];
bool vis[50][2][2][2];
llong A,B,K;
llong dfs(int i, int a, int b, int k);

llong solve(int i,int a,int b,int nxtk,int ad) {
	int cura = (A>>(i-1))&1;
	int curb = (B>>(i-1))&1;
	int nxta,nxtb;
	llong res=0;
	if (ad) {// a&b = 1
		if (a && b) {
			if (nxtk==1) res += ((1ll<<(i-1))) * ((1ll<<(i-1)));
			else res += dfs(i-1, a, b, nxtk);
		} else if (a && curb) {
			res += dfs(i-1, a, 0, nxtk);
		} else if (cura && b) {
			res += dfs(i-1, 0, b, nxtk);
		} else if (cura && curb) {
			res += dfs(i-1, 0, 0, nxtk);
		}
	} else {
		// a=0, b=1
		if (b || curb) {
			nxtb = b?1:0;
			if (a || cura) nxta=1;
			else nxta=0;
			res += dfs(i-1, nxta, nxtb, nxtk);
		}
		// a=1, b=0
		if (a || cura) {
			nxta = a?1:0;
			if (b || curb) nxtb=1;
			else nxtb=0;
			res += dfs(i-1, nxta, nxtb, nxtk);
		}
		// a=0, b=0
		if (a || cura) nxta=1;
		else nxta=0;
		if (b || curb) nxtb=1;
		else nxtb=0;
		res += dfs(i-1, nxta, nxtb, nxtk);
	}
	return res;
}

llong dfs(int i, int a, int b, int k) {
	int curk = (K>>(i-1))&1;
	if (vis[i][a][b][k]) {
		return dp[i][a][b][k];
	}
	if (i==0) {
		vis[i][a][b][k]=1;
		return dp[i][a][b][k]=1;
	}
	llong res = 0;
	if (k==0) {// not free
		if (curk==1) {
			res += solve(i,a,b,0,1);
			res += solve(i,a,b,1,0);
		} else {
			res += solve(i,a,b,0,0);
		}
	}
	else {// free
		res += solve(i,a,b,1,0);
		res += solve(i,a,b,1,1);
	}
	vis[i][a][b][k] = true;
	return dp[i][a][b][k] = res;
}

void work() {
	cin>>A>>B>>K;
	A--, B--, K--;
	memset(vis,0,sizeof(vis));
	memset(dp,0,sizeof(dp));
	llong ans = dfs(40,0,0,0);
	cout<<ans<<endl;
}

int main() {
	int cas;
	freopen("test.txt","r",stdin);
	freopen("ans2.txt","w",stdout);
	scanf("%d",&cas);
	for (int i=1; i<=cas; i++ ) {
		printf("Case #%d: ",i);
		work();
	}
	return 0;
}
