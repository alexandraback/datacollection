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

const int maxn = 200001;
int tim,a,b;
double pl[maxn],g[maxn];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	#endif
	scanf("%d",&tim);
	for(int tt=1;tt<=tim;++tt)
	{
		scanf("%d%d",&a,&b);
		memset(pl,0,sizeof(pl));
		pl[0]=1;
		for(int i=1;i<=a;++i)
		{
			scanf("%lf",&g[i]);
			pl[i]=pl[i-1]*g[i];
		}
		double res=b+2;
		for(int i=0;i<=a;++i)
		{
			double ans=pl[i]*((a-i)+(b-i)+1);
			ans+=(1-pl[i])*((a-i)+(b-i)+1 + b+1);
			res=min(res,ans);
		}
		printf("Case #%d: %.10lf\n",tt,res);
	}
	return 0;
}

