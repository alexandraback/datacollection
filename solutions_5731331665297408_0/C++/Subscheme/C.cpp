#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define fo(i,n) for(int i=0,_n=(n); i<_n; ++i)
#define range(i,a,b) for(int i=(a),_n=(b); i<_n; ++i)
typedef pair<int,int> pr;

const int oo = 100000000;
vector<int> number, zip, from;
vector<bool> seen, nseen;
vector<vector<int> > adj;

void dfs(int i) {
	if(seen[i]) return;
	seen[i] = true;
	fo(j,adj[i].size()) dfs(adj[i][j]);
}

void reachDFS(int i) {
	if(nseen[i]) return;
	nseen[i] = true;
	fo(j,adj[i].size()) reachDFS(adj[i][j]);
}

bool canReachFrom(int i) {
	fo(j, nseen.size()) nseen[j] = seen[j];
	while(i != -1) {
		nseen[i] = false;
		reachDFS(i);
		i = from[i];
	}
	fo(j, nseen.size()) if(!nseen[j]) {
		return false;
	}
	return true;
}

void f(int i, int parent_min, int parent) {
	seen[i] = true;
	from[i] = parent;
	number.push_back(zip[i]);
	int my_min = oo;
	fo(j, adj[i].size()) {
		int val = zip[adj[i][j]];
		if(val < my_min) {
			my_min = val;
		}
	}
		
	int adj_min = my_min;
	if(adj_min < 0) adj_min += oo;
	
	vector<pr> children;
	fo(j, adj[i].size()) if(!seen[adj[i][j]]) children.push_back(pr(zip[adj[i][j]], adj[i][j]));
	sort(children.begin(), children.end());
	children.push_back(pr(oo, 0));

	fo(j, children.size() - 1) if(!seen[children[j].second]) {
		if(zip[children[j].second] > parent_min && canReachFrom(parent)) return;
		f(children[j].second, min(children[j+1].first, parent_min), i);
	}
}

int main() {
	int T;
	cin >> T;
	fo(t,T) {
		number.clear();
		int n, m;
		cin >> n >> m;
		
		zip.resize(n);
		fo(i,n) cin >> zip[i];
		
		seen.resize(n);
		nseen.resize(n);
		fo(i,n) seen[i] = false;

		adj.resize(n);
		fo(i,n) adj[i].clear();

		from.clear();
		from.resize(n);

		fo(i,m) {
			int a, b;
			cin >> a >> b;
			--a; --b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		// This is completely unnecessary... but not rewriting it >_>
		vector<pr> starts;
		fo(i,n) starts.push_back(pr(zip[i], i));
		sort(starts.begin(), starts.end());
		fo(i,n) {
			fo(j,n) seen[j] = false;
			dfs(starts[i].second);
			bool poss = true;
			fo(j,n) if(!seen[j]) poss = false;
			if(poss) {
				fo(j,n) seen[j] = false;
				f(starts[i].second, oo, -1);
				break;
			}
		}

		if(number.size() != n) {
			cout << "FUCK!\n";
			cout << "Case " << t+1 << ": \n\n";
			cout << n << ' ' << number.size() << '\n';
			fo(i,number.size()) cout << number[i] << ' ';
			cout << endl << endl;
			fo(i,n) cout << i+1 << ": " << zip[i] << endl;
			cout << endl;
			fo(i,n) {
				cout << i+1 << ": ";
				fo(j,adj[i].size()) cout << adj[i][j]+1 << ' ';
				cout << endl;
			}
			cout << endl;
			return 1;
		}

		cout << "Case #" << t + 1 << ": ";
		fo(i,n) cout << number[i];
		cout << '\n';
	}

}