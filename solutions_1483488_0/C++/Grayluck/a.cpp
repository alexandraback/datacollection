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

const int maxn = 2000001;
int f[maxn],g[maxn],ff[maxn];

int work(int a,int b,int t)
{
	int res=0;
	for(int i=a;i<=b;++i)
	if(ff[i]!=t)
	{
		int p=i;
		int n=0,ten=1;
		while(p)
			n++,p/=10,ten*=10;
		ten/=10;
		p=i;
		int pl=0;
		for(int j=1;j<=n;++j)
		{
			if( a<=p&&p<=b && (f[p]!=i||ff[p]!=t) && p/ten )
				pl++,f[p]=i,ff[p]=t;
			p=ten*(p%10)+p/10;
		}
		pl=pl*(pl-1)/2;
		res+=pl;
	}
	return res;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	#endif
	int tim;
	scanf("%d",&tim);
	for(int tt=1;tt<=tim;++tt)
	{
		printf("Case #%d: ",tt);
		int a,b;
		scanf("%d%d",&a,&b);
		int res=work(a,b,tt);
		printf("%I64d\n",res);
	}
	return 0;
}

