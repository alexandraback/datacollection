#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
static const double PI2 = 8.0 * atan(1.0);

#define REP(i,n)	for(int i=0;i<(int)n;++i)
#define ALL(c)		(c).begin(),(c).end()
#define CLEAR(v)	memset(v,0,sizeof(v))
#define MP(a,b)		make_pair((a),(b))
#define ABS(a)		((a)>0?(a):-(a))
#define FOR(i,s,n)	for(int i=s;i<(int)n;++i)

#define IMPOSSIBLE "IMPOSSIBLE"

//void solve1() {
//	int K, C, S;
//	cin >> K >> C >> S;
//	vector<ull> res[100];
//	REP(k, K) res[0].push_back(k);
//	ull k = K;
//	FOR(c, 1, C) {
//		auto &prev = res[c - 1];
//		for (int i = 0; i < (prev.size() + 1) / 2; ++i) {
//			//int j = (i + 1 == prev.size()) ? i : i + 1;
//			int j = prev.size() - 1 - i;
//			res[c].push_back((ull)prev[i] * k + prev[j]);
//		}
//		k *= K;
//	}
//	auto &r = res[C - 1];
//	if (r.size() > S) {
//		cout << IMPOSSIBLE << endl;
//	}
//	else {
//		REP(i, r.size()) {
//			if (i != 0) cout << " ";
//			cout << (r[i] + 1);
//		}
//		cout << endl;
//	}
//}

void solve() {
	ll K, C, S;
	cin >> K >> C >> S;
	vector<ll> res;
	ll n = 0;
	REP(i, K) {
		n *= K;
		n += i;
		if ((i + 1) % C == 0 || i + 1 == K) {
			res.push_back(n);
			n = 0;
		}
	}
	if (res.size() > S) {
		cout << IMPOSSIBLE << endl;
	}
	else {
		REP(i, res.size()) {
			if (i != 0) cout << " ";
			cout << (res[i] + 1);
		}
		cout << endl;
	}
}

int main(int argc, char **argv) {
	int T;
	cin >> T;
	REP(i, T) {
		cout << "Case #" << (i + 1) << ": ";
		solve();
	}
	return 0;
}
