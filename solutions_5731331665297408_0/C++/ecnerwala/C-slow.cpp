#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef pair<int, int> pii;
#define A first
#define B second

const int MAXN = 100;

int N, M;
pii z[MAXN];

vector<int> adj[MAXN];

//result
int S;
int order[MAXN];

//stores children
vector<int> children[MAXN];

//stores the current parent
bool vis[MAXN];

bool inStack[MAXN];

bool dfs(int cur = 1) {
	//for(int i = 0; i < cur; i++) cerr << order[i] << ' '; cerr << '\n';
	if(cur == N) return true;
	vector<int> path;
	for(int cur = 0; ;) {
		path.push_back(cur);
		if(children[cur].size() == 0) break;
		cur = children[cur].back();
	}
	//cerr << "path "; for(int i = 0; i < path.size(); i++) cerr << path[i] << ' '; cerr << '\n';
	for(int i = 0; i < N; i++) {
		if(vis[i]) continue;
		//cerr << i << '\n';
		for(int j = path.size() - 1; j >= 0; j--) {
			int p = path[j];
			if(binary_search(adj[i].begin(), adj[i].end(), p)) {
				vis[i] = true;
				children[p].push_back(i);
				order[cur] = i;
				if(dfs(cur + 1)) return true;
				children[p].pop_back();
				vis[i] = false;
				break;
			}
		}
	}
	return false;
}

void go() {
	if(N == 1) {
		order[0] = 0;
		return;
	}
	
	for(int i = 0; i < N; i++) sort(adj[i].begin(), adj[i].end());

	for(int i = 0; i < N; i++) vis[i] = false;
	vis[0] = true;
	
	dfs();

	for(int i = 0; i < N; i++) adj[i].clear();
	for(int i = 0; i < N; i++) children[i].clear();
}

int main() {
	int T; cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> N >> M;
		for(int i = 0; i < N; i++) {
			cin >> z[i].A;
			z[i].B = i + 1;
		}
		sort(z, z + N);
		for(int i = 0; i < M; i++) {
			int a, b; cin >> a >> b;

			//sketchy changing indices
			for(int i = 0; i < N; i++) {
				if(z[i].B == a) {
					a = i;
					break;
				}
			}
			for(int i = 0; i < N; i++) {
				if(z[i].B == b) {
					b = i;
					break;
				}
			}

			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		go();

		cout << "Case #" << t << ": ";
		for(int i = 0; i < N; i++) {
			cout << z[order[i]].A;
		}
		cout << '\n';
	}
}
