#include<iostream>
#include<cstdio>
using namespace std;

double st[100000];
double tmp[100000];
double ans2[100000];
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A.out","w",stdout);
	int T,a,b;
	double ans1,ans3;
	scanf("%d",&T);
	int cas = 0;
	while(T--)
	{
		cas++;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++)
			scanf("%lf",&st[i]);
		tmp[0] = 1;
		for(int i=1;i<=a;i++)
		{
			tmp[i] = tmp[i-1]*st[i];
		}
		ans1 = ans3 = 0;
		for(int i=1;i<=a;i++)
		{
			ans1 += tmp[i-1]*(1-st[i])*(b+1+b-a+1);
			ans2[i] = (1-tmp[a-i])*(i-a+1+b+i+1+b);
			ans2[i] += tmp[a-i]*(i-a+1+b+i);
		}
		double ans22 = 10000000;
		for(int i=1;i<=a;i++)
			ans22 = min(ans22,ans2[i]);
		ans1 += tmp[a]*(b-a+1);
		ans3 = b+2;
	//	cout<<ans1<<" "<<ans22<<" "<<ans3<<endl;
		printf("Case #%d: %.6lf\n",cas,min(min(ans1,ans22),ans3));
	}
	return 0;
}
