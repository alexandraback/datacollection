#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define FORD(x,y,z) for(int x=y;x>=z;x--)
#define MSET(x,y) memset(x,y,sizeof(x))
#define FOR(x,y) for(__typeof(y.begin()) x=y.begin();x!=y.end();x++)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define M 1005
void RI(){}
template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
using namespace std;
typedef long long LL;
int t,n,ans,in[M],vis[M],dep[M];
int s[M],top;
vector<int> e[M];

void dfs(int cur,int d,int ban)
{
	dep[cur] = d;
	FOR(i,e[cur]) if(*i!=ban && dep[*i]==0)
		dfs(*i, d+1, ban);
}
int check(int x,int y)
{
	int re=0;

	MSET(dep,0);
	dfs(x, 1, y);
	re += *max_element(dep+1, dep+n+1);

	MSET(dep, 0);
	dfs(y, 1, x);
	re += *max_element(dep+1, dep+n+1);

//	printf("check %d %d = %d\n",x,y,re);;
	return re;
}
int main()
{
	int x;
	RI(t);
	REP(tt,1,t)
	{
		RI(n);
		REP(i,0,n) e[i].clear();
		REP(i,1,n)
		{
			RI(in[i]);
			e[in[i]].PB(i);
		}

		//FIND MAX CYCLE
		ans = 0;
		REP(i,1,n)
		{
			MSET(vis, 0);
			x = i;
			top = 0;
			while(!vis[x])
			{
				vis[x] = 1;
				s[top++] = x;
				x = in[x];
			}

			int cnt=0;
			while(top)
			{
				cnt++;
				vis[s[top-1]] = 2;
				if(s[top-1] == x) break;

				top--;
			}
			ans = max(ans, cnt);
		}

		//CHECK C2
		int tmp = 0;
		REP(i,1,n) if(in[i]>i && in[in[i]]==i)
		{
			tmp += check(i,in[i]);
		}
		ans = max(tmp, ans);

		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}

