//Time:4/14/2012
//Author:PiAnte28
//Language:C++
//For Google Code Jam Dancing With the Googlers
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int tt,hehe,a,b,c,n,s,p;

int main()
{
    freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d\n",&tt);hehe=tt;
	while (tt--)
	{
	    int ans(0),val;
	    scanf("%d %d %d",&n,&s,&p);
		for (int i=1;i<=n;i++)
		{
		    scanf("%d",&val);
			int mm(val%3);
			a=b=c=val/3;
			if (mm==0)
			{
			    if (a>=p) {ans++;continue;}
				if (a+1>=p && b>=1 && s>0) {ans++;s--;continue;}
			}
			if (mm==1)
			{
			    if (a+1>=p) {ans++;continue;}
			}
			if (mm==2)
			{
			    if (a+1>=p) {ans++;continue;}
				if (a+2>=p && s>0) {ans++;s--;continue;}
			}
		}
		printf("Case #%d: %d\n",hehe-tt,ans);
	}
	return 0;
}
