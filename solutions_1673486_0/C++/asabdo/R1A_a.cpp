#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<map>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
#include<climits>
#include<set>
#include<iterator>
#include<complex>
#ifdef _MSC_VER
#include <hash_set>
#include <hash_map>
using namespace stdext;
#else
#if __GNUC__ > 2
#include <ext/hash_set>
#include <ext/hash_map>
using namespace __gnu_cxx;
#else
#include <hash_set>
#include <hash_map>
#endif
#endif
using namespace std;



typedef complex<double> point;
#define sz(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define EPS 1e-1
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define polar(r,t) ((r)*exp(point(0,(t))))
#define angle(v) (atan2((v).Y,(v).X))
#define dist(v) ((double)hypot((v).Y,(v).X))
#define length(v) dist(v)
#define lengthSqr(v) (dot(v,v))
#define dot(a,b) ((conj(a)*(b)).real())
#define cross(a,b) ((conj(a)*(b)).imag())
#define rotate(v,t) (polar(v,t))
#define rotateabout(v,t,a)  (rotate(vec(a,v),t)+(a))
#define reflect(p,m) ((conj((p)/(m)))*(m))
#define normalize(p) ((p)/length(p))
#define same(a,b) (lengthSqr(vec(a,b))<EPS)
#define mid(a,b) (((a)+(b))/point(2,0))
#define perp(a) (point(-(a).Y,(a).X))
#define colliner pointOnLine
const double PI = acos(-1.);
int N;
int A,B;
const double ZERO = 0;
const double INF = 1/ZERO;
double p[5];
double keep(int m)
{
	double r = B-A+1;
	double P = 1;
	for(int i=0;i<A;i++)
		if(m&(1<<i))
			P*=(1-p[i]);
		else P*=(p[i]);
		return P*(r + (m?B+1:0));
}
double b(int m,int i)
{
	if( i > A )
		return INF;
	if( i == A )
		return (i+B+1)/(1<<A);
	double r = B-A+1+(i*2);
	double P = 1;
	for(int i=0;i<A;i++)
	{
		if(m&(1<<i))
			P*=(1-p[i]);
		else P*=(p[i]);
	}
	if( A == 1)
		m = 0;
	if( A == 2)
	{
		if( i == 1)
			m&=1;
		else m = 0;
	}
	if( A == 3)
	{
		if( i == 1)
			m&=3;
		if( i == 2)
			m&=1;
		if( i == 3)
			m = 0;
	}
	return P*(r + (m?B+1:0));
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","rt",stdin);
	freopen("Aout.txt","wt",stdout);
#endif
	int TC=1;
	scanf("%d",&TC);
	for(int tc=1;tc<=TC;tc++)
	{
		scanf("%d %d",&A,&B);
		for(int i=0;i<A;i++)
			scanf("%lf",&p[i]);
		double ans = INF;
		double r[5];
		r[0] = r[1] = r[2] = r[3] = r[4] = 0;
		for(int m=0;m<(1<<A);m++)
		{
			r[0]+= keep(m);
			r[1]+= b(m,1);
			r[2]+= b(m,2);
			r[3]+= b(m,3);
			r[4] = B+2;
		}
		for(int i=0;i<5;i++)
			ans = min(r[i],ans);
		printf("Case #%d: %lf\n",tc,ans);
	}
	return 0;
}