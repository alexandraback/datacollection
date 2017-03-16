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

struct tribe
{
	int w,e,s,ni,fd;
	int dd,dp,ds;
	tribe()
	{
		w=e=s=ni=dd=dp=ds=fd=0;
	}
	inline void getdata()
	{
		getint(fd);getint(ni);getint(w);getint(e);getint(s);
		getint(dd);getint(dp);getint(ds);
		w=w*2-1;
		e=e*2-1;
		dp*=2;
		return ;
	}
};

typedef pair<ii,int> i3;
typedef vector<i3> vi3;

vi Xs;
vi3 updata; // update data for the same day
tribe arr[1005];
int st[16000005]; // rmq
int prop[16000005];
int n,lastday,szXs;

inline int fidx(int &val,const vi &A) {return int(lower_bound(ALL(A),val)-A.begin());}
inline int fuidx(int &val,const vi &A) {return int(upper_bound(ALL(A),val)-A.begin());}

inline void propagate(int node,int val)
{
	st[node]=max(st[node],val);
	prop[node]=max(prop[node],val);
	return ;
}

void query(int node,int l,int r,int a,int b,int &ans)
{
	if (a<=l && r<=b)
	{
		ans=min(ans,st[node]);
		return ;
	}
	int mid=(l+r)>>1,A=node<<1,B=A|1;
	if (prop[node])
	{
		propagate(A,prop[node]);
		propagate(B,prop[node]);
		prop[node]=0;
	}
	if (mid>=a) query(A,l,mid,a,b,ans);
	if (mid+1<=b) query(B,mid+1,r,a,b,ans);
	return ;
}

void query(int L,int R,int &ans)
{
	L=fidx(L,Xs);
	R=fidx(R,Xs)-1;
	query(1,0,szXs-1,L,R,ans);
	return ;
}

void update(int node,int l,int r,int a,int b,int val)
{
	if (a<=l && r<=b)
	{
		propagate(node,val);
		return ;
	}
	int mid=(l+r)>>1,A=node<<1,B=A|1;
	if (prop[node])
	{
		propagate(A,prop[node]);
		propagate(B,prop[node]);
		prop[node]=0;
	}
	if (mid>=a) update(A,l,mid,a,b,val);
	if (mid+1<=b) update(B,mid+1,r,a,b,val);
	st[node]=min(st[A],st[B]);
	return ;
}

void update(int L,int R,int val)
{
	L=fidx(L,Xs);
	R=fidx(R,Xs)-1;
	update(1,0,szXs-1,L,R,val);
	return ;
}

int main()
{
	getint(n);
	FOR (tc,0,n)
	{
		int ans=0;
		RESET(st,0);
		RESET(prop,0);
		Xs.clear();
		updata.clear();

		printf("Case #%d: ",tc+1);
		getint(n);
		FOR (i,0,n) arr[i].getdata();
		FOR (i,0,n)
		{
			int cw,ce;
			cw=arr[i].w;ce=arr[i].e;
			FOR (j,0,arr[i].ni)
			{
				Xs.pb(cw);
				Xs.pb(ce+1);
				cw+=arr[i].dp;
				ce+=arr[i].dp;
			}
		}
		VSORT(Xs);
		Xs.erase(unique(ALL(Xs)),Xs.end());
		szXs=SIZE(Xs);

		priority_queue<attack> PQ;
		FOR (i,0,n)
			PQ.push(attack(arr[i].w,arr[i].e,arr[i].s,i,arr[i].fd,arr[i].ni));

		lastday=0;
		while (!PQ.empty())
		{
			attack now = take(PQ);
			if (now.day!=lastday)
			{
				FOR (j,0,SIZE(updata))
				{
					i3 &cur=updata[j];
					update(cur.ff.ff,cur.ff.ss,cur.ss);
				}
				updata.clear();
				lastday=now.day;
			}
			bool succ=0;
			int smallest=INF;
			query(now.wi,now.ei,smallest);
			succ=(smallest<now.si);
			if (succ) ++ans;
			updata.pb(mp(mp(now.wi,now.ei),now.si));
			now.last--;
			if (now.last>0)
			{
				tribe &cur=arr[now.id];
				PQ.push(attack(now.wi+cur.dp,now.ei+cur.dp,now.si+cur.ds,now.id,now.day+cur.dd,now.last));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}