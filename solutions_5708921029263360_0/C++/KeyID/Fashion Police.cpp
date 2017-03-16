#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

typedef pair <int,int> pii;

struct state
{
	int a,b,c;
}p[1<<27];

int k,ans,anss,cnt;
map <pii,int> ms1,ms2,ms3;

void dfs(int cur,int sta,int now)
{
	if (now>ans)
	{
		ans=now;
		anss=sta;
	}
	if (cur>=cnt) return;
	if (ms1[mp(p[cur].a,p[cur].b)]<k&&ms2[mp(p[cur].b,p[cur].c)]<k&&ms3[mp(p[cur].a,p[cur].c)]<k)
	{
		ms1[mp(p[cur].a,p[cur].b)]++;
		ms2[mp(p[cur].b,p[cur].c)]++;
		ms3[mp(p[cur].a,p[cur].c)]++;
		dfs(cur+1,sta|(1<<cur),now+1);
		ms1[mp(p[cur].a,p[cur].b)]--;
		ms2[mp(p[cur].b,p[cur].c)]--;
		ms3[mp(p[cur].a,p[cur].c)]--;
	}
	if (now+cnt-cur-1>ans) dfs(cur+1,sta,now);
}

inline void solve()
{
	int a,b,c;
	scanf("%d%d%d%d",&a,&b,&c,&k);
	cnt=0;
	for (int i=1;i<=a;i++)
		for (int j=1;j<=b;j++)
			for (int l=1;l<=c;l++)
				p[cnt++]={i,j,l};
	ans=anss=0;
	dfs(0,0,0);
	printf("%d\n",ans);
	for (int i=0;i<cnt;i++)
		if (anss&(1<<i))
			printf("%d %d %d\n",p[i].a,p[i].b,p[i].c);
}

int main()
{
	freopen("read.txt","r",stdin);
	freopen("write.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;i++)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
