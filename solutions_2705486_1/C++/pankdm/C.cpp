#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <queue>
#include <assert.h>
#include <deque>
#include <string.h>
#include <fstream>

using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

typedef vector <int> vi;
typedef vector <vi> vvi;

typedef pair<char, int> pci;
typedef vector<pci> vpci;

struct TNode {
	int edge[30];
	bool last;

	TNode() {
		memset(edge, -1, sizeof(edge));
		last = false;
	}
};

vector<TNode> bor(1);

void add_to_bor(const string& s) {
	int ind = 0;
	for (int i = 0; i < sz(s); ++i) {
		int go = s[i] - 'a';
		int& next = bor[ind].edge[go];
		if (next != -1) {
			ind  = next;
			continue;
		} else {
			next = sz(bor);
			ind = next;
			bor.pb(TNode());
		}
	}
	bor[ind].last = true;
}

inline int get_next(int bor_index, char c) {
	return bor[bor_index].edge[c - 'a'];
}

const int INF = 1000000;

const int nx = 4200;

int dp[nx][7];
bool was[nx][7];

struct TSolver {

	TSolver() {
		memset(was, 0, sizeof(was));
	}
	
	string s;

	int go_dp(int ind, int error, int bor_index) {
		if (ind >= sz(s)) {
			if (bor_index == 0 || bor[bor_index].last == true) {
				return 0;
			} else {
				return INF;
			}
		}

		if (bor_index == 0) {
			if (was[ind][error]) {
				return dp[ind][error];
			}
		}

		int res = INF;
		if (bor[bor_index].last) {
			res = min(res, go_dp(ind, error, 0));
		}

		int next = get_next(bor_index, s[ind]);
		if (next != -1) {
			int next_dp = go_dp(ind + 1, max(0, error - 1), next);
			// cout << ind << ": can take " << s[ind] << " ans: " << next_dp << endl;
			res = min(res, next_dp);
		}

		if (error == 0) {
			for (int g = 0; g + 'a' <= 'z'; ++g) {
				char c = g + 'a';
				if (c == s[ind]) {
					continue;
				}
				int nxt = get_next(bor_index, c);
				if (nxt != -1) {
					int next_dp = go_dp(ind + 1, 4, nxt);
					// cout << ind << ":if error take " << c << " instead of " << s[ind] << " ans: " << next_dp << endl;
					res = min(res, 1 + next_dp);
				}
			}
		}

		if (bor_index == 0) {
			was[ind][error] = true;
			dp[ind][error] = res;
		}
		// cout << "at " << ind << " error = " << error << " bor = " << bor_index << " --> " << res << endl;

		return res;
	}

};



void solve() {
	TSolver solver;
	cin >> solver.s;
	

	int res = solver.go_dp(0, 0, 0);
	// cout << min(res, 6) << endl;
	cout << res << endl;


}

int main () {
	//freopen("", "rt", stdin);
	//freopen("", "wt", stdout);
	//std::ios::sync_with_stdio(false);

	vector<string> words;
	ifstream input("dict.txt");
	string s;
	while (input >> s) {
		words.pb(s);
		add_to_bor(s);
	}
	// cout << "bor vertex: " << sz(bor) << endl;


	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cout << "Case #" << t + 1 << ": ";
		solve();
	}

    return 0;
}

