#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

class NetworkFlow
{
public:
	struct Edge 
	{
		int target, capacity, flow;
		Edge *reverse;

		int residualCapacity() const { return capacity - flow; }

		void push(int amt)
		{
			flow += amt;
			reverse->flow -= amt;
		}
	};

	NetworkFlow(int V) : V(V)
	{
		adj.resize(V);
	}

	~NetworkFlow()
	{
		for(int i=0; i < V; i++)
			for(size_t j=0; j < adj[i].size(); j++)
				delete adj[i][j];
	}

	void addEdge(int u, int v, int capacity)
	{
		Edge *uv = new Edge(), *vu = new Edge();

		uv->target = u;
		uv->capacity = capacity;
		uv->flow = 0;
		uv->reverse = vu;

		vu->target = v;
		vu->capacity = 0;
		vu->flow = 0;
		vu->reverse = uv;

		adj[u].push_back(uv);
		adj[v].push_back(vu);
	}

	int getMaximumFlow(int source, int sink)
	{
		int totalFlow = 0;

		while(true)
		{
			vector<pair<int, Edge*>> parent(V, {-1, nullptr});

			queue<int> q;
			parent[source].first = source;
			q.push(source);

			while(!q.empty() && parent[sink].first == -1)
			{
				int here = q.front();
				q.pop();

				for(size_t i=0; i < adj[here].size(); i++)
				{
					Edge *there = adj[here][i];
					int v = there->reverse->target;

					if(there->residualCapacity() > 0 && parent[v].first == -1)
					{
						q.push(v);
						parent[v] = {here, there};
					}
				}
			}

			if(parent[sink].first == -1)
				break;

			int amount = INF;
			for(int p = sink; p != source; p = parent[p].first)
				amount = min(amount, parent[p].second->residualCapacity());

			totalFlow += amount;
			for(int p = sink; p != source; p = parent[p].first)
			{
				Edge *uv = parent[p].second;
				uv->push(amount);
			}

		}

		return totalFlow;
	}

private:
	int V;
	vector<vector<Edge *>> adj;

};

int N;
vector<pair<int, int>> a;
map<int, int> b, c;
map<pair<int, int>, int> d;
int idx;
int cache[17][1 << 16];

int solve(int pos, int mask, long long maskp, long long maskq)
{
	if(pos == N)
		return 0;

	int& ans = cache[pos][mask];
	if(ans != -1)
		return ans;

	ans = 0;
	if(b[a[pos].first] > 1 && c[a[pos].second] > 1 && d[a[pos]] == 1)
	{
		if((maskp & (1LL << a[pos].first)) == 0 && (maskq & (1LL << a[pos].second)) == 0)
			ans = 1 + solve(pos + 1, mask | (1 << pos), maskp | (1LL << a[pos].first), maskq | (1LL << a[pos].second));
	}
	ans = max(ans, solve(pos + 1, mask, maskp, maskq));
	return ans;
}

int main()
{
	int T;
	cin >> T;

	for(int tc=1; tc <= T; tc++)
	{
		map<string, int> ck, ck2;
		a.clear();
		idx = 1;

		cin >> N;
		for(int i=0; i < N; i++)
		{
			string p, q;
			cin >> p >> q;
			if(ck.count(p) == 0)
				ck[p] = idx++;
			if(ck2.count(q) == 0)
				ck2[q] = idx++;

			a.push_back({ck[p], ck2[q]});
		}

		b = map<int, int>();
		c = map<int, int>();
		d = map<pair<int, int>, int>();
		for(int i=0; i < N; i++)
		{
			b[a[i].first]++;
			c[a[i].second]++;
			d[a[i]]++;
		}
		memset(cache, -1, sizeof(cache));
		printf("Case #%d: %d\n", tc, solve(0, 0, 0, 0));
	}

	return 0;
}