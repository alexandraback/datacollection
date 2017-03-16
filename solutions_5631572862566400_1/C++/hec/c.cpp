#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
#define popcount(n) (__builtin_popcountll(n))

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}

using namespace std;

using Edge=struct{int to,cost;};
using Graph=vector<vector<Edge>>;

vector<int> bfs(const Graph &g,int s){
	int n=g.size();
	vector<int> dist(n,-1);
	vector<int> ok(n,0);

	queue<int> q;
	dist[s]=0,q.push(s);
	while(!q.empty()){
		int v=q.front();q.pop();
		for(auto &e:g[v]){
			int nc=dist[v]+1; int nv=e.to;
			if(dist[nv]==-1){
				dist[nv]=nc;
				if(ok[v]==1 || e.cost==2) ok[nv]=1;
				q.push(nv);
			}
		}
	}

	rep(i,n) if(dist[i]!= -1 && ok[i]==0) dist[i]=-100;
	return dist;
}

int main(void){
	int T;
	cin >> T;	
	rep(testcase,1,T+1){
		int n;
		cin >> n;
		vector<int> bid(n);
		rep(i,n) cin >> bid[i],bid[i]--;

		int ans=0;
		rep(i,n){
			vector<int> visited(n);
			int cur=i,num=1;
			while(visited[cur]==0) visited[cur]=num++,cur=bid[cur];
			chmax(ans,num-visited[cur]);
		}

		Graph g(n);
		rep(i,n){
			int a=i,b=bid[a],w=1;
			if(bid[b]==a) w++;
			g[a].push_back({b,w});
			g[b].push_back({a,w});
		}

		vector<vector<int>> dist(n);
		rep(s,n) dist[s]=bfs(g,s);
	 	vector<int> comp(n,-1);	
	 	vector<int> cmax(n);
	 	int all=0;

	 	rep(s,n){
	 		if(comp[s]==-1) comp[s]=all;
	 		rep(t,n) if(dist[s][t]!=-1) comp[t]=all;
	 		all++;
	 	}
		
		rep(s,n)rep(t,n){
			if(comp[s]!=comp[t]) continue;
			chmax(cmax[comp[s]],dist[s][t]+1);
	 	}

	 	int cur=0;
	 	rep(i,all) cur+=cmax[i];
	 	chmax(ans,cur);

		cout << "Case #" << testcase << ": " << ans << endl;
	}
	return 0;
}