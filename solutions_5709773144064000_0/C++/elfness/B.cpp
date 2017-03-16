/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;

const int V=100100;
double t[V],C,F,X,p;
int _;

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&_);
	for(int ca=1;ca<=_;ca++)
	{
		scanf("%lf%lf%lf",&C,&F,&X);
		t[0]=0.0;
		for(int i=1;i<=X;i++)
		{
			p=2+F*(i-1);
			t[i]=t[i-1]+C/p;
		}
		double ret=1e9;
		for(int i=0;i<=X;i++)
		{
			p=2+F*i;
			ret=min(ret,t[i]+X/p);
		}
		printf("Case #%d: %.9f\n",ca,ret);
	}
	return 0;
}
