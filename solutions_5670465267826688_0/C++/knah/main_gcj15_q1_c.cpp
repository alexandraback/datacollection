//compiler: MSVC 2010 (C++ obviously)
//one template to rule them all

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <queue>

typedef unsigned long long ull;
typedef long long ll;

#define FN "gcj_c"

using namespace std;

// 1 i j k 2 a b c
char ord[] = "1ijk2abc";
int c2o[255];
char mt[8][8] = {
	{'1', 'i', 'j', 'k',   '2', 'a', 'b', 'c'},
	{'i', '2', 'k', 'b',   'a', '1', 'c', 'j'},
	{'j', 'c', '2', 'i',   'b', 'k', '1', 'a'},
	{'k', 'j', 'a', '2',   'c', 'b', 'i', '1'},

	{'2', 'a', 'b', 'c',   '1', 'i', 'j', 'k'},
	{'a', '1', 'c', 'j',   'i', '2', 'k', 'b'},
	{'b', 'k', '1', 'a',   'j', 'c', '2', 'i'},
	{'c', 'b', 'i', '1',   'k', 'j', 'a', '2'},
};

int main() {
	//freopen("in.in", "r", stdin);
    //freopen("in.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	ifstream in(FN ".in");
	ofstream out(FN ".out");

	for(int i = 0; i < 8; i++) {
		c2o[ord[i]] = i;
	}

	int t;
	in >> t;

	for(int tn = 0; tn < t; tn++) {
		int l, x;
		in >> l >> x;
		string s;
		in >> s;

		out << "Case #" << tn + 1 << ": ";

		char init = '1';
		for(int i = 0; i < l; i++) {
			init = mt[c2o[init]][c2o[s[i]]];
		}

		char init2;

		if(((x * (ull) l) < 3ull) || init == '1' || (init == '2' && ((x%2) == 0)) || (init != '1' && init != '2' && (x % 4) != 2)) {
			out << "NO\n";
			continue;
		}

		/*if(has_i_sb && has_k_sb) {
			out << "YES\n";
			continue;
		}*/

		ull iprefix = 0;
		init = '1';
		std::set<char> seen;
		seen.insert(init);
		for(int ib = 0; ib < x; ib++) {
			for(int i = 0; i < l; i++) {
				init = mt[c2o[init]][c2o[s[i]]];
				if(init == 'i') {
					iprefix = ib * (ull) l + i + 1;
					goto no_more_i;
				}
			}
			if(seen.find(init) != seen.end()) {
				break;
			}
			seen.insert(init);
		}
no_more_i:

		ull kprefix = 0;
		seen.clear();
		init2 = '1';
		seen.insert(init2);
		for(int ib = x; ib > 0; ib--) {
			for(int i = l; i > 0; i--) {
				init2 = mt[c2o[s[i - 1]]][c2o[init2]];
				if(init2 == 'k') {
					kprefix = (ib - 1) * (ull) l + (i - 1);
					goto no_more_j;
				}
			}
			if(seen.find(init2) != seen.end()) {
				break;
			}
			seen.insert(init2);
		}
no_more_j:

		if(kprefix && iprefix && iprefix < kprefix) {
			out << "YES\n";
		} else
			out << "NO\n";
		
	}

	return 0;
}