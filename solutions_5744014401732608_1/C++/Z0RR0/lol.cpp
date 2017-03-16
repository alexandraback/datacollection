#include <bits/stdc++.h>

#define rep(i,n) for(i=1;i<=n;i++)
#define Rep(i,n) for(i=0;i<n;i++)
#define For(i,a,b) for(i=a;i<=b;i++)

#define pb(x) push_back(x)
#define sz(x) x.size()

#define mem(ara,val) memset(ara,val,sizeof(ara))
#define eps 1e-9

#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d %d",&x,&y)
#define siii(x,y,z) scanf("%d %d %d",&x,&y,&z)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld %lld",&x,&y)
#define slll(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define ss(ch) scanf("%s",ch)
#define pi(x) printf("%d",x)
#define pii(x,y) printf("%d %d",x,y)
#define piii(x,y,z) printf("%d %d %d",x,y,z)
#define pl(x) printf("%lld",x)
#define pll(x,y) printf("%lld %lld",x,y)
#define plll(x,y,z) printf("%lld %lld %lld",x,y,z)
#define ps(ch) printf("%s",ch)
#define Afridi 0
#define NL printf("\n")
#define debug(x) printf("wow  %d !!\n",x)
#define Max 1000000
#define INF INT_MAX
#define mod 1000000007
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

LL bigmod(LL b,LL p)
{
    if(p == 0)return 1;
    LL my = bigmod(b,p/2);
    my*=my;my%=mod;
    if(p & 1)my*=b,my%=mod;
    return my;
}
int setb(int n,int pos){return n=n | (1 << pos);}
int resb(int n,int pos){return n=n & ~(1 << pos);}
bool checkb(int n,int pos){return (bool)(n & (1 << pos));}

LL n,m;
LL graph[60][60];

int main()
{
	//FI;
	freopen("B-large.in","r",stdin);
	freopen("Blarge.out","w",stdout);
	LL t,T,i,j;
	sl(T);
	rep(t,T)
	{
		sll(n,m);
		mem(graph,0);
		for(i=2;i<n;i++)
		{
			for(j=1;j<i;j++)
			{
				graph[i][j] = 1;
			}
		}
		LL way = 1;
		rep(i,n-2)way *= 2;
		printf("Case #%lld: ",t);
		if(way < m)
		{
			printf("IMPOSSIBLE\n");
		}
		else
		{
			printf("POSSIBLE\n");
			LL cur = way / 2;
			LL d = n - 1;
			while(d > 1)
			{
				//printf("m %lld cur %lld d %lld\n",m,cur,d);
				if(cur <= m)
				{
					m -= cur;
					graph[n][d] = 1;
				}
				d--;
				cur /= 2;
			}
			if(m == 1)
			{
				graph[n][1] = 1;
			}
			for(i=n;i>=1;i--)
			{
				for(j=n;j>=1;j--)
				{
					printf("%lld",graph[i][j]);
				}
				NL;
			}
		}
	}
    return 0;
}
