#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

struct Dinic {
	struct Edge {
		int from;
		int to;
		int flow;
	};

	vector<Edge> elist;
	vector<int> adj[N];
	int saiz;

	int ptr[N];
	int dist[N];

	int source,sink;
	int num;

	Dinic(int _s = 0,int _t = 0,int _num = 0) {
		source = _s;
		sink = _t;
		num = _num;
		reset();
	}

	void reset() {
		for(int i = 0 ; i <= num ; i++)
			adj[i].clear();
		elist.clear();
		saiz = 0;
	}

	void add_edge(int from,int to,int flow) {
		adj[from].push_back(saiz++);
		adj[to].push_back(saiz++);

		elist.push_back((Edge){from,to,flow});
		elist.push_back((Edge){to,from,0});
	}

	bool BFS() {
		for(int i = 0 ; i <= num ; i++)
			dist[i] = -1;
		queue<int> q;
		q.push(source);
		dist[source] = 0;

		while(!q.empty() && dist[sink] == -1) {
			int now = q.front();
			q.pop();
			for(int idx : adj[now]) {
				int to = elist[idx].to;
				int flow = elist[idx].flow;

				if(dist[to] == -1 && flow > 0) {
					dist[to] = dist[now] + 1;
					q.push(to);
				}
			}
		}

		return dist[sink] != -1;
	}

	int augment(int now,int f) {
		if(now == sink)
			return f;

		for(int &i = ptr[now] ; i < adj[now].size() ; i++) {
			int idx = adj[now][i];
			int to = elist[idx].to;
			int flow = elist[idx].flow;

			if(dist[to] == dist[now] + 1 && flow > 0) {
				int res = augment(to,min(f,flow));
				if(res > 0) {
					elist[idx].flow -= res;
					elist[idx ^ 1].flow += res;
					return res;
				}
			}
		}

		return 0;
	}

	int maxFlow() {
		int mf = 0;
		while(BFS()) {
			for(int i = 0 ; i <= num ; i++)
				ptr[i] = 0;
			int add = augment(source,(int)1e9);
			while(add > 0) {
				mf += add;
				add = augment(source,(int)1e9);
			}
		}
		return mf;
	} 
};

void make(vector<string> &v) {
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
}

int ID(vector<string> &v,string &str) {
	return lower_bound(v.begin(),v.end(),str) - v.begin();
}

vector<string> fr,bk;
Dinic network;
string a[N], b[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int t; cin >> t;
	for(int tc = 1 ; tc <= t ; tc++) {
		int n; cin >> n;

		fr.clear(); bk.clear();
		for(int i = 1 ; i <= n ; i++) {
			cin >> a[i] >> b[i];
			fr.push_back(a[i]);
			bk.push_back(b[i]);
		}

		make(fr);
		make(bk);

		int source = 0;
		int sink = fr.size() + bk.size() + 5;
		network = Dinic(source,sink,sink);

		for(int i = 1 ; i <= n ; i++) {
			int st = ID(fr,a[i]);
			int en = ID(bk,b[i]);
			st++;
			en += fr.size() + 1;
			network.add_edge(st,en,1);
		}

		for(int i = 0 ; i < fr.size() ; i++) {
			network.add_edge(source,i+1,1);
		}

		for(int i = 0 ; i < bk.size() ; i++) {
			network.add_edge(fr.size()+1+i,sink,1);
		}

		int mf = network.maxFlow();
		int ans = n - (fr.size() + bk.size() - mf);
		cout << "Case #" << tc << ": " << ans << "\n";
	}
	return 0;
}