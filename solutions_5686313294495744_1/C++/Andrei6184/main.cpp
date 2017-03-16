#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector < vector<int> > g;
vector<int> mt;
vector<char> used;

bool try_kuhn (int v) {
	if (used[v])  return false;
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (mt[to] == -1 || try_kuhn (mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}


int main() {
    freopen("C-large.in", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;
        vector<string> v1, v2;
        g.clear();
        for (int i = 0; i < N; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            if (find(v1.begin(), v1.end(), s1) == v1.end()) {
                    v1.push_back(s1);
                    g.push_back(vector<int>());
            }
            int i1 = find(v1.begin(), v1.end(), s1) - v1.begin();
            if (find(v2.begin(), v2.end(), s2) == v2.end()) v2.push_back(s2);
            int i2 = find(v2.begin(), v2.end(), s2) - v2.begin();
            g[i1].push_back(i2);
        }
        n = v1.size();
        k = v2.size();

        mt.assign (k, -1);
        for (int v = 0; v < n; ++v) {
            used.assign (n, false);
            try_kuhn (v);
        }
        int p = 0;
        for (int i=0; i<k; ++i)
            p += (mt[i] != -1);
        int ans = N - n - k + p;
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
