#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int n, k;
vector < vector<int> > g;
vector<int> mt;
vector<char> used;

bool try_kuhn (int v) {
	if (used[v])  {
        return false;
	}
	used[v] = true;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (mt[to] == -1 || try_kuhn (mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

int solve(int y) {
    g.clear();
    mt.clear();
    used.clear();
    int N; cin >> N;
    set < string > wds[2];
    vector < pair <string, string> > ed;
    for (int i = 0; i < N; ++i) {
        string s, t;
        cin >> s >> t;
        ed.push_back(make_pair(s,t));
        wds[0].insert(s);
        wds[1].insert(t);
    }
    n = wds[0].size();
    k = wds[1].size();
    g.resize(n + k, vector<int>());
    for (int i = 0; i < ed.size(); ++i) {
        g[distance(wds[0].begin(), wds[0].find(ed[i].first))].push_back(distance(wds[1].begin(), wds[1].find(ed[i].second)));
    }
    mt.assign (k, -1);
	for (int v = 0; v < n; ++v) {
		used.assign (n, false);
		try_kuhn (v);
	}
    int par = 0;
	for (int i = 0; i < k; ++i)
		if (mt[i] != -1)
			par += 1; // mt[i] + 1, i + 1

    if (N < 10) {
        sort(ed.begin(), ed.end());
        int p = 1;
        for (int i = 0; i < N; ++i) {
            p *= (i + 1);
        }
        int mb = 0;
        for (int i = 0; i < p; ++i) {
            set <string> s1, s2;
            int cb = 0;
            for (int i = 0; i < N; ++i) {
                if (s1.find(ed[i].first) != s1.end()) {
                    if (s2.find(ed[i].second) != s2.end()) {
                        cb += 1;
                    }
                }
                s1.insert(ed[i].first);
                s2.insert(ed[i].second);
            }
            mb = max(cb, mb);
            next_permutation(ed.begin(), ed.end());
        }
        if (mb != (N - (n + k - par))) {
            cout << mb << " " << (N - (n + k - par)) << " " << par << " " << n << " " << k << endl;
            for (int i = 0; i < N; ++i) {
                cout << ed[i].first << " " << ed[i].second << endl;
            }
            exit(0);
        }
    }
    return N - (n + k - par);
}

int main() {
#ifdef ALEXEY
    freopen("input", "r", stdin);
   freopen("output", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(7) << std::fixed;
#endif
    int t; cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": " << solve(i) << endl;
    }
    return 0;
}
