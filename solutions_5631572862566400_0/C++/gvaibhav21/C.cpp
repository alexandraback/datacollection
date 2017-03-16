#include<bits/stdc++.h>
using namespace std;

#define sd(a) scanf("%d",&a)
#define ss(a) scanf("%s",&a)
#define sl(a) scanf("%lld",&a)
#define clr(a) memset(a,0,sizeof(a))
#define debug(a) printf("check%d\n",a)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ll long long
int bff[1010];
int mark[1010];
int Time[1010];
vector<int> v[1010];
int maxd;
void dfs(int cur,int d)
{
	mark[cur]=1;
	maxd=max(maxd,d);
	for(int i=0;i<v[cur].size();++i)
		if(!mark[v[cur][i]] && v[cur][i]!=bff[cur])
			dfs(v[cur][i],d+1);
}
int main()
{
	//freopen("C_1.in","r",stdin);
	//freopen("C_1.out","w",stdout);
	int t,i,j,k,n;
	sd(t);
	for(int tt=1;tt<=t;tt++)
	{
		sd(n);
		clr(mark);
		for(i=1;i<=n;++i)
			v[i].clear();
		for(i=1;i<=n;++i)
		{
			sd(bff[i]);
			v[bff[i]].PB(i);
		}
		int cnt=0,maxx=-1,j=1;
		for(i=1;i<=n;++i)
		{
			if(mark[i])	continue;
			j++;
			int cur=i,c=0;
			while(true)
			{
				if(mark[cur])
				{
					if(mark[cur]==j)
					{
						int cycle=c-Time[cur]+1;
						maxx=max(maxx,cycle);
					}
					break;
				}
				mark[cur]=j;
				Time[cur]=++c;
				cur=bff[cur];
			}
		}
		clr(mark);
		for(i=1;i<=n;++i)
		{
			if(mark[i])	continue;
			if(bff[bff[i]]!=i)	continue;
			
			cnt+=2;

			maxd=-1;
			dfs(i,0);
			cnt+=maxd;
			maxd=-1;
			dfs(bff[i],0);
			cnt+=maxd;
		}
		printf("Case #%d: %d\n",tt,max(maxx,cnt));
	}
}