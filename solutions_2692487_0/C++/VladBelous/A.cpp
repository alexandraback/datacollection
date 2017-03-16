#include <vector>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <utility>

#include <string>
#include <iostream>

using namespace std;

template<typename T>
inline int sz(const T& x) { return (int)x.size(); }

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long int LL;


int solve(int a, vi& M) {
	sort(M.begin(), M.end());

	int best = sz(M);
	int xs = 0;
	for (int k = 1; k <= sz(M); ++k) {
		if (a-1 == 0) break;
		while (a <= M[k-1]) {
			a  += (a-1);
			xs += 1;
		}
		a += M[k-1];
		best = min(best, xs + sz(M)-k);
	}
	return best;
}


int main() {
	int tcn; cin >> tcn;

	for (int tc = 1; tc <= tcn; ++tc) {
		int ans = 0;

		int A; cin >> A;
		int N; cin >> N;
		vi motes(N);
		for(int i = 0; i < N; ++i)
			cin >> motes[i];

		ans = solve(A, motes);

		cout << "Case #" << tc << ": " << ans << "\n";
	}

	return 0;
}

