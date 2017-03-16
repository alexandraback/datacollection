#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#pragma warning( disable : 4244 4267 4018 4996 4800 )
#include <future>
//#pragma comment( linker, "/stack:10000000" )
using namespace std; 
typedef vector< int > vi; typedef vector< vector< int > > vvi; typedef vector< string > vs; typedef vector< double > vd;
typedef vector< vd > vvd; typedef long long ll; typedef vector< ll > vll; typedef vector< vll > vvll; typedef pair< int, int > pii;
#define all( v ) (v).begin( ), (v).end( )

ifstream in( "c.in" );
ofstream out( "c.out" );

int find_idx(map<string, int> & m, string w) {
	auto it = m.find(w);
	if (it == m.end()) {
		int sz = m.size();
		m[w] = sz;
		return sz;
	}
	return it->second;
}

struct max_matching {
	max_matching(vvi const & c) : c(c), left(c.size(), -1), right(c[0].size(), -1), size(0) {
		for (bool t = true; t; ) {
			mark = vi(c[0].size());
			t = false;
			for (int i = 0, n = c.size(); i < n; ++i) if (left[i] == -1)
				if (search(i))
					size++, t = true;
		}
	}

	bool search(int k) {
		for (int i = 0, n = c[0].size(); i < n; ++i) if (c[k][i] && !mark[i]) {
			mark[i] = true;
			if (right[i] == -1 || search(right[i])) {
				right[i] = k; left[k] = i;
				return true;
			}
		}

		return false;
	}

	vvi const & c;
	vi mark, left, right;
	int size;
};

int main() {
    int ntests;
    in >> ntests;
    for (int test = 1; test <= ntests; ++test) {
		int n; in >> n;
		map<string, int> w1, w2;
		vector<pii> v;
		for (int i = 0; i < n; ++i) {
			string p, q;
			in >> p >> q;
			v.push_back(make_pair(find_idx(w1, p), find_idx(w2, q)));
		}		
		vvi e(w1.size(), vi(w2.size()));
		for (int i = 0; i < n; ++i) {
			e[v[i].first][v[i].second] = 1;
		}
		max_matching m(e);
		int needed = m.size + w1.size() - m.size + w2.size() - m.size;
        out << "Case #" << test << ": " << n - needed << "\n";
    }
    return 0;
}