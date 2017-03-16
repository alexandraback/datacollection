#include <iostream> 
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <cassert>

using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<ll, ll>;
using vi = vector<ll>;
using vb = vector<bool>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

const int INF = 2000000000;
const ll LLINF = 9000000000000000000;

void rec(size_t i, string &C, string &J, ll cv, ll jv, ll &dopt, ll &copt, ll &jopt, ll ep) {
	
	if (i == C.length()) {
		if (abs(cv - jv) < dopt || (abs(cv - jv) == dopt && (cv < copt || (cv == copt && jv < jopt)))) {
			dopt = abs(cv - jv);
			copt = cv;
			jopt = jv;
		}
	}
	for (int sc = 0; sc < 10; ++sc) {
		if (C[i] != '?' && C[i] - '0' != sc) continue;
		for (int sj = 0; sj < 10; ++sj) {
			if (J[i] != '?' && J[i] - '0' != sj) continue;
			rec(i+1,C,J, cv + ep*sc, jv + ep*sj, dopt, copt, jopt, ep/10LL);
		}
	}
}

void solve(int t) {
	string C, J;
	cin >> C >> J;
	int N = C.length();
	
	ll ep = 1LL;
	for (int i = 1; i < N; ++i)
		ep *= 10LL;
	
	ll dopt = LLINF, copt = 0LL, jopt = 0LL;
	rec(0, C, J, 0LL, 0LL, dopt, copt, jopt, ep);
	
	for (int i = 0; i < N; ++i) {
		if (C[i] == '?')
			C[i] = char('0' + (copt / ep));
		if (J[i] == '?')
			J[i] = char('0' + (jopt / ep));
		copt %= ep;
		jopt %= ep;
		ep /= 10LL;
	}
	cout << "Case #" << t << ": " << C << ' ' << J << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) solve(t);
	
	return 0;
}
