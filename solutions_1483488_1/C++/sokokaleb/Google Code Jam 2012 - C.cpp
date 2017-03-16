#define nganggo using
#define nemspes namespace
#define standar std
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<cstdlib>
#include<cctype>
#include<bitset>
#include<string>
#include<map>
#include<complex>
#include<set>
 
#define FOR(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORN(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<=(_t);++(_i))
#define FORD(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i>=(_t);--(_i))
#define FORLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORNLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);(_i)<=(_t);++(_i))
#define FORDLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);(_i)>=(_t);--(_i))
#define FOREACH(_i,_a) for (__typeof(_a.begin()) _i=_a.begin();_i!=_a.end();++_i)
#define RESET(_a,_value) memset(_a,_value,sizeof(_a))
#define debugln clog << "----OK----" << endl;
#define debug(_a) clog << "Value of " <<  #_a << " is: " << (_a) << endl;
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define mp make_pair
#define SIZE(_a) (int)_a.size()
#define VSORT(_a) sort(_a.begin(),_a.end())
#define SSORT(_a,_val) sort(_a,_a+(_val))
#define ALL(_a) _a.begin(),_a.end()
#define MAX(_a,_b) (((_a)>(_b))?(_a):(_b))
#define MIN(_a,_b) (((_a)<(_b))?(_a):(_b))
 
nganggo nemspes standar;
 
const int dr[]={ 1, 0,-1, 0, 1, 1,-1,-1};
const int dc[]={ 0, 1, 0,-1, 1,-1,-1, 1};
const double eps=1e-9;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef pair<double,double> pdd;
typedef vector<pdd> vpdd;
const int INF=0x7FFFFFFF;
const ll INFLL=0x7FFFFFFFFFFFFFFFLL;
const double pi=acos(-1);

struct point_i
{
	int x,y;
	point_i (int _x=0,int _y=0) {x=_x;y=_y;}
};

struct point
{
	double x,y;
	point (double _x=0,double _y=0) {x=_x;y=_y;}
	bool operator < (const point &other) const
	{
		if (fabs(x-other.x)<eps)
			return y<other.y;
		return x<other.x;
	}
};

struct line_s
{
	point beg,end;
	line_s () {beg=point(0,0);end=point(0,0);}
	line_s (point a,point b) : beg(a),end(b) {}
	bool intersect (const line_s &other,point &ans)
	{
		double mua,mub;
		double denom,numera,numerb;

		denom  = (other.end.y-other.beg.y) * (end.x-beg.x) - (other.end.x-other.beg.x) * (end.y-beg.y);
		numera = (other.end.x-other.beg.x) * (beg.y-other.beg.y) - (other.end.y-other.beg.y) * (beg.x-other.beg.x);
		numerb = (end.x-beg.x) * (beg.y-other.beg.y) - (end.y-beg.y) * (beg.x-other.beg.x);
		
		if (denom==0 && numera==0 && numerb==0) return 0;
		
		mua=numera/denom;
		mub=numerb/denom;
		if (mua<0 || mua>1 || mub<0 || mub>1)
		{
			ans.x=0;
			ans.y=0;
			return 0;
		}
		ans.x=beg.x+mua*(end.x-beg.x);
		ans.y=beg.y+mua*(end.y-beg.y);
		return 1;
	}
};

struct line
{
	double a,b,c,len;
	line () {a=b=c=0.0;}
	line (const point &a_,const point &b_)
	{
		if (fabs(a_.x-b_.x)<eps)
		{
			a=1.0;
			b=0.0;
			c=-a_.x;
		}
		else
		{
			a=-(double)(a_.y-b_.y)/(a_.x-b_.x);
			b=1.0;
			c=-(double)(a_.x*a)-(double)(a_.y*b);
		}
		if (fabs(a)<eps) a=fabs(a);
		if (fabs(b)<eps) b=fabs(b);
		if (fabs(c)<eps) c=fabs(c);
		double x=a_.x-b_.x,y=a_.y-b_.y;
		len=sqrt((x*x)+(y*y));
	}
	bool parallel (const line &other)
	{
		return (fabs(a-other.a)<eps && fabs(b-other.b)<eps);
	}
	bool same (const line &other)
	{	
		return (*this).parallel(other) && fabs(c-other.c)<eps;
	}
};

inline void getint(int &num)
{
	bool neg=0;
	num=0;
	char c;
	while ((c=getchar_unlocked()) && (!isdigit(c) && c!='-'));
	if (c=='-')
	{
		neg=1;
		c=getchar_unlocked();
	}
	do num=num*10+c-'0';
	while ((c=getchar_unlocked()) && isdigit(c));
	num*=(neg)?-1:1;
}

//using sokokaleb's template v2.2.4

int T,a,b;

int main()
{
	getint(T);
	FORN (iz,1,T)
	{
		getint(a);getint(b);
		ll ans=0;
		int lg10=log10(a);
		int C=1;
		FOR (i,0,lg10) C*=10;
		// debug(C);
		FORN (i,a,b)
		{
			// debug(a);debug(b);
			int tmp=i,z=0;
			// debug(tmp);
			do
			{
				do
				{
					z=tmp%10;
					// debug(z);
					tmp/=10;
					tmp+=z*C;
				} while (!z);
				// debug(tmp);
				if (tmp>i && tmp>=a && tmp<=b)
					++ans;
			} while (tmp!=i);
		}
		printf("Case #%d: %lld\n",iz,ans);
	}
	return 0;
}