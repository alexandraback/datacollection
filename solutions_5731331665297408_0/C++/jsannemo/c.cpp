#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int codes[50];
vector<set<int>> adj;
vector<bool> visited;
vector<int> path;
vector<int> visiting;
int remaining;
int at;
int n;

void pop(){
    int city = path.back(); path.pop_back();
    visiting[city] = 0;
    at = path.back();
}

void enter(int city){
    printf("%d", codes[city]);
    visited[city] = true;
    remaining--;
    if(!path.empty()){
	adj[city].erase(path.back());
	adj[path.back()].erase(city);
    }
    path.push_back(city);
    visiting[city] = path.size();
    at = city;
}

bool dfs(int node, vector<bool>& seen, int lim){
    bool ans = visiting[node] != 0 && visiting[node] <= lim;
    seen[node] = true;
    if(!visited[node]){
	trav(it, adj[node]){
	    int u = *it;
	    if(!seen[u]){
		ans |= dfs(u, seen, lim);
	    }
	}
    }
    return ans;
}

void go(int start){
    path.clear();
    enter(start);
    while(remaining){
	int i = path.size() - 1;
	set<pair<int, pair<int, int>>> q;
	for(i = path.size() - 1; i >= 0; --i){
	    int node = path[i];
	    trav(it, adj[node]){
		int u = *it;
		if(!visited[u]) q.insert(make_pair(codes[u], make_pair(-i, u)));
	    }
	    if(i == 0) break;
	    bool canBacktrack = true;
	    trav(it, adj[node]){
		if(visited[*it]) continue;
		vector<bool> seen(n);
		seen[node] = true;
		bool could = dfs(*it, seen, i);
		canBacktrack &= could;
	    }
	    if(!canBacktrack) break;
	}
	pair<int, pair<int, int>> cur = *q.begin(); q.erase(q.begin());
	while((int)path.size() != (-cur.second.first) + 1) pop();
	enter(cur.second.second);
    }
}

bool solve(int tc){
    int m;
    scanf("%d%d", &n, &m);
    remaining = n;
    adj.assign(n, set<int>());
    visited.assign(n, false);
    visiting.assign(n, 0);
    for(int i = 0; i < n; ++i) scanf("%d", &codes[i]);
    for(int i = 0; i < m; ++i){
	int a, b;
	scanf("%d%d", &a, &b);
	a--; b--;
	adj[a].insert(b);
	adj[b].insert(a);
    }
    int minCode = codes[0], minVertex = 0;
    for(int i = 0; i < n; ++i){
	if(codes[i] < minCode){
	    minCode = codes[i];
	    minVertex = i;
	}
    }
    printf("Case #%d: ", tc);
    go(minVertex);
    printf("\n");
    return true;
}

int main(){
    int n = 0;
    if(!n) cin >> n;
    for(int i = 1; i <= n && solve(i); ++i);
}
