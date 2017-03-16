#include <iostream>
#include <iomanip>
#include <vector>           
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <functional>
#include <string>
#include <string.h>  // Include for memset!
#include <complex>
#include <random>
#define _USE_MATH_DEFINES
#include <math.h>

#define INF 2000000000              // 9
#define LLINF 9000000000000000000LL // 18
#define LDINF 1e200

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef long long ll;
typedef long double ld;

void output(int t, ld ans) {
	cout << "Case #" << t << ": ";
	printf("%lf", (double)ans);
	cout << endl;		
}

template <int ALPHABET_SIZE, int(*mp)(char)>
class AC_FSM {
	struct Node {
		int child[ALPHABET_SIZE], failure = 0;
		vector<int> match;
		Node() {
			for (int i = 0; i < ALPHABET_SIZE; ++i) child[i] = -1;
		}
	};
	vector <Node> a;
public:
	AC_FSM() { a.push_back(Node()); }
	void construct_automaton(vector<string>& words) {
		for (int w = 0, n = 0; w < words.size(); ++w, n = 0) {
			for (int i = 0; i < words[w].size(); ++i) {
				if (a[n].child[mp(words[w][i])] == -1) {
					a[n].child[mp(words[w][i])] = a.size();
					a.push_back(Node());
				}
				n = a[n].child[mp(words[w][i])];
			}
			a[n].match.push_back(w);
		}

		queue<int> q;
		for (int k = 0; k < ALPHABET_SIZE; ++k) {
			if (a[0].child[k] == -1) a[0].child[k] = 0;
			else if (a[0].child[k] > 0) {
				a[a[0].child[k]].failure = 0;
				q.push(a[0].child[k]);
			}
		}
		while (!q.empty()) {
			int r = q.front(); q.pop();
			for (int k = 0; k < ALPHABET_SIZE; ++k) {
				if (a[r].child[k] != -1) {
					q.push(a[r].child[k]);
					int v = a[r].failure;
					while (a[v].child[k] == -1) v = a[v].failure;
					a[a[r].child[k]].failure = a[v].child[k];
					for (int w : a[a[v].child[k]].match)
						a[a[r].child[k]].match.push_back(w);
				}
			}
		}
	}

	ld aho_corasick(map<char, ld> char_chance, int s) {
		vector<ld> chance(a.size(), 0.0), chance2(a.size(), 0.0);
		chance[0] = 1.0;
		ld ret = 0.0;
		for (int i = 0; i < s; ++i) {
			for (int state = 0; state < a.size(); ++state) {
				// MOVE AUTOMATON
				for (int chr = 'A'; chr <= 'Z'; ++chr) {
					int ss = state;
					while (a[ss].child[mp(chr)] == -1)
						ss = a[ss].failure;
					ss = a[ss].child[mp(chr)];
					chance2[ss] += chance[state] * char_chance[chr];
					for (int w : a[ss].match) {
						ret += chance[state] * char_chance[chr];
					}
				}
			}
			for (int j = 0; j < a.size(); ++j) {
				chance[j] = chance2[j];
				chance2[j] = 0.0;
			}
		}
		return ret;
	}
};

int mpchar(char c) {
	return c - 'A';
}

ld expected(string& K, string& L, int s) {
	map<char, ld> chance;
	for (char c : K) {
		if (chance.find(c) == chance.end())
			chance[c] = 1.0 / (ld)K.size();
		else chance[c] += 1.0 / (ld)K.size();
	}

	AC_FSM<26, mpchar> fsm;
	vector<string> v_L(1, L);
	fsm.construct_automaton(v_L);
	
	return fsm.aho_corasick(chance, s);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int k, l, s;
		cin >> k >> l >> s;
		string K, L;
		cin >> K >> L;

		/*
				K : KEYBOARD
				L : TO-MATCH
				S : MONKEY-STRING
				k l s
				K
				L
		*/

		// max bananas: shortest match
		int m;
		for (m = 1; m < L.size(); ++m) {
			bool match = true;
			for (int i = 0; m + i < L.size(); ++i) {
				if (L[i] != L[m + i]) {
					match = false;
					break;
				}
			}
			if (match) break;
		}
		ld matches = 1 + (s - l) / m;
		ld ans;

		bool MATCH_POS = true;
		for (char c : L) {
			bool THIS_MATCH_POS = false;
			for (char cc : K) {
				if (c == cc) THIS_MATCH_POS = true;
			}
			MATCH_POS = MATCH_POS && THIS_MATCH_POS;
		}
		if (!MATCH_POS) ans = 0.0;
		else ans = matches - expected(K, L, s);

		output(t, ans);
	}

	return 0;
}