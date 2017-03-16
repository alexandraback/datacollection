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

const double eps=1e-8;

const int MN=1000*1000+1000;
vector<int> list[MN];
bool mark[MN];
int dis[MN];
int t,tc;
int rev(int a)
{
	int res=0;
	while (a)
		res=res*10+a%10,a/=10;
	return res;
}
void bfs(int a)
{
	queue<int> Q;
	Q.push(1);
	mark[1]=true;
	dis[1]=1;
	while (!Q.empty())
	{
		int x=Q.front();
		Q.pop();
		for (int & y:list[x]) if (!mark[y])
		{
			dis[y]=dis[x]+1;
			mark[y]=1;
			Q.push(y);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	for (int i=1;i<=1000*1000;i++)
	{
		list[i].push_back(i+1);
		list[i].push_back(rev(i));
	}
	cin>>t;
	bfs(1);
	while (t-->0)
	{
		int n;
		cin>>n;
		cout<<"Case #"<<++tc<<": "<<dis[n]<<endl;
	}
	return 0;
}
