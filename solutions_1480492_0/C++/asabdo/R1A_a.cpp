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

struct st
{
	bool c;
	double s,d;
	st(bool c,double s,double d):c(c),s(s),d(d){}
	st(){}
};
vector<st> v;
#define mk(a,b) make_pair((a),(b))
double calc(int i,int j)
{
	return (v[j].d-v[i].d-5) / (v[i].s - v[j].s);
}
const double ZERO = 0;
const double INF = 1/ZERO;
#define eps 1e-9

#define eq(a,b) ( fabs((a)-(b)) < eps )
#define ls(a,b) ((a)<(b) && fabs((a)-(b)) > eps)
#define lseq(a,b) ((a)<(b) || fabs((a)-(b)) < eps)

#define gr(a,b) ((a)>(b) && fabs((a)-(b)) > eps)
#define greq(a,b) ((a)>(b) || fabs((a)-(b)) < eps)
bool ok(int I)
{
	for( int i=0;i<(int)v.size();i++)
		if(v[i].c != v[I].c)
		{
			if( ls(v[i].d,v[I].d+5) && greq(v[i].d,v[I].d ) )
				return false;
			else if( gr(v[i].d + 5,v[I].d) && lseq(v[i].d+5, v[I].d+5) )
				return false;
			else if( eq(v[I].d +5 , v[i].d) && v[i].s < v[I].s)
				return false;
			else if( eq( v[I].d , v[i].d+5 ) && v[i].s > v[I].s )
				return false;
		}
		return true;
}
double dfs()
{
	set< pair<double , pair<int,int> > > s;
	for(int i=0;i<(int)v.size();i++)
		for(int j=0;j<(int)v.size();j++)
			if(i != j)
			{
				if( v[i].c == v[j].c && v[i].s > v[j].s && v[i].d < v[j].d )
					s.insert( mk( calc(i,j) , mk(i,j) ) );
			}
			if( !s.size() )
				return INF;
			int I,J;
			double T;
			I = s.begin()->second.first;
			J = s.begin()->second.second;
			T = s.begin()->first;
			for(int i=0;i<(int)v.size();i++)
				v[i].d += v[i].s*T;
			double r1,r2;
			r1 = r2 = 0;
			if( ok(I) )
			{
				v[I].c = !v[I].c;
				r1 = dfs();
				v[I].c = !v[I].c;
			}
			if( ok(J) )
			{
				v[J].c = !v[J].c;
				r2 = dfs();
				v[J].c = !v[J].c;

			}

			for(int i=0;i<(int)v.size();i++)
				v[i].d -= v[i].s*T;

			return s.begin()->first + max(r1,r2);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","rt",stdin);
	freopen("Cout.txt","wt",stdout);
#endif
	int TC=1;
	scanf("%d",&TC);
	for(int tc=1;tc<=TC;tc++)
	{
		cerr<<tc<<endl;
		v.clear();
		int n,d,s;
		char c;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf(" %c %d %d",&c,&s,&d);
			v.push_back( st(c=='L',s,d) );
		}
		double r = dfs();
		printf("Case #%d: ",tc);
		if( r < INF )
			printf("%lf\n",r);
		else printf("Possible\n");
	}
	return 0;
}