#include<iostream>
#include<cstdio>

using namespace std;

const int maxn=1000;
const int maxm=11000000;
int a[maxn];
int n,m,num;
int ca;
void solve()
{
	sort(a+1,a+n+1);

	printf("Case #%d: ",++ca);
	if (m==1)
	{
		printf("%d\n",n);
		return;
	}
	
	
	int ans=0x7FFFFFFF;

	for (int i=n; i>=0; i--)
	{
		int sum=m, tot=0;
		for (int j=1; j<=i; j++)
		{
			while (sum<=a[j])
			{
				sum+=sum-1;
				++tot;		
			}
			sum+=a[j];
		}
		ans=min(ans,tot+n-i);
	}

	printf("%d\n",ans);
}
void init()
{
	scanf("%d",&num);
	while (num--)
	{
		scanf("%d%d",&m,&n);
		for (int i=1; i<=n; i++) scanf("%d",&a[i]);
		solve();
	}
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	init();
	return 0;
}
