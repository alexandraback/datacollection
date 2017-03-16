#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
#define rep(i,s,t) for(int i=int(s); i<int(t); i++)
#define mst(A,k) memset(A,k,sizeof(A))

int n;
int F[1005], vis[1005], d[1005], t[1005];
int scc;
int ro[1005], v[1005][2], l[1005][2], o, mp[1005], supfa[1005];
int cnt;
int ans;

int dfs(int s)
{
	vis[s] = -1;
	t[s] = ++scc;
	int ret;
	if(vis[F[s]] == 0) 
	{
		int limt = dfs(F[s]);
		d[s] = d[F[s]] + 1;
		if(t[s] >= limt) d[s] = 0;
		else
		{
			if(d[s] == 1) supfa[s] = F[s];
			else supfa[s] = supfa[F[s]];
		}
		ret = min(limt, t[s]);
		mp[s] = mp[F[s]];
	}
	else if(vis[F[s]] == -1)
	{
		d[s] = 0;
		ret = t[F[s]];
		mp[s] = ++o;
		//cout<<F[s]<<" "<<s<<"\n";
		//cout<<t[s]<<" "<<t[F[s]]<<"\n";
		ro[o] = t[s] - t[F[s]] + 1;
		l[o][0] = l[o][1] = 0;
		if(ro[o] == 2)
		{
			v[o][0] = F[s];
			v[o][1] = s;
			cnt++;
		}
	}
	else
	{
		d[s] = d[F[s]] + 1;
		if(d[s] == 1) supfa[s] = F[s];
		else supfa[s] = supfa[F[s]];
		ret = t[s];
		mp[s] = mp[F[s]];
	}
	vis[s] = 1;
	int k = mp[s];
	if(ro[k] == 2)
	{
		if(supfa[s] == v[k][0]) l[k][0] = max(l[k][0], d[s]);
		else l[k][1] = max(l[k][1], d[s]);
	}
	else l[k][0] = max(l[k][0], d[s]);
	return ret;
}
int main() {
	freopen("C-small-attempt3.in","r",stdin); 
	freopen("ans.txt","w",stdout); 

	int T;
	scanf("%d", &T);
	rep(cas, 0, T)
	{
		scanf("%d", &n);
		rep(i, 1, n + 1) scanf("%d", F + i);
		//printf("%d\n", n);
		//rep(i, 1, n + 1) printf("%d ", F[i]);
		//printf("\n");
		mst(vis, 0);
		scc = 0;
		o = 0;
		cnt = 0;
		rep(i, 1, n + 1)
		{
			if(!vis[i]) dfs(i);
		}
		ans = 0;
		int res = 0;
		rep(i, 1, o + 1)
		{
			ans = max(ans, ro[i]);
			if(ro[i] == 2)
			{
				res += 2 + l[i][0] + l[i][1];
			}
			//ans = max(l[i][0] + 1, ans);
		}
		ans = max(ans, res);
		printf("Case #%d: %d\n", cas + 1, ans);
	}
	return 0;
}

