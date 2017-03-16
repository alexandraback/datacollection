#include <bits/stdc++.h>
#define openfile(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
#define mpr std::make_pair
#define lg(x) (31-__builtin_clz(x))
#define lgll(x) (63-__builtin_clzll(x))
#define __count __builtin_popcount
#define __countll __builtin_popcountll
#define X first
#define Y second
#define mst(x) memset(x,0,sizeof(x))
#define mst1(x) memset(x,-1,sizeof(x))
#define ALL(c) (c).begin(),(c).end()
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<=n;i++)
#define FORit(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define pb push_back
#define RI(x) scanf("%d",&x)
#define RID(x) int x;RI(x)
using namespace std;
typedef long long LL;
typedef double LD;
typedef vector<int> VI;
typedef std::pair<int,int> PII;
template<class T>inline void maz(T &a,T b){if(a<b)a=b;}
template<class T>inline void miz(T &a,T b){if(a>b)a=b;}
template<class T>inline T abs(T a){return a>0?a:-a;}
const int N=1010, INF=1e9;
const LD EPS=1e-7;
int T;
int al[N];

int V;
int visit[N];
vector<int> edge[N];
vector<int> redge[N];
int ans = 0;
int now;
void init(){
	FOR(i,N) edge[i].clear();
	FOR(i,N) redge[i].clear();
	memset(visit,0,sizeof(visit));
	V = 0;
	ans = 0;
}
void addE(int x,int y){
	edge[x].pb(y);
	redge[y].pb(x);
}
int dep[N];

void dfs(int x){
	//printf("%d:%d ",x,dep[x]);
	visit[x] = V;
	for(auto nxt: edge[x]){
		if(visit[nxt] != V){
			dep[nxt] = dep[x]+1;
			dfs(nxt);
		} else{
			if(nxt == now ){
				ans = max(ans, dep[x]+1);
			}
		}	
	}
}


int dep2[N];
int dfs2(int x,int ban){
	//printf("%d:%d ",x,dep2[x]);
	int res = dep2[x];
	visit[x] = V;
	for(auto nxt :redge[x]){
		if(visit[nxt] != V && nxt != ban){
			dep2[nxt] = dep2[x]+1;
			res = max(dfs2(nxt, ban), res);
		}
	}
	return res;
}
int run(int a,int b){
	dep2[a] = 0;
	V++;
	int tmp  =dfs2(a,b);//puts("");
	//printf("%d %d %d\n",a,b, tmp);
	return tmp;
}
int solve(int a,int b){
	return run(a,b)+run(b,a) +2;
}


int main(){
	int t = 0;
	scanf("%d",&T);
	while(t++ < T){
		init();
		RID(n);
		FOR(i,n){
			RID(nxt);
			addE(i+1, nxt);
			al[i+1] = nxt;
		}
		FOR(i,n){
			V++;
			now = i+1;
			dep[i+1] = 0;
			dfs(i+1);//puts("");
		}
		set<int> seen;
		int res = 0;
		FOR1(i,n){
			if(al[al[i]] == i){
				if(seen.count(i)) continue;
				else{
					seen.insert(i);
					seen.insert(al[i]);
					res += solve(i, al[i]);
				}
			}
		}

		printf("Case #%d: ",t);	
		printf("%d\n",max(ans,res));
		//printf("%d\n",res);
	}
}
