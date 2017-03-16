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
#include <cstring>
#include <complex>
#include <random>
#include <math.h>
#include <unordered_map>

#define INF 2000000000
#define LLINF 9000000000000000000LL
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

ll drev(ll v) {
	vector<ll> vs;
	while (v > 0) {
		vs.push_back(v % 10);
		v /= 10;
	}
	ll o = 0LL;
	for (int i = 0; i < vs.size(); ++i) {
		o = 10LL * o + vs[i];
	}
	return o;
}

ll costtone(ll v) {
	vector<ll> vs;
	while (v > 0) {
		vs.push_back(v % 10);
		v /= 10;
	}
	ll cost1 = 0LL;
	int i = 0, s = vs.size() - 1;
	ll m = 1;
	while (i < 1 + s / 2) {
		if (vs[i] > 0)
			cost1 += (vs[i] - 1) * m;
		else {
			cost1 += 9 * m;
			for (int j = i + 1; j <= s; ++j) {
				vs[j] -= 1;
				if (vs[j] == -1) {
					vs[j] = 9;
				}else
				break;
			}
			if (vs[s] <= 0) s--;
		}

		i++;
		m *= 10;
	}

	return cost1;
}

ll cost(ll N) {
	ll c = 0;
	while (N > 1) {
		c += costtone(N);
		N -= costtone(N);
		ll r = drev(N);
		c += 1;
		if (r < N) 
		N = r;
		else N--;
	}
	return c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int aantal;
	cin >> aantal;
	for (int t = 1; t <= aantal; ++t) {

		ll N;
		cin >> N;
		ll c = cost(N);
		if (N == 1) c++;
		
		cout << "Case #" << t << ": " << c << endl;
	}
	return 0;
}