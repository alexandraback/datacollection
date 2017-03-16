#include <bits/stdc++.h>
using namespace std;

#define MAX 100001
#define NIL 0
#define INF (1<<28)
vector< int > G[MAX];
int n, m, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] ? G1[G[1---n]] ? G2[G[n+1---n+m]]
int ntest; 
map<string,int> mp;

bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<=n; i++) { 
        if(match[i]==NIL) { dist[i] = 0; Q.push(i); } 
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}
int hopcroft_karp() {
    int matching = 0, i;   // match[] is assumed NIL for all vertex in G
    memset(match,0,sizeof match);
     while(bfs())
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i)) matching++;
    return matching;
}
string s,t;
void solve(int test) {
   cout << "Case #" << test+1 << ": ";   
   cin >>n;
   
   for(int i=0; i<2*n+2; i++) G[i].clear();
   map<string,int> mpleft,mpright;
   
   vector<int> left,right;
   
   int cright=1,cleft= 1;
   for(int i=0; i<n; i++){
		cin >> s >> t;
		int u = mpleft[s];
		if(!u) u = mpleft[s] = cleft++;
		left.push_back(u);
		int v = mpright[t];
		if(!v) v = mpright[t] = cright++;
		right.push_back(v);
		
   }
   for(int i=0; i<left.size(); i++){
   		G[left[i]].push_back(right[i]+cleft);   	
   }
   int mx = hopcroft_karp() ;
   int cover = cleft+cright-2-mx;   
   cout << left.size() - cover << endl;
}

int main() {
    freopen("C-large.in", "r", stdin);
    freopen("test.out", "w", stdout);
    ios::sync_with_stdio(false);
    int ntest;
    cin >> ntest;
    for(int test=0; test< ntest; test++) {
        solve(test);
    }
    return 0;
}
