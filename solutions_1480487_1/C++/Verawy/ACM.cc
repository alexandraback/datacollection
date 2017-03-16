#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int s[1000],a[1000];

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int T,tt,n,i,sum,m,s2,j;
	double ans,point;
	scanf("%d",&T);
	for (int tt=1;tt<=T;tt++)
	{
		scanf("%d",&n); sum=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&s[i]);
			sum+=s[i]; a[i]=s[i];
		}
		m=n; s2=sum;
		sort(a+1,a+1+n);
		for (i=n;i>=1;i--)
		{
			j=i;
			while (a[j-1]==a[j]&&j>1) j--;
			if ((sum+s2-a[i]*(i-j+1)+0.0)/(m-(i-j+1))<=a[i])
			{
				m-=(i-j+1); s2-=(a[i]*(i-j+1));
//				cout<<s2<<' '<<a[i]<<' '<<m<<endl;
			}
			i=j;
		}
		point=(sum+s2+0.0)/m;
	//	cout<<point<<endl;
		double test=0.0;
		printf("Case #%d:",tt);
		for (i=1;i<=n;i++)
		{
			if (point>s[i])	ans=(point-s[i])*100.0/sum;
			else ans=0;
			printf(" %.10f",ans); test+=ans;
		}
		printf("\n");
	}
	return 0;
}
