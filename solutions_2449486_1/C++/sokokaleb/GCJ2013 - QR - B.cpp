#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <cstdlib>
#include <cctype>
#include <bitset>
#include <string>
#include <map>
#include <cassert>
#include <set>

#ifdef PEYEK 
	#define debugln {printf("----OK----\n");}
	#define debug(...) {printf(__VA_ARGS__);}
	#define debugs(...) {printf(":::::--->> ");printf(__VA_ARGS__);}
	#define TIME() printf("%.3lf\n",clock()/(double)CLOCKS_PER_SEC)
#else
	#define debugln {}
	#define debug(...) {}
	#define debugs(...) {}
	#define TIME() {}
#endif

#define FOR(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORN(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<=(_t);++(_i))
#define FORD(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i>=(_t);--(_i))
#define FORLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORNLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);(_i)<=(_t);++(_i))
#define FORDLL(_i,_n,_m) for(long long (_i)=(_n),_t=(_m);(_i)>=(_t);--(_i))
#define FOREACH(_i,_a) for (__typeof(_a.begin()) _i=_a.begin();_i!=_a.end();++_i)
#define RESET(_a,_value) memset(_a,_value,sizeof(_a))
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
 
using namespace std;
 
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

template <class T> T take(queue<T> &O) {T tmp=O.front();O.pop();return tmp;}
template <class T> T take(stack<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <class T> T take(priority_queue<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <class T> inline void getint(T &num)
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

void OPEN(string in="input.txt",string out="output.txt")
{
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
	return ;
}

//using sokokaleb's template v2.7

int dpH[105][105][2]; // 0 dari kiri, 1 dari kanan
int dpV[105][105][2]; // 0 dari atas, 1 dari bawah
int arr[105][105];
int r,c;
bool iso;

int main()
{
	getint(r);
	FOR (tc,0,r)
	{
		getint(r);getint(c);
		RESET(dpH,0);RESET(dpV,0);
		FOR (i,0,r)
			FOR (j,0,c)
				getint(arr[i][j]);
		FOR (i,0,r)
		{
			dpH[i][0][0]=arr[i][0];
			FOR (j,1,c)
				dpH[i][j][0]=MAX(arr[i][j],dpH[i][j-1][0]);
			dpH[i][c-1][1]=arr[i][c-1];
			FORD (j,c-2,0)
				dpH[i][j][1]=MAX(arr[i][j],dpH[i][j+1][1]);
		}
		FOR (j,0,c)
		{
			dpV[0][j][0]=arr[0][j];
			FOR (i,1,r)
				dpV[i][j][0]=MAX(arr[i][j],dpV[i-1][j][0]);
			dpV[r-1][j][1]=arr[r-1][j];
			FORD (i,r-2,0)
				dpV[i][j][1]=MAX(arr[i][j],dpV[i+1][j][1]);
		}
		iso=1;
		FOR (i,0,r)
			FOR (j,0,c)
			{
				int mxH=MAX(dpH[i][j][0],dpH[i][j][1]);
				int mxV=MAX(dpV[i][j][0],dpV[i][j][1]);
				iso&=(arr[i][j]>=mxH || arr[i][j]>=mxV);
			}
		printf("Case #%d: %s\n",tc+1,iso?"YES":"NO");
	}
	return 0;
}