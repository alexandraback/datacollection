#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

double p[100005],mulp[100005];
int main()
{
	int t;
	int text=1;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		double ans1,ans2,ans3,P=1;
		scanf("%d%d",&a,&b);
		mulp[0]=1;
		for(int i=1;i<=a;i++)
		{
			scanf("%lf",&p[i]);
			mulp[i]=mulp[i-1]*p[i];	
			
		}
		P=mulp[a];
		ans1=(b-a+1)*P+(2*b-a+2)*(1-P);
		ans3=b+2;
//		cout<<ans1<<" "<<ans3<<endl;
		double minn=100000000.0;
		for(int i=1;i<=a;i++)
		{
			double v=b-a+2*i+1;
			ans2=mulp[a-i]*v+(1-mulp[a-i])*(v+b+1);
//			cout<<"ans2="<<ans2<<endl;
			if(ans2<minn)
				minn=ans2;
		}
		double ans=min(min(ans1,ans3),minn);
		printf("Case #%d: %.6lf\n",text++,ans);
	}
	return 0;
}