#include <cstdio>
char map[256]={};

void solve(int t)
{
	int n,s,p,a,ans=0;
	scanf("%d%d%d",&n,&s,&p);
	for (int i=0;i<n;++i)
	{
		scanf("%d",&a);
		if (p*3-2<=a)
			ans++;
		else if (p*3-4<=a && s && p<=a)
			ans++, s--;
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
