// /\||/\||
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
#include <cassert>
#include <csignal>
#include <cmath>
#include <array>
#include <queue>
#include <stack>
#include <string>
#include <regex>
#include <set>
#include <map>
#include <tuple>
#include <list>
#include <utility>
#include <vector>
#include <bitset>
#include <deque>
#include <iomanip>
#include <complex>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <unordered_map>

using namespace std;
#ifdef _TEST
#define testdo(x) x
#else
#define testdo(x)
#endif
#define show(x) testdo(cerr<<((#x))<<" = "<<((x))<<" "<<endl)
#define bit(a,b) (((a)>>(b))&1)
#define gt(x,i) (get<((i))>(((x))))
#define ALL(x) ((x)).begin(),((x)).end()
#define Mt make_tuple
#define endl '\n'
#define bcnt(x) ((__builtin_popcount(x)))
#define bcntll(x) ((__builtin_popcountll(x)))
#define sqr(x) ((((x))*((x))))
#define fx(x) fixed<<setprecision(x)
#define list _list

template<class T> inline void smn(T &a,const T &b){if(b<a) a=b;}
template<class T> inline void smx(T &a,const T &b){if(b>a) a=b;}
template<class T> inline T gcd(T x,T y) { return y?gcd(y,x%y):x;}
namespace std{ template<class T,class U> struct hash<pair<T,U>> {
	inline size_t operator() (const pair<T,U> & p) const { return hash<T>()(p.first)*701+hash<U>()(p.second);}
};}

typedef long long ll;
typedef pair<int,int> pie;
typedef tuple<int,int,int> trip;
typedef complex<double> point;

const long double eps=1e-10l;

const int MN=1000*100;
int t,tc;
int n;
int d[MN],h[MN],m[MN];
pair<int,long double> list[MN];
int solve()
{
	if (n==1 && h[0]==1) return 0;
//	show("HI2");	
	if (n==1)
	{
		list[0]={d[0],1.l/m[0]};
		list[1]={d[1],1.l/(m[0]+1)};
	}
	else
	{
		list[0]={d[0],1.l/m[0]};
		list[1]={d[1],1.l/m[1]};	
	}
//	cerr<<fx(12)<<list[0].second<<" "<<list[1].second<<endl;
	if (n==2 && m[0]==m[1]) return 0;
//	show("HI");
	if (list[0].second<list[1].second)
		swap(list[0],list[1]);
	if (list[0].first>list[1].first)
	{
		long double time=(360-list[0].first+list[1].first)/360./(list[0].second-list[1].second);
		long double t2=(360-list[1].first)/360./list[1].second;
		cerr<<fx(6)<<time<<" "<<t2<<endl;
		if (time<=t2+eps) return 1;
		return 0;
	}
	long double time=(360+list[1].first-list[0].first)/360./(list[0].second-list[1].second);
	long double t2=(360-list[1].first)/360./list[1].second;
	cerr<<fx(6)<<time<<" "<<t2<<endl;	
	if (time<=t2+eps) return 1;
	return 0;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	while (t-->0)
	{
		cin>>n;
		for (int i=0;i<n;i++) cin>>d[i]>>h[i]>>m[i];
		int _=solve();
		cout<<"Case #"<<++tc<<": "<<_<<endl;
		
	}
	return 0;
}
