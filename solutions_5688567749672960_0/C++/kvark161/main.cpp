// Smile please :)

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cctype>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//#undef KVARK_DEBUG

#ifdef KVARK_DEBUG
	#include "../h/debug.h"
#else
#define dbg(...) (void(1));
#define dbg2(...) (void(1));
#define dbg3(...) (void(1));
#define dbg4(...) (void(1));
#define dbg5(...) (void(1));
#define dbgp(...) (void(1));
#define dbg_arr(...) (void(1));
#define dbg_vec(...) (void(1));
#endif
#define endl "\n"

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vector<int> > vvi;
typedef vector<vector<pii> > vvpii;
typedef vector<vector<long long> > vvll;
typedef vector<long long> vll;
typedef long long int llint;

#define all(v) (v.begin()), (v.end())

template <typename T>
inline T sqr(const T& a) {
	return a * a;
}

template <typename T>
inline int sign(const T& a) {
	return a < 0 ? -1 : a > 0;
}

void task();
void precalc();

int main() {
#ifdef KVARK
	freopen("src/input.txt", "r", stdin);
	//freopen("src/debug.txt", "w", stderr);
	freopen("src/output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);

	precalc();

	int tests;
	cin >> tests;
	for (int test = 0; test < tests; ++test) {

		cout << "Case #" << test + 1 << ": ";
		task();
		if (test + 1 != tests)
			cout << endl;
	}

#ifdef KVARK_DEBUG
//	my_debug::printProcessInfo();
#endif
	return 0;
}

const int INF = 1e9;
const int limit = 1e6;
int dp[limit + 10];

void precalc() {
	fill(dp, dp + limit + 10, INF);
	dp[1] = 1;
	priority_queue<pii> q;
	q.push({-1, 1});
	while (!q.empty()) {
		pii p = q.top();
		q.pop();
		p.first *= -1;
		int cnt = p.first;
		int num = p.second;
		if (dp[num] != cnt)
			continue;
		vi v;
		int a = num;
		while (a) {
			v.push_back(a % 10);
			a /= 10;
		}


		if (num + 1 <= limit && dp[num + 1] > dp[num] + 1) {
			dp[num + 1] = dp[num] + 1;
			q.push({-(dp[num] + 1), num + 1});
		}



		int n = 0;
		for (int i = 0; i < (int)v.size(); ++i)
			n *= 10, n += v[i];

		if (num != n && n <= limit && dp[n] > cnt + 1) {
			dp[n] = cnt + 1;
			q.push({-(cnt + 1), n});
		}

	}
}

void task(){
	int n;
	cin >> n;
	cout << dp[n];
}
