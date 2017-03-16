#include<iostream>
#include<algorithm>
#include<stdio.h>
#define N 11
using namespace std;
typedef unsigned long long ull;
void calc(int,int,int);
int e,r,n,value[N],mg;
int main()
{	int t,i,j;
	cin>>t;
	for(i=1;i<=t;i++)
	{	scanf("%d %d %d",&e,&r,&n);
		mg=0;
		for(j=0;j<n;j++)
			scanf("%d",&value[j]);
		calc(0,0,e);
		printf("Case #%d: %d\n",i,mg);
	}
	return 0;
}
void calc(int n,int g,int e)
{	if(n==::n)
	{	mg=max(mg,g);
		return;
	}
	for(int i=0;i<=e;i++)
		calc(n+1,g+value[n]*i,min(e-i+r,::e));
}