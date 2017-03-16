#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;
const int maxn=10000000+10;
int mark[maxn];
long long a,b;
long long ta,tb;


void work()
{
	scanf("%lld%lld",&a,&b);
	ta=sqrt(a);
	tb=sqrt(b);
	if (ta*ta<a) ta++;
	int res=mark[tb]-mark[ta-1];
	printf("%d\n",res);
}

bool check(long long p)
{
	long long rr=0,pp=p;
	while (p>0)
	{
		rr=rr*10+p%10;
		p/=10;
	}
	if (rr!=pp) return 0; else return 1;
}

void init()
{
	freopen(".in","r",stdin);
	freopen("a.out","w",stdout);
	mark[0]=0;
	for (long long i=1;i<=10000000;i++)
	{
		if (check(i) && check(i*i)) mark[i]=1;else mark[i]=0;
		mark[i]+=mark[i-1];
	}
}

int main()
{
	init();
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;i++)
	{
		printf("Case #%d: ",i);
		work();
	}
	return 0;
}
