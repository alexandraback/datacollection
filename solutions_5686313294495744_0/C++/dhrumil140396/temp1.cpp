#include <bits/stdc++.h>
#define rf freopen("input1.txt", "r", stdin)
#define wf freopen("output1.txt", "w", stdout)
using namespace std;

const int INF = 100000000;
const int MAX = 2500;

struct edge{
	int to, cap, rev;
};

vector < edge > adj[MAX];
bool vis[MAX];
 
void edgeaddthai(int from, int to, int cap){
	adj[from].push_back((edge){to, cap, (int) adj[to].size()});
	adj[to].push_back((edge){from, 0, (int) adj[from].size() - 1});
}

int dfs(int v,int t,int f){ 
	if(v == t) return f;
	vis[v] = true;
	for(int i = 0; i < adj[v].size(); i++){
		edge &e = adj[v][i];
		if(!vis[e.to] && e.cap > 0){ 
			int d = dfs(e.to, t, min(f, e.cap));
			if(d > 0){ 
				e.cap -= d;
				adj[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int flowmax(int s, int t){ 
	int flow = 0;
	while(true){ 
		memset(vis, 0, sizeof(vis));
		int f = dfs(s, t, INF);
		if(!f) return flow;
		flow += f;
	}
}

 
int main(){
	rf, wf;
	ios :: sync_with_stdio(false);
	int t; cin >> t;
	for(int qq = 1; qq <= t; qq++){
		int n;
		string s[1005], t[1005]; 
		cin >> n;
		map < string, int > left_p, right_p;
		for(int i = 0; i < n; i++){
			cin >> s[i] >> t[i];
			left_p[s[i]] = 0;
			right_p[t[i]] = 0;
		}
		int mc = 0, nx = 1;
		for(map < string, int > ::iterator it = left_p.begin(); it != left_p.end(); it++){
			edgeaddthai(2098, nx, 1);
			it -> second = nx++;
		}
		mc += nx - 1;
		nx = 1;
		for(map < string,int > ::iterator it = right_p.begin(); it != right_p.end(); it++){
			edgeaddthai(1050 + nx, 2099, 1);
			it -> second = nx++;
		}
		mc += nx - 1;
		for(int i = 0; i < n; i++){
			edgeaddthai(left_p[s[i]], right_p[t[i]] + 1050, 1);
		}
		mc -= flowmax(2098,2099);
		cout << "Case #" << qq << ": ";
		cout << n - mc << '\n';
	}
}

