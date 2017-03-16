#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

#define ALL(v) v.begin(), v.end()

using namespace std;

template< typename T > T next() {  T tmp; cin >> tmp; return tmp; }

int fact(int n) {
	return n == 0 ? 1 : n * fact(n - 1);
}

void solve() {
	int n = next< int >();
	int m = next< int >();

	vector< string > zip;
	for (int i = 0; i < n; ++i) {
		zip.push_back( next< string >() );
	}

	vector< set< int > > edges(n, set< int >());
	for (int i = 0; i < m; ++i) {
		int u = next< int >() - 1;
		int v = next< int >() - 1;
		edges[u].insert(v);
		edges[v].insert(u);
	}
	int lim = fact(n);
	vector< int > pos(n);
	for (int i = 0; i < n; ++i) {
		pos[i] = i;
	}
	string best = "";
	for (int k = 0; k < lim; ++k) {

		vector< int > st;
		st.push_back(pos[0]);
		for (size_t i = 1; i < pos.size(); ++i) {
			while (st.size() > 0 && edges[st.back()].find(pos[i]) == edges[st.back()].end()) {
				st.pop_back();
			}
			if (st.size() == 0) {
				break;
			}
			st.push_back(pos[i]);
		}
		if (st.size() != 0) {
			string cur = "";
			for (int i = 0; i < n; ++i) {
				cur += zip[ pos[i] ];
			}
			if (best == "" || best > cur) {
				best = cur;
			}
		}

		next_permutation(ALL(pos));
	}
	cout << best << "\n";

}

int main() {

//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);

  int test = next< int >();
  for (int i = 1; i <= test; ++i) {
    printf("Case #%d: ", i);
    solve();
  }

  return 0;
}


