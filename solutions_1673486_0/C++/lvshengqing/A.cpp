#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

double pp[100005],ans,sum[100005],s,temp;
int a,b;


int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		cin>>a>>b;
		s=1;
		for(int i=0;i<a;i++)
			scanf("%lf",&pp[i]),s*=pp[i],sum[i]=s;
		ans=20000000;
		//#1
		temp=sum[a-1]*(b-a+1)+(1-sum[a-1])*(b+b-a+2);
		if(temp<ans)
			ans=temp;
		for(int i=1;i<=a;i++)
		{
			temp=sum[a-1-i]*(b-a+1+i+i)+(1-sum[a-1-i])*(b+b-a+2+i+i);
			if(temp<ans)
				ans=temp;
		}
		temp=2+b;
		if(temp<ans)
			ans=temp;
		printf("Case #%d: %.6lf\n",t,ans);
		
	}
	return 0;
}
