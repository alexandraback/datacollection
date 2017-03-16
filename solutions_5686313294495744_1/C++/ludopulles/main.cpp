#include <bits/stdc++.h>

using namespace std;

#define MAXN 10000

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream &out, const pii &a) { return out << '(' << a.first << ", " << a.second << ')'; }
istream& operator>>(istream &in, pii &a) { return in >> a.first >> a.second; }

string s[MAXN], t[MAXN];
map<string, int> os, ot;

int nl[MAXN], nr[MAXN];

bool valid[MAXN], validL[MAXN], validR[MAXN];
vector<int> listL[MAXN], listR[MAXN];

//int order[1 << MAXN];

int popcount(int num)
{
	int ret = 0;
	while (num > 0) {
		if (num & 1) ret++;
		num >>= 1;
	}
	return ret;
}

#define MAXL 10000
#define MAXR 10000

bool vis[MAXR]; // vis[rightnodes]
int par[MAXR]; // par[rightnode] = leftnode
vector<int> adj[MAXL]; // adj[leftnode][i] = rightnode

bool match(int cur) {
	for (auto it = adj[cur].begin(); it != adj[cur].end(); ++it) {
		if (vis[*it]) continue;
		vis[*it] = true;
		if (par[*it] == -1 || match(par[*it])) {
			par[*it] = cur;
			return true;
		}
	}
	return false;
}

int maxMatching(int nodesLeft) {
	int matches = 0;
	for (int i = 0; i < nodesLeft; i++) {
		memset(vis, false, sizeof(vis));
		if (match(i)) matches++;
	}
	return matches;
}

void run()
{
	os.clear();
	ot.clear();

	int cntl = 0, cntr = 0;

	cerr << "Starting" << endl;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> t[i];
		if (os.find(s[i]) == os.end()) os[s[i]] = cntl++;
		if (ot.find(t[i]) == ot.end()) ot[t[i]] = cntr++;

		nl[i] = os[s[i]];
		nr[i] = ot[t[i]];

		for (int j = 0; j < i; j++) {
			if (nl[i] == nl[j] && nr[i] == nr[j]) {
				cerr << "Duplicates found" << endl;
			}
		}

		// cout << nl[i] << " " << nr[i] << endl;
	}

    int nodesLeft = cntl;
    int nodesRight = cntr;

	fill_n(vis, nodesRight, false);
	fill_n(par, nodesRight, -1);
	for (int i = 0; i < nodesLeft; i++) {
		adj[i].clear();
	}
	for (int i = 0; i < n; i++) {
		adj[nl[i]].push_back(nr[i]);
	}

	cerr << "matching" << endl;

	int maxMatch = maxMatching(nodesLeft);

	int needed = nodesLeft + nodesRight - maxMatch;
	cout << (n - needed);
}

/*
void run()
{
	os.clear();
	ot.clear();

	int cntl = 0, cntr = 0;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> t[i];
		if (os.find(s[i]) == os.end()) os[s[i]] = cntl++;
		if (ot.find(t[i]) == ot.end()) ot[t[i]] = cntr++;

		nl[i] = os[s[i]];
		nr[i] = ot[t[i]];

		for (int j = 0; j < i; j++) {
			if (nl[i] == nl[j] && nr[i] == nr[j]) {
				cerr << "Duplicates found" << endl;
			}
		}

		// cout << nl[i] << " " << nr[i] << endl;
	}

	for (int i = 0; i < (1 << n); i++) {
		order[i] = i;
	}
	sort(order, order + (1 << n), [] (int a, int b) -> bool {
		return popcount(a) < popcount(b);
	});

	for (int idx = 0; idx < 1 << n; idx++) {
		int i = order[idx];

		// init
		fill_n(valid, n, false);
		fill_n(validL, n, false);
		fill_n(validR, n, false);
		for (int j = 0; j < n; j++) {
			listL[j].clear();
			listR[j].clear();
		}

		queue<int> q;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				valid[j] = true;
				q.push(j);
			} else {
				listL[nl[j]].push_back(j);
				listR[nr[j]].push_back(j);
			}
		}

		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			validL[nl[cur]] = validR[nr[cur]] = true;
			for (int j : listL[nl[cur]]) {
				if (validL[nl[j]] && validR[nr[j]] && !valid[j]) {
					valid[j] = true;
					q.push(j);
				}
			}
			for (int j : listR[nr[cur]]) {
				if (validL[nl[j]] && validR[nr[j]] && !valid[j]) {
					valid[j] = true;
					q.push(j);
				}
			}
		}

		bool correct = true;
		for (int j = 0; j < n; j++) {
			if (!valid[j]) correct = false;
		}

		if (correct) {
			cout << (n - popcount(i));
			return;
			// cout << i << "(" << popcount(i) << ") is possible" << endl;
		}
	}
	cout << -1;
}
*/

int main()
{
#ifdef LOCAL
    assert(freopen("input2.txt", "r", stdin));
    freopen("output2.txt", "w", stdout);
#else
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#endif // LOCAL

	int n;
	cin >> n;
	for (int tc = 1; tc <= n; tc++) {
		cout << "Case #" << tc << ": ";
		run();
		cout << endl;
	}

    return 0;
}
