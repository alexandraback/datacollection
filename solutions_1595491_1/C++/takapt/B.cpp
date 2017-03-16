#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>


using namespace std;

#ifdef _MSC_VER
#define __typeof__ decltype
template <class T> int popcount(T n) { return n ? 1 + popcount(n & (n - 1)) : 0; }
#endif
#ifdef __GNUC__
template <class T> int popcount(T n);
template <> int popcount(unsigned int n) { return n ? __builtin_popcount(n) : 0; }
template <> int popcount(int n) { return n ? __builtin_popcount(n) : 0; }
template <> int popcount(unsigned long long n) { return n ? __builtin_popcountll(n) : 0; }
template <> int popcount(long long n) { return n ? __builtin_popcountll(n) : 0; }
#endif

#define foreach(it, c) for (__typeof__((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define CL(arr, val) memset(arr, val, sizeof(arr))

#define rep(i, n) for (int i = 0; i < n; ++i)

template <class T> void max_swap(T& a, const T& b) { a = max(a, b); }
template <class T> void min_swap(T& a, const T& b) { a = min(a, b); }

typedef long long ll;
typedef pair<int, int> pint;

const double EPS = 1e-8;
const double PI = acos(-1.0);
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };
bool valid_pos(int x, int y, int w, int h) { return 0 <= x && x < w && 0 <= y && y < h; }



int main()
{
	int T;
	cin >> T;
	for (int C = 1; C <= T; ++C)
	{
		int n, s, p, t[128];
		cin >> n >> s >> p;
		for (int i = 0; i < n; ++i)
			cin >> t[i];

		int res = 0;
		for (int i = 0; i < n; ++i)
		{
			if ((t[i] + 2) / 3 >= p)
				++res;
			else if (t[i] >= 2 && s > 0 && t[i] / 3 + (t[i] % 3 == 2 ? 2 : 1) >= p)
			{
				++res;
				--s;
			}
		}
		printf("Case #%d: %d\n", C, res);
	}
}