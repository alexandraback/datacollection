// GCJ.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

long long gcd(long long a,long long b)
{
	if (a>b) return gcd(b,a);
	if (b%a==0) return a;
	return gcd(b%a,a);
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cout<<"Case #"<<i<<": ";
		long long p,q;
		int tmp=0;
		scanf("%lld/%lld",&p,&q);
		long long g=gcd(p,q);
		p=p/g;q=q/g;
		while (q>2*p)
		{
			if (q%2==0) q=q/2;
			else 
			{
				tmp=-1;
				break;
			}
			tmp++;
		}
		while (q!=1) 
		{
			if (q%2==0)
				q=q/2;
			else 
			{
				tmp=-1;
				break;
			}
		}
		if (tmp==-1) cout<<"impossible"<<endl;
		else
			cout<<tmp+1<<endl;
	}
	return 0;
}
