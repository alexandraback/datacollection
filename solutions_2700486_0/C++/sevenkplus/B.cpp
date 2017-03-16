#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
double f[4010][4010];
int main()
{
	int _;scanf("%d",&_);
	for(int __=1;__<=_;__++)
	{
		int n,x,y;
		scanf("%d%d%d",&n,&x,&y);
		printf("Case #%d: ",__);
		if(y<0){puts("0");continue;}
		if(abs(x+y)&1){puts("0");continue;}
		int p;
		if(x<0)p=(y-x)/2;
		else p=(y+x)/2;
		for(int i=0;i<p;i++)
		{
			n-=i*4+1;
			if(n<=0)break;
		}
		if(n<=0){puts("0");continue;}
		if(n>=p*4+1){puts("1");continue;}
		if(x==0){puts("0");continue;}
		for(int i=0;i<=2*p;i++)
			for(int j=0;j<=2*p;j++)
				f[i][j]=0;
		f[0][0]=1;
		double S=0;
		for(int i=0;i<=2*p;i++)
			for(int j=0;j<=2*p;j++)
			{
				if(i+j==n){if(j>y)S+=f[i][j];break;}
				if(i==2*p)f[i][j+1]+=f[i][j];else
				if(j==2*p)f[i+1][j]+=f[i][j];else f[i+1][j]+=f[i][j]/2,f[i][j+1]+=f[i][j]/2;
			}
		printf("%.9lf\n",S);
	}
	return 0;
}