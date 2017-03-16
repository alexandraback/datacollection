#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int a[205];
int main()
{
	freopen("A-s.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++)
	{
		printf("Case #%d:",cas);
		int n;
		scanf("%d",&n);
		int sum=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		for (int i=1;i<=n;i++)
		{
			double l=0,r=100;
			for (int j=1;j<=1000;j++)
			{
				double mid=(l+r)/2.0;
				double left=100-mid;
				double nowi=a[i]+sum*(mid/100.0);
				bool flag=false;
				for (int k=1;k<=n;k++)
				{
					if (i==k) continue;
					double want=(double)max(0.0,nowi-a[k])/(double)sum*100.0;
					if (want>left)
					{
						flag=true;break;
					}
					else left-=want;
				}
				if (flag) r=mid;
				else l=mid;
			}
			printf(" %.8f",l);
		}
		puts("");

	}
}
