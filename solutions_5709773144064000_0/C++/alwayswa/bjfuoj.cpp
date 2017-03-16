#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
#define LL long long
int A[10];
int main()
{
	freopen("data.in", "r", stdin);
	freopen("data.out","w",stdout);
	int T;
	scanf("%d", &T);
	int cas = 0;
	while (T--)
	{
		double c,f,x,s,ans=0;
		scanf("%lf %lf %lf",&c,&f,&x);
		s=2;
		while(1)
		{
			double t1,t2,t3;
			t1=x/s;
			t2=c/s;
			t3=x/(s+f);
			if(t1>t2+t3)
			{
				ans+=t2;
				s=s+f;
			}
			else
			{
				ans+=t1;
				break;
			}
		}
		printf("Case #%d: %.7lf\n",++cas,ans);
	}
	return 0;
}
