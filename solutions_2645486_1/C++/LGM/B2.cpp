//In the name of Allah
//
//
//////////////////////
// Program: 
// Written By Alireza Farhadi (LGM)
//////////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cctype>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <utility>
#include <vector>
#include <bitset>
#include <deque>
#include <iomanip>
#include <complex>
#include <fstream>
#include <sstream>
#include <map>
//#include <climits>
//#include <list>

using namespace std;

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define show(x) cerr<<((#x))<<" = "<<((x))<<" "<<endl
#define bit(a,b) (((a)>>(b))&1)
#define gcd __gcd
#define endl '\n'
#define bcnt(x) ((__builtin_popcount(x)))
#define sz(x) ((int((x).size())))
#define sqr(x) ((((x))*((x))))
#define fx(x) fixed<<setprecision(x)
#define fl endl<<flush

template<class T> inline void smn(T &a,const T &b){if(b<a) a=b;}
template<class T> inline void smx(T &a,const T &b){if(b>a) a=b;}
template<class T> inline T _rev(const T & a){T _=a; reverse(_.begin(),_.end()); return _;}

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pie;
typedef pie pii;
typedef complex<double> point;

const double eps=1e-8;
const ld leps=1e-14;
const int MN=10000+100;
#define int ll
int e,r,n,t;
int v[MN];
int now[MN];
int fen[10*MN];
int li=-1;
void add(int a,int b)
{
	for (int i=a;i<=n;i+=i&(-i))
		fen[i]+=b;
}
int fnd(int a)
{
	int res=0;
	for (int i=a;i>0;i-=i&(-i))
		res+=fen[i];
	return res;
}
struct cmp
{
	bool operator () (const int & a,const int & b)
	{
		if (v[a]!=v[b]) return v[a]>v[b];
		return a<b;
	}
};
set <int,cmp> me;
void nw(int un)
{
	int go=un;
			while (!me.empty() && go>0)
			{
				int v=*me.begin();
				if (v<=li)
				{
					me.erase(v);
					continue;
				}
				int t=fnd(v+1);
				int can=e+r*v-t;
				if (can>go)
				{
					now[v]+=go;
					add(v+1,go);
					break;
				}
				else
				{
					now[v]+=can;
					add(v+1,can);
					go-=can;
					me.erase(v);
					li=v;
				}
			}

}
 main()
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	for (int tc=1;tc<=t;tc++)
	{
		cout<<"Case #"<<tc<<": ";
		me.clear();
		memset(now,0,sizeof(now));
		memset(fen,0,sizeof(fen));
		li=-1;
		cin>>e>>r>>n;
		r=min(r,e);
		for (int i=0;i<n;i++) cin>>v[i];
		for (int i=0;i<n-1;i++)
		{
			me.insert(i);
			nw(r);
		}
		me.insert(n-1);
		nw(e);
		ll res=0;
		for (int i=0;i<n;i++)
			res+=now[i]*v[i];
		cout<<res<<endl;
	}
	return 0;
}
