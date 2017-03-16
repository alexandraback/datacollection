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
		vi seen1(w1.size()), seen2(w2.size());
		int maxfakes = 0;
		for (int mask = 0; mask < (1 << n); ++mask) {
			seen1.assign(seen1.size(), 0);
			seen2.assign(seen2.size(), 0);
			for (int i = 0; i < n; ++i) if (mask & (1 << i)) {
				seen1[v[i].first] = 1;
				seen2[v[i].second] = 1;
			}
			bool valid = true;
			for (int i = 0; i < n; ++i) if (!(mask & (1 << i))) {
				if (!seen1[v[i].first] || !seen2[v[i].second]) {
					valid = false;
					break;
				}
			}
			if (valid) {
				int fakes = 0;
				for (int i = 0; i < n; ++i) if (!(mask & (1 << i)))
					++fakes;
				maxfakes = max(maxfakes, fakes);
			}			
		}
        out << "Case #" << test << ": " << maxfakes << "\n";
    }
    return 0;
}