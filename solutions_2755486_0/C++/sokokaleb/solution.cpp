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

#define OFF 20000

struct attack
{
	int wi,ei,si,id,day,last;
	attack()
	{
		wi=ei=si=id=day=last=0;
	}
	attack(int ww,int ee,int ss,int idd,int dd,int lastt):wi(ww),ei(ee),si(ss),id(idd),day(dd),last(lastt){}
	bool operator < (const attack &A) const {return day>A.day;}
};

int h[40000],nh[40000];
int n,di,wi,ei,id,si,ni;
int ds[11],dp[11],dd[11];

int main()
{
	getint(n);
	FOR (tc,0,n)
	{
		RESET(h,0);
		RESET(nh,0);
		printf("Case #%d: ",tc+1);
		getint(n);
		priority_queue<attack> PQ;
		FOR (i,0,n)
		{
			getint(di);getint(ni);getint(wi);getint(ei);getint(si);
			getint(dd[i]);getint(dp[i]);getint(ds[i]);
			dp[i]*=2;
			wi=2*wi-1;
			ei=2*ei-1;
			wi+=OFF;ei+=OFF;
			PQ.push(attack(wi,ei,si,i,di,ni));
		}
		int ans=0,lastday=0;
		while (!PQ.empty())
		{
			attack now = take(PQ);
			debug("DAY %d:\n",now.day);
			debug("TRIBE %d, from %d to %d with %d power\n",now.id+1,now.wi-OFF,now.ei-OFF,now.si);
			if (now.day!=lastday)
			{
				FOR (i,0,40000)
					h[i]=max(h[i],nh[i]);
				RESET(nh,0);
				FOR (i,-1*2-1,11*2-1)
					debug(" %4d",h[i+OFF]);
				debug("\n");
				lastday=now.day;
			}
			bool succ=0;
			FORN (i,now.wi,now.ei)
			{
				succ|=(h[i]<now.si);
				nh[i]=max(max(h[i],nh[i]),now.si);
			}
			if (succ) ++ans;
			debug("\tans it's %s\n","not succeed"+(succ?4:0));
			--now.last;
			if (now.last>0)
			{
				int &id=now.id;
				PQ.push(attack(now.wi+dp[id],now.ei+dp[id],now.si+ds[id],id,now.day+dd[id],now.last));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}