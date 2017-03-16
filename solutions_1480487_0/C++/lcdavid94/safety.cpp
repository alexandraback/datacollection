#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,a[500];
int main()
{
	//freopen("safety.in","r",stdin);
	//freopen("safety.out","w",stdout);
	cin>>t;
	for (int tt=1;tt<=t;++tt)
		{
			cin>>n;
			int sum=0;
			for (int i=0;i<n;++i)
				{
					cin>>a[i];
					sum+=a[i];
				}
			printf("Case #%d:",tt);
			for (int i=0;i<n;++i)
			{
			 double left=0.0,right=1.0;
			 while (right-left>1e-10)
				{
					double mid=(left+right)/2,score=a[i]+sum*mid,tot=1.0;
					for (int j=0;j<n;++j)
							if (score-a[j]>1e-10) tot-=(score-a[j])/sum;
					if (tot<0) right=mid;else left=mid;
				}
			 printf(" %.6lf",left*100);
			}
			printf("\n");
		}
}
