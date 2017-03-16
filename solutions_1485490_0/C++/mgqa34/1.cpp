#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
long long dp[110][110],sum1[110][110],sum2[110][110];
struct edge
{
	int v,next;
}e[10010];
int cnt,head[110];
void addedge(int u,int v)
{
	e[cnt].v = v;
	e[cnt].next = head[u];
	head[u] = cnt ++;
}
struct point
{
	int v;
	long long x;
}a[110],b[110],tmp[110];
int main()
{
freopen("C-small-attempt2.in","r",stdin);
freopen("C-small-attempt2.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int tcase = 1; tcase <= t; tcase ++) {
		memset(dp,0,sizeof(dp));
		memset(sum1,0,sizeof(sum1));
		memset(head,-1,sizeof(head));
		memset(sum2,0,sizeof(sum2));
		cnt = 0;
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i = 1; i <= n; i ++)
			cin >> tmp[i].x >> tmp[i].v;
		int c1 = 0;
		for(int i = 1; i <= n; i ++)
			if(i == 1) a[++c1] = tmp[1];
			else if(tmp[i].v == tmp[i-1].v) a[c1].x += tmp[i].x;
			else a[++c1] = tmp[i];
		n = c1;
		c1 = 0;
		for(int i = 1; i <= m; i ++)
			cin >> tmp[i].x >> tmp[i].v;
		for(int i = 1; i <= m; i ++)
			if(i == 1) b[++c1] = tmp[1];
			else if(tmp[i].v == tmp[i-1].v) b[c1].x += tmp[i].x;
			else b[++c1] = tmp[i];
		m = c1;
		for(int i = 1; i <= n; i ++) 
			for(int j = m; j >= 1; j --)
				if(a[i].v == b[j].v) addedge(i,j);
		for(int i = 1; i <= n; i ++) 
			sum1[a[i].v][i] = a[i].x;
		for(int i = 1; i <= m; i ++)
			sum2[b[i].v][i] = b[i].x;
		for(int i = 1; i <= 100; i ++) {
			for(int j = 1; j <= 100; j ++) {
				sum1[i][j] += sum1[i][j-1];
				sum2[i][j] += sum2[i][j-1];
			}
		}
		long long ans = 0;
		for(int i = 1; i <= n; i ++)
			for(int j = head[i]; j != -1; j = e[j].next) {
				for(int k = i - 1; k >= 0; k --)
					for(int p = e[j].v - 1; p >= 0; p --)
						dp[i][e[j].v] = max(dp[i][e[j].v],dp[k][p] + min(sum1[a[i].v][i] - sum1[a[i].v][k],sum2[a[i].v][e[j].v] - sum2[a[i].v][p]));
				ans = max(ans,dp[i][e[j].v]);
			}
		printf("Case #%d: ",tcase);
		cout<<ans<<endl;
	}
	return 0;
}


		


