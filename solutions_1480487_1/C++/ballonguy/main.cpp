#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string.h>
#include <vector>
#include <set>
using namespace std;
#pragma comment(linker, "/STACK:167772160")

#define sz(x) int((x).size())
const int inf = 1000000000;
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define pi 2*acos(0.0)
#define sqr(a) (a)*(a)
#define mp make_pair
#define pb push_back
typedef long long Int;
const int gck=420;

double a[2001];
int n;
int cur;
double X;

bool ok(double m)
{
	double s=0;
	FOR(i,1,n)
		if(i!=cur)
		if(a[cur]-a[i]+X*m>=0)
		s+=(a[cur]-a[i]+X*m)/X;
	return s+m>=1.0;
}

double f(double l,double r)
{
	while(r-l>1e-8)
	{
	double m=(l+r)/2;
	if(ok(m))r=m;else
		l=m;
	}
	return r;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int tes;
	cin>>tes;
	FOR(o,1,tes)
	{
		cin>>n;
		FOR(i,1,n)cin>>a[i];
		cout<<"Case #"<<o<<":";
		X=0;
		FOR(i,1,n)X+=a[i];
		FOR(i,1,n)
		{
			cur=i;
			double ans=f(0.0,1.0);
			printf(" %.5f",100*ans);
		}
		cout<<endl;
	}
	
	return 0;
}