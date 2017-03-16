#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int T,casenum;
double D;
double a[300];
double t[2010];
double x[2010];
double n,A,ans;
int i,j;
int main()
{
	freopen("gcj.in","r",stdin);
	freopen("gcj.out","w",stdout);
	cin>>T;
	for (casenum=1;casenum<=T;casenum++)
	{
		cout<<"Case #"<<casenum<<":\n";
		cin>>D>>n>>A;
		for (i=1;i<=n;i++)
			cin>>t[i]>>x[i];
		for (i=1;i<=A;i++)
			cin>>a[i];
		for (i=1;i<=A;i++)
		{
			if (n==1)
			{
				ans=sqrt(2*D/a[i]);
			}
			if (n==2)
			{
				ans=sqrt(2*D/a[i]);
				if (x[1]<D)
				{
					double p=t[2]*(D-x[1])/(x[2]-x[1]);
					if (p>ans)	ans=p;
				}
			}
			printf("%.8f\n",ans);
		}
	}
}
