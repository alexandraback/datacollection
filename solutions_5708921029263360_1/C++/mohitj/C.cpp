#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <numeric>
#include <cassert>

using namespace std;

int main() {
  int T;
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  for(int cn = 1; cn <= T; ++cn) {
cerr << cn << " of " << T << '\n';
    int J, P, S, K;
	cin >> J >> P >> S >> K;

	vector<int> vi;
    int ans = 0;

	typedef pair<int, int> pii;
	vector< pair< pii, int > > v;

	for(int j = 1; j <= J; ++j)
	for(int p = 1; p <= P; ++p)
	for(int s = 1; s <= S; ++s) {
		v.push_back( make_pair( make_pair(j, p), s ) );
	}

	const int sz = static_cast<int>( v.size() );
	for(int i = 0; i < 20000; ++i) {
		std::random_shuffle(v.begin(), v.end());
		map< pair<int, int>, int> m[3];
		vector<int> vvi;
		int vans = 0;
	    for(int i = 0; i < sz; ++i) {
			const int j = v[i].first.first, p = v[i].first.second, s = v[i].second;
			if(m[0][make_pair(j, p)] == K) continue;
			if(m[1][make_pair(p, s)] == K) continue;
			if(m[2][make_pair(s, j)] == K) continue;
			++m[0][make_pair(j, p)];
			++m[1][make_pair(p, s)];
			++m[2][make_pair(s, j)];
			vvi.push_back(j);
			vvi.push_back(p);
			vvi.push_back(s);
			++vans;
		}
		if(vans > ans) {
			ans = vans;
			vi.swap(vvi);
		}
	}

	cout << "Case #" << cn << ": ";
	cout << ans << '\n';
	for(int i = 0; i < ans; ++i) {
		int j = i * 3;
		cout << vi[j++] << ' ';
		cout << vi[j++] << ' ';
		cout << vi[j++] << '\n';
	}
  }
}
