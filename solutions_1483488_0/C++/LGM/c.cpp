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

template<class T> inline void smn(T &a,const T &b){if(b<a) a=b;}
template<class T> inline void smx(T &a,const T &b){if(b>a) a=b;}
template<class T> inline T rev(const T & a){T _=a; reverse(_.begin(),_.end()); return _;}

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pie;

const double eps=1e-9;
const ld leps=1e-14;
ll res;
int list[3000000];
const int INF=(1u<<31)-1;
int t,a,b;
int d[100];
int p;
void chk(int a)
{
	p=0;
	int mn=INF;
	while (a)
		d[p++]=a%10,a/=10;
	reverse(d,d+p);
	for (int i=0;i<p;i++)
	{
		int now=0;
		int pt=i;
		for (int j=0;j<p;j++)
		{
			now=(10*now)+d[pt];
			pt++;
			if (pt==p)
				pt=0;
		}
		smn(mn,now);
	}
	res+=list[mn];
	list[mn]++;
}
int main(int argc,char * argv[])
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	for (int tc=1;tc<=t;tc++)
	{
		res=0;
		cin>>a>>b;
		memset(list,0,sizeof(list));
		for (int i=a;i<=b;i++) chk(i);
		cout<<"Case #"<<tc<<": "<<res<<endl;
	}
	return 0;
}
