#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <set>
#include <ctime>
#include <algorithm>
#define min(a,b)	((a)<(b)?(a):(b))
#define max(a,b)	((a)>(b)?(a):(b))
#define abs(a)	((a)<0?-(a):(a))
#define inf 214748364
#define pi 3.141592653589793
using namespace std;
typedef long long ll;

const int maxn = 101;
int tim,n,s,p;
int g[maxn],f[maxn][maxn];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	#endif
	scanf("%d",&tim);
	for(int tt=1;tt<=tim;++tt)
	{
		printf("Case #%d: ",tt);
		scanf("%d%d%d",&n,&s,&p);
		for(int i=1;i<=n;++i)
			scanf("%d",&g[i]);
		memset(f,-63,sizeof(f));
		f[0][0]=0;
		for(int i=1;i<=n;++i)
		{
			bool ba=1;
			if(g[i]<=1||g[i]>=29)
				ba=0;
			int mi,ma;
			if(g[i]%3==0)
				mi=g[i]/3;else
				mi=g[i]/3+1;
			if(ba)
			{
				if(g[i]%3!=2)
					ma=g[i]/3+1;else
					ma=g[i]/3+2;
			}
			mi=(mi>=p),ma=(ma>=p);
			for(int j=0;j<=s;++j)
			{
				f[i][j]=max(f[i][j],f[i-1][j]+mi);
				if(ba)
					f[i][j+1]=max(f[i][j+1],f[i-1][j]+ma);
			}
		}
		printf("%d\n",f[n][s]);
	}
	return 0;
}

