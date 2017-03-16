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
typedef vector<bool> VB;


/**
* Team Proof
* Strongly Connected Components
* 
* Initialize deg[] and adjList[][] before calling SCC()
* All numberings are 0-based
*/

#include<algorithm>
#include<cstring>
using namespace std;

const int maxNode = 200;
int deg[maxNode];
int adjList[maxNode][maxNode*2];
int adjChest[maxNode][maxNode*2];

int component[maxNode];			// what is component number of vertex v
int compSize[maxNode];			// how many vertices in comp c
int totalSCC;					// how many total components found
bool adjComp[maxNode][maxNode];	// adjacency matrix for components
	
int dfsNum[maxNode], minDfsNum[maxNode], dfsNext;
int currentComp[maxNode], currentSize;
bool inComp[maxNode];

void dfs(int u)
{
	if( dfsNum[u] >= 0) return;
	
	minDfsNum[u] = dfsNum[u] = dfsNext++;
	
	currentComp[currentSize++] = u;	// Insert u in current component
	inComp[u] = true;

	for(int i = 0; i < deg[u]; i++)
	{
		int v = adjList[u][i];
		dfs(v);
		
		if( inComp[v] )		// Check is only for cross edges
			minDfsNum[u] = min (minDfsNum[u], minDfsNum[v] );	
	}

	if( minDfsNum[u] == dfsNum[u] )		// New component found 
	{
		while(true)
		{
			int v = currentComp[--currentSize];
			component[v] = totalSCC;
			compSize[totalSCC] ++;
			inComp[v] = false;
			if( u == v) break;
		}
		totalSCC ++;
	}
}

void scc(int N)
{

	memset( dfsNum, -1, sizeof dfsNum);	// dfsNum also works as visited array
	memset( compSize, 0, sizeof compSize);
	memset( inComp, false, sizeof inComp);
	
	currentSize = dfsNext= totalSCC = 0;
	
	for( int i = 0; i < N; i++ )
		if( dfsNum[i] < 0)	dfs( i );
		
	/*
	for(int i=0;i<N;i++)
		for(int j=0;j<deg[i];j++)
			if(component[i] != component[ adjList[i][j] ])
				adjComp[ component[i] ][ component[adjList[i][j]] ] = true;
	*/
}


/*Main code begins now */
int testnum;

int N;
const int nkeys=200;
int opener[200];
VI chest[200];

struct Checker
{
	int have[nkeys];
	int need[nkeys];
	bool used[200];
	int usedCount;
	
	Checker(VI &count, VB &_used) {
		fill(need,0);
		usedCount = 0;
		for(int i=0;i<nkeys;i++) {
			have[i] = count[i];
		}
		
		for(int i=0; i<N; i++) {
			used[i] = _used[i];
			if(!used[i]) {
				need[opener[i]]++;
			} else {
				usedCount++;
			}
		}
		//debug("checker inited");
	}
	
	void openChest(int u) {
		//debug("openChest", u+1);
		assert(!used[u]);
		used[u] = true;
		usedCount++;
		
		assert(have[opener[u]]);
		have[opener[u]]--;
		need[opener[u]]--;
		for(int i=0; i<chest[u].size(); i++) {
			have[chest[u][i]]++;
		}
	}
	
	bool doGreedy() {
		//debug("greedy");
		bool found = false;
		for(int i=0; i<N; i++) {
			if(!used[i] && have[opener[i]] >= need[opener[i]]) {
				openChest(i);
				found = true;
			}
		}
		return found;
	}
	
	bool findLoop() {
		//debug("findLoop");
		fill(deg,0);
		for(int i=0; i<N; i++) {
			if(used[i]) {
				continue;
			}
			
			int u = opener[i];
			for(int j=0; j<chest[i].size(); j++) {
				int v = chest[i][j];
				adjList[u][deg[u]] = v;
				adjChest[u][deg[u]] = i;
				deg[u]++;
			}
		}
		
		//debug("before scc");
		for(int i=0; i<nkeys; i++) {
			if(deg[i]==0) continue;
			//debug("key",i);
			//debugarr(adjList[i], deg[i]);
		}
		scc(nkeys);
		//debug("after scc");
		
		bool found = false;
		for(int i=0; i<nkeys; i++) {
			for(int j=0; j<deg[i]; j++) {
				int u = adjList[i][j];
				//debug("pairs",i,u);
				if(component[i] == component[u] && have[i]>0) {
					int c = adjChest[i][j];
					if(!used[c]) {
						openChest(adjChest[i][j]);
					}
					found = true;
					break;
				}
			}
			if(found) break;
		}
		return found;
	}
		
		
	
	
	bool isFeasible() {
		while(true) {
			//debug("isFeasible");
			//debugarr(have, 10);
			//debugarr(need, 10);
			if(usedCount==N) {
				//debug("FEASIBLE");
				return true;
			}
			if(doGreedy()) continue;
			if(findLoop()) continue;
			//debug("NOT FEASIBLE");
			return false;
		}
		assert(false);
	}
	
};
		

VI keyCount;
VB doneChest;

void openChest(int u) {
	assert(!doneChest[u]);
	int key = opener[u];
	assert(keyCount[key]);
	
	doneChest[u] = true;
	keyCount[key]--;
	for(int i=0; i<chest[u].size(); i++) {
		keyCount[chest[u][i]]++;
	}
}

void closeChest(int u) {
	assert(doneChest[u]);
	int key = opener[u];
	doneChest[u] = false;
	keyCount[key]++;
	for(int i=0; i<chest[u].size(); i--) {
		keyCount[chest[u][i]]--;
	}
}
	

void solve()
{
	debug("Case done", testnum);
	Checker checker = Checker(keyCount, doneChest);
	if(!checker.isFeasible()) {
		printf("Case #%d: IMPOSSIBLE\n", testnum);
		return;
	}
	//debug("initial check passed");
	
	printf("Case #%d:", testnum);
	for(int i=0; i<N; i++) {
		if(i%10 == 0) debug(testnum, N, i);
		for(int j=0; j<N; j++) {
			if(doneChest[j]) continue;
			int u = opener[j];
			if(keyCount[u] == 0) continue;
			
			openChest(j);
			
			checker = Checker(keyCount, doneChest);
			if(checker.isFeasible()) {
				printf(" %d", j+1);
				break;
			}
			
			closeChest(j);
		}
	}
	printf("\n");
	
}

bool input()
{
	int k; s(k);
	s(N);
	
	keyCount = vector<int>(nkeys,0);
	doneChest = vector<bool>(N,false);
	
	for(int i=0; i<k; i++) {
		int z; s(z);
		keyCount[z-1]++;
	}
	
	for(int i=0; i<N; i++) {
		chest[i].clear();
		int ti, ki;
		s(ti); s(ki);
		opener[i] = ti-1;
		for(int j=0; j<ki; j++) {
			int z; s(z);
			chest[i].pb(z-1);
		}
	}
			
	
	return true;
}


int main()
{
	int T; s(T);
	for(testnum=1;testnum<=T;testnum++)
	{
		if(!input()) break;
		solve();
	}
}
