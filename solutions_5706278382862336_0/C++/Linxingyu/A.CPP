#include <cstdio>
#include <cstdlib>

using namespace std;

long long n,m,t;
int test;
char ch;

long long gcd(long long a, long long b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	//freopen("x.in","r",stdin);
	//freopen("x.out","w",stdout);
	scanf("%d",&test);
	for (int i=1; i<=test; ++i)
	{
		scanf("%lld%c%lld",&n,&ch,&m);
		if (n==0)
		{
			 printf("Case #%d: impossible\n",i);
			 continue;
		}
		t=gcd(n,m);
		m/=t;
		n/=t;
		long long tm=m;
		int cnt=0;
		while (m>1 && m%2==0)
		{
			m/=2;
			cnt++;
		}
		printf("Case #%d: ",i);
		if (m>1 || cnt>40) printf("impossible\n");
		else 
		{
			int ans=0; long long mul=1;
			while (n*mul<tm)
			{
				ans++;
				mul*=2;
			}
			printf("%d\n",ans);
		}
	}
//	while (1);
}
