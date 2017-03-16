//============================================================================
// Name        : B.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

int main()
{
	//freopen("B-small-attempt5.in","r",stdin);
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;
	int N,X,Y;
	scanf("%d",&T);
	int iCase=0;
	while(T--)
	{
		iCase++;
		scanf("%d%d%d",&N,&X,&Y);
		if(X<0)X=-X;
		printf("Case #%d: ",iCase);
		int t=1;
		int tmp=N;
		while(tmp>4*t-3)
		{
			tmp-=4*t-3;
			t++;
		}
		//printf("%d  %d\n",t,tmp);
		if(X+Y<2*(t-1))
		{
			printf("1.0\n");
			continue;
		}
		if(X+Y>2*(t-1))
		{
			printf("0.0\n");
			continue;
		}
		if(tmp==4*t-3)
		{
			printf("1.0\n");
			continue;
		}
		if(X==0 && Y==2*(t-1))
		{
			printf("0.0\n");
			continue;
		}
		int cc;
		if(X>=0)cc=2*(t-1)-X;
		else cc=2*(t-1)+X;
		cc++;
		if(tmp<cc)
		{
			printf("0.0\n");
			continue;
		}
		if(tmp-(2*t-2)>=cc)
		{
			printf("1.0\n");
			continue;
		}
		//printf("%d  %d %d\n",tmp,cc,t);
		double temp=0;

		//for(int p=0;p<cc;p++)
		//{
			double ans=1.0;
			temp=1.0;
			int cnt=tmp;
			for(int i=1;i<cc;i++)
			{
				ans*=(double)(tmp-i+1)/i;
				//printf("%lf\n",ans);
				temp+=ans;
				while(cnt>0 && temp>1 && ans>1)
				{
					temp/=2;
					ans/=2;
					cnt--;
				}
			}
		//}

		//temp*=pow(0.5,tmp);
			while(cnt>0 && temp>1)
			{
				temp/=2;
				cnt--;
			}
		printf("%.8lf\n",1-temp);
	}
	return 0;
}
