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

int main() {
#ifdef KVARK
	freopen("src/input.txt", "r", stdin);
	//freopen("src/debug.txt", "w", stderr);
	freopen("src/output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);

	int tests;
	cin >> tests;
	for (int test = 0; test < tests; ++test) {

		cout << "Case #" << test + 1 << ": ";
		task();
		cout << endl;
	}

#ifdef KVARK_DEBUG
//	my_debug::printProcessInfo();
#endif
	return 0;
}

int n;
int a1, t1, c1;
int a2, t2, c2;

void task(){
	cin >> n;
	if (n == 1) {
		cin >> a1 >> c1 >> t1;
		cout << 0;
		return;
	}

	cin >> a1 >> c1 >> t1;
	cin >> a2 >> c1 >> t2;
	if (t1 == t2) {
		cout << 0;
		return;
	}
	double mx1 = t1 * (360 - (double)a1) / 360.0;
	double mx2 = t2 * (360 - (double)a2) / 360.0;
	double mx1_2 = mx1 + t1;
	double mx2_2 = mx2 + t2;

	if (mx1 > mx2) {
		cout << (mx2_2 <= mx1);
	} else
		cout << (mx1_2 <= mx2);

}
