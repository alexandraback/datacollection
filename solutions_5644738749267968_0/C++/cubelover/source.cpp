#include<cstdio>
#include<algorithm>

double a[1000];
double b[1000];

int main()
{
	freopen("D-small-attempt1.in","r",stdin);
	freopen("D-small-attempt1.out","w",stdout);
	int tc,tcn;
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++)
	{
		int ans1,ans2;
		int i,j,n;
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%lf",&a[i]);
		for(i=0;i<n;i++)scanf("%lf",&b[i]);
		std::sort(a,a+n);
		std::sort(b,b+n);
		ans1=n;
		for(i=j=0;j<n;i++,j++)
		{
			while(j<n&&b[j]<a[i])j++;
			if(j<n)ans1--;
		}
		ans2=0;
		for(i=j=0;i<n;i++,j++)
		{
			while(i<n&&b[j]>a[i])i++;
			if(i<n)ans2++;
		}
		printf("Case #%d: %d %d\n",tc,ans2,ans1);
	}
}