#include <cstdio>
char map[256]={};

void solve(int t)
{
	int a,b,ans=0,z=1;
	scanf("%d%d",&a,&b);
	for (int i=a;i<=b;++i)
	{
		int k=i;
		while (z*10<=i)
			z*=10;
		while (1)
		{
			k = (k%10)*z+(k/10);
			if (k==i)
				break;
			if (a<=k && k<=b && k>i)
				ans++;
		}
	}
	printf("Case #%d: %d\n",t,ans);
}

int main()
{
	freopen("input.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for (int t=0;t<T;++t)
		solve(t+1);
	return 0;
}
