#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>

using namespace std;

#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)
#define sc(n)                   {char temp[4]; ss(temp); n=temp[0];}
#define INF						(int)1e9
#define LINF					(long long)1e18
#define EPS						1e-9
#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))
#define foreach(v,c)            for( typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define mp						make_pair
#define FF						first
#define SS						second
#define tri(a,b,c)				mp(a,mp(b,c))
#define XX						first
#define YY						second.first
#define ZZ						second.second
#define pb						push_back
#define fill(a,v) 				memset(a,v,sizeof a)
#define all(x)					x.begin(),x.end()
#define SZ(v)					((int)(v.size()))
#define DREP(a)					sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)			(lower_bound(all(arr),ind)-arr.begin())


#define debugger cerr
#define debug(args...)			{mdbg,args; debugger<<endl;}
#define PRINT_CONTAINER(o,v)    {if(v.size()==0) return o<<"{}"; o<<"{"; foreach(it,v) o<<*it<<" "; return o<<"\b}";}
struct multidebug {template<typename T> multidebug& operator , (const T &v) {debugger<<v<<" "; return *this;}} mdbg;
template<class T> ostream& operator << (ostream& o,const vector<T> &v) PRINT_CONTAINER(o,v)
template<class T> ostream& operator << (ostream& o,const set<T> &v) PRINT_CONTAINER(o,v)
template<class A,class B> ostream& operator << (ostream& o,const map<A,B> &v) PRINT_CONTAINER(o,v)
template<class A,class B> ostream& operator << (ostream& o,const pair<A,B> &p) {o<<"("<<p.first<<","<<p.second<<")"; return o;}
template<class T> void debugarr(T* v,int n) {debugger<<"{"; for(int i=0;i<n;i++) debugger<<v[i]<<" "; debugger<<"\b}"<<endl;}


typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<TRI> VT;




/*Main code begins now */
int testnum;
int K,N;
int keyCnt[205];
VI chest[205];
int opener[205];
int tcnt[205];

VI adj[1<<20];
VI radj[1<<20];

bool done[1<<20];

void dfs(int u)
{
	done[u]=true;;
	for(int i=0; i<adj[u].size(); i++)
	{
		int v=adj[u][i];
		if(!done[v]) dfs(v);
	}
}

bool ok(int cur)
{
	fill(done, false);
	dfs(cur);
	return done[(1<<N)-1];
}

void solve()
{
	for(int mask=0; mask<(1<<N); mask++)
	{
		adj[mask].clear();
		radj[mask].clear();
		for(int i=0; i<205; i++)
			tcnt[i] = keyCnt[i];
		for(int i=0; i<N; i++)
		{
			if(mask&(1<<i))
			{
				tcnt[opener[i]]--;
				for(int j=0; j<chest[i].size(); j++)
					tcnt[chest[i][j]]++;
			}
		}
		
		for(int i=0; i<N; i++) {
			if(mask & (1<<i)) continue;
			if(tcnt[opener[i]] == 0) continue;
			adj[mask].pb(mask + (1<<i));
			radj[mask].pb(i);
		}
	}
	
	printf("Case #%d:", testnum);
	
	if(!ok(0))
	{
		printf(" IMPOSSIBLE\n");
		return;
	}
	
	int cur = 0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<adj[cur].size(); j++)
		{
			int nmask = adj[cur][j];
			if(ok(nmask))
			{
				printf(" %d", radj[cur][j]+1);
				cur = nmask;
				break;
			}
		}
	}
	printf("\n");
		
}

bool input()
{
	s(K); s(N);
	fill(keyCnt,0);
	for(int i=0; i<K; i++) {
		int z; s(z);
		keyCnt[z]++;
	}
	for(int i=0; i<N; i++) {
		s(opener[i]);
		chest[i].clear();
		int k; s(k);
		for(int j=0; j<k; j++) {
			int z; s(z);
			chest[i].pb(z);
		}
	}
		
	return true;
}


int main()
{
	int T=1; s(T);
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		solve();
	}
}
