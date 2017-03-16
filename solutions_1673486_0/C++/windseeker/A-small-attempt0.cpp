#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int Len=100010;
double mu[3];
double p[Len];
double sum[2][Len];

int main()
{
	int i,j;
	int c;
	int tc=1;
	freopen("A-small-attempt1.in","r",stdin);
	freopen("A-small-attempt1.out","w",stdout);
	scanf("%d",&c);
	while(c--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		double res[3];
		for(i=1;i<=a;i++)
		scanf("%lf",&p[i]);
		mu[0]=mu[1]=1.0;
		for(i=a;i>=1;i--)
		if(i==a)
		sum[1][i]=1.0-p[i];
		else
		sum[1][i]=(1.0-p[i])*sum[1][i+1];
		sum[1][a+1]=1;
		for(i=1;i<=a;i++)
		{
			mu[0]*=p[i];
			mu[1]*=(1.0-p[i]);
		}
		res[0]=mu[0]*(1.0+b-a)+(1.0-mu[0])*(2+b-a+b);
		res[1]=1000000000;
		mu[2]=1;
		p[0]=1;
		for(i=0;i<=a;i++)
		{
			mu[2]*=p[i];
			double temp=mu[2]*((a-i)*2+b-a+1)+(1.0-mu[2])*(b-i+a-i+2+b);
	//		cout<<i<<" "<<mu[2]<<" "<<temp<<endl;
			res[1]=min(res[1],temp);
		}
		res[2]=2+b;
		double mmin=min(min(res[0],res[1]),res[2]);
	//	cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<endl;
		printf("Case #%d: %.6lf\n",tc++,mmin);
	}
	return 0;
}