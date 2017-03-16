#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

double p[100010];

int main()
{
	int T,t,i,A,B,b;
	double sum,min,temp,ans;
	//freopen("A-large.in","r",stdin);
	//freopen("A-large.out","w",stdout);
	scanf("%d",&T);
	for(t=1;t<=T;++t)
	{
		scanf("%d%d",&A,&B);
		min=B+2;
		b=B+1;
		temp=2*B-A+2*(A+1);
		sum=1;
		ans=temp-sum*b;
		min=ans<min?ans:min;
		for(i=1;i<=A;++i)
		{
			scanf("%lf",&p[i]);
			sum*=p[i];
			temp-=2;
	    	ans=temp-sum*b;
		    min=ans<min?ans:min;
		}
		printf("Case #%d: %f\n",t,min);
	}
	
	return 0;
}