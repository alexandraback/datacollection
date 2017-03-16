#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

// Code from https://web.stanford.edu/~liszt90/acm/notebook.html#file5
// This code performs maximum bipartite matching.
//
// Running time: O(|E| |V|) -- often much faster in practice
//
//   INPUT: w[i][j] = edge between row node i and column node j
//   OUTPUT: mr[i] = assignment for row node i, -1 if unassigned
//           mc[j] = assignment for column node j, -1 if unassigned
//           function returns number of matches made


typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
    for (int j = 0; j < w[i].size(); j++) {
	if (w[i][j] && !seen[j]) {
	    seen[j] = true;
	    if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
		mr[i] = j;
		mc[j] = i;
		return true;
	    }
	}
    }
    return false;
}

int BipartiteMatching(const VVI &w) {
    VI mr(w.size(), -1), mc(w[0].size(), -1);
  
    int ct = 0;
    for (int i = 0; i < w.size(); i++) {
	VI seen(w[0].size());
	if (FindMatch(i, w, mr, mc, seen)) ct++;
    }
    return ct;
}

int m[2], n;
set<string> S[2];
map<string, int> M[2];
string s[1005][2];

int main() {
    int tt;
    cin >> tt;
    for (int t = 0 ; t < tt ; t ++) {
	cin >> n;
	S[0].clear();
	S[1].clear();
	M[0].clear();
	M[1].clear();
	for (int i = 0 ; i < n ; i ++) {
	    for (int j = 0 ; j < 2 ; j ++) {
		cin >> s[i][j];
		S[j].insert(s[i][j]);
	    }
	}
	for (int j = 0 ; j < 2 ; j ++) {
	    m[j] = 0;
	    for (string t : S[j]) {
		M[j][t] = (m[j] ++);
	    }
	}
	VVI w;
	for (int i = 0 ; i < m[0] ; i ++) {
	    VI v(m[1]);
	    for (int j = 0 ; j < m[1] ; j ++) v[j] = 0;
	    w.push_back(v);
	}
	for (int i = 0 ; i < n ; i ++) {
	    w[M[0][s[i][0]]][M[1][s[i][1]]] = 1;
	}
	int ec = m[0] + m[1] - BipartiteMatching(w);
	cout << "Case #" << t + 1 << ": " << n - ec << endl;
    }
    return 0;
}
