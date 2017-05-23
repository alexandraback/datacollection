#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
double mic[200020];
double newmic[200020];
main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int t;
	cin >> t;
	int n,k,x,y;
	double ans;
	for(int ll=0;ll<t;ll++)
	{
		scanf("%d %d %d",&n,&x,&y);
		printf("Case #%d: ",ll+1);
		if(x<0) x=-x;
		k=x+y;
		k/=2;
		if(x==0)
		{
			//cout << "A";
			if(n>=2*k*k+3*k+1) printf("1.0\n");
			else printf("0.0\n");
			continue;
		}
		//cout << "AAAAA";
		if(n<=2*k*k-k)
		{
			//cout << "A";
			printf("0.0\n");
			continue;
		}
		if(n>=2*k*k+3*k+1)
		{
			//cout << "A";
			printf("1.0\n");
			continue;
		}
		//cout << "A";
		n-=2*k*k-k;
		if(n<=y)
		{
			//cout << "A";
			printf("0.0\n");
			continue;
		}
		mic[0]=1.0;
		for(int i=1;i<=20000;i++) mic[i]=0.0;
		for(int i=0;i<=20000;i++) newmic[i]=0.0;
		int z;
		//cout << "---" << n << endl;
		for(int i=0;i<n;i++)
		{
			z=min(x+y,i+1);
			for(int j=0;j<=z;j++)
			{
				if(i-j>x+y) continue;
				if(i-j==x+y) newmic[j+1]+=mic[j];
				else if(j==x+y) newmic[j]+=mic[j];
				else
				{
					newmic[j]+=mic[j]/2;
					newmic[j+1]+=mic[j]/2;
				}
			}
			for(int j=0;j<=z;j++) mic[j]=newmic[j];
			//cout << mic[0] << " " << mic[1] << " " << mic[2] << " " << mic[3] << " " << mic[4] << endl;
			for(int j=0;j<=z;j++) newmic[j]=0.0;
		}
		z=min(n,x+y);
		double ans=0.0;
		//cout << "---" <<  y+1 << " " << z << endl;
		for(int i=y+1;i<=z;i++)
		{
			ans+=mic[i];
		}
		//double sum=0.0;
		
		//for(int i=0;i<=z;i++) sum+=mic[i];
		//cout << sum << endl;
		printf("%.6lf\n",ans);
	}
}
/*
7
13 1 3
*/
