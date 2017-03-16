// gcjr1cc题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
long long A[105];
long long a[105];
long long B[105];
long long b[105];
long long abak[105];
long long bbak[105];
int main()
{
	long long n,m,i,j,k,t,tt,res;
	freopen("in.txt","r",stdin);
	freopen("out5.txt","w",stdout);
	scanf("%lld",&t);
	for(tt=1;tt<=t;tt++)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		printf("Case #%lld: ",tt);
		scanf("%lld %lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%lld %lld",&a[i],&A[i]);
		}
		for(i=1;i<=m;i++)
		{
			scanf("%lld %lld",&b[i],&B[i]);
		}
		for(i=0;i<=n;i++)
			abak[i]=a[i];
		for(i=0;i<=m;i++)
			bbak[i]=b[i];
		res=0;
		if(n==1)
		{
			for(i=1;i<=m;i++)
			{
				if(B[i]==A[1])
				{
					if(a[1]>b[i])
					{
						res+=b[i];
						a[1]-=b[i];
						b[i]=0;
					}
					else
					{
						res+=a[1];
						a[1]=0;
					}
				}
			}
		}
		else if(n==2)
		{
			long long i1,j1;
			long long max1;
			for(i=0;i<=m;i++)
			{
				for(i1=1;i1<=n;i1++)
					a[i1]=abak[i1];
				for(j1=1;j1<=m;j1++)
					b[j1]=bbak[j1];
				max1=0;
				for(i1=1;i1<=i;i1++)
					if(B[i1]==A[1])
					{
						if(a[1]>b[i1])
						{
							max1+=b[i1];
							a[1]-=b[i1];
							b[i1]=0;
						}
						else
						{
							max1+=a[1];
							b[i1]-=a[1];
							a[1]=0;
						}
					}
					for(i1=i+1;i1<=m;i1++)
					{
						if(B[i1]==A[2])
						{
							if(a[2]>b[i1])
							{
								max1+=b[i1];
								a[2]-=b[i1];
								b[i1]=0;
							}
							else
							{
								max1+=a[2];
								b[i1]-=a[2];
								a[2]=0;
							}
						}
					}
					if(max1>res)
						res=max1;
			}

		}
		else if(n==3)
		{
			long long i1,j1;
			long long max1;
			for(i=0;i<=m;i++)
				for(j=0;j<=m;j++)
				{
					for(i1=1;i1<=n;i1++)
						a[i1]=abak[i1];
					for(j1=1;j1<=m;j1++)
						b[j1]=bbak[j1];
					max1=0;
					for(i1=1;i1<=i;i1++)
						if(B[i1]==A[1])
						{
							if(a[1]>b[i1])
							{
								max1+=b[i1];
								a[1]-=b[i1];
								b[i1]=0;
							}
							else
							{
								max1+=a[1];
								b[i1]-=a[1];
								a[1]=0;
							}
						}
						for(i1=i+1;i1<=j;i1++)
						{
							if(B[i1]==A[2])
							{
								if(a[2]>b[i1])
								{
									max1+=b[i1];
									a[2]-=b[i1];
									b[i1]=0;
								}
								else
								{
									max1+=a[2];
									b[i1]-=a[2];
									a[2]=0;
								}
							}
						}
						for(i1=j+1;i1<=m;i1++)
						{
							if(B[i1]==A[3])
							{
								if(a[3]>b[i1])
								{
									max1+=b[i1];
									a[3]-=b[i1];
									b[i1]=0;
								}
								else
								{
									max1+=a[3];
									b[i1]-=a[3];
									a[3]=0;
								}
							}
						}
						if(max1>res)
							res=max1;
				}

		}
		printf("%lld\n",res);
	}
	return 0;
}

