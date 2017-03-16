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

#ifdef __WIN32__
	char getchar_unlocked() {return getchar();}
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

//using sokokaleb's template v2.8

string dp[8][8][1<<8];
bool dpb[8][8][1<<8];
string zip[8];
int adjMat[8][8];
int v,e;
vi adj[8];

bool cmp(const int &a,const int &b)
{
	return zip[a] > zip[b];
}

string f(int u,int par,int mask)
{
	string &ret = dp[u][par][mask];
	if (dpb[u][par][mask]) return ret;
	dpb[u][par][mask] = 1;
	if (mask == 0) return ret = zip[u];
	
	string dp2[1 << v];
	fill(dp2,dp2 + (1 << v),"a");
	dp2[0] = "";

	FOR (asem,0,SIZE(adj[u]))
	{
		int &i = adj[u][asem];
		if (adjMat[u][i] && i != u && mask&(1 << i))
		{
			int nmask = mask - (1 << i);
			for (int mmask = nmask; mmask; mmask = (mmask-1)&nmask)
			{
				string tmp = f(i,u,mmask);
				if (tmp == "a") continue;
				int zz = mmask + (1 << i);
				FORD (j,(1 << v) - 1,zz)
					if ((j&zz) == zz && dp2[j-zz] != "a")
						dp2[j] = min(min(tmp+dp2[j-zz],dp2[j-zz]+tmp),dp2[j]);
			}
			string tmp = f(i,u,0);
			if (tmp == "a") continue;
			FORD (j,(1 << v) - 1,1 << i)
				if (((j >> i)&1) && dp2[j-(1 << i)] != "a")
					dp2[j] = min(min(tmp+dp2[j-(1 << i)],dp2[j-(1 << i)]+tmp),dp2[j]);
		}
	}
	if (dp2[mask] == "a") return ret = "a";
	return ret = zip[u] + dp2[mask];
}

int main()
{
	getint(v);
	FORN (tc,1,v)
	{
		printf("Case #%d: ",tc);
		getint(v);getint(e);
		FOR (i,0,v)
			FOR (j,0,v)
				FOR (mask,0,1<<v)
				{
					dp[i][j][mask] = "";
					dpb[i][j][mask] = 0;
				}
		char x[10];
		FOR (i,0,v)
		{
			scanf("%s",x);
			zip[i] = x;
		}
		RESET(adjMat,0);
		FOR (i,0,e)
		{
			int a,b;
			getint(a);getint(b);
			--a;--b;
			adjMat[a][b] = adjMat[b][a] = 1;
		}

		FOR (i,0,v)
		{
			adj[i].clear();
			FOR (j,0,v)
				if (i != j && adjMat[i][j])
					adj[i].pb(j);
			sort(ALL(adj[i]),cmp);
		}
		string ans = "a";
		FOR (i,0,v)
			ans = min(ans,f(i,i,(1 << v) - 1 - (1 << i)));
		assert(SIZE(ans) == 5 * v);
		puts(ans.c_str());
	}
	return 0;
}