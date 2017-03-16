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

template <class T> void print(T a, int n, const string& deli = ", ") { cout << "{ "; for (int i = 0; i < n; ++i) { cout << a[i]; if (i + 1 != n) cout << deli; } cout << " }"; }
template <class T> void print(const vector<T>& v, const string& deli = ", ") { print(v, v.size(), deli); }

int main()
{
	const int MAX = 2000000 + 100;
	static vector<int> recycle[MAX + 1];
	for (int i = 1, mds = 1, d = 1; i <= MAX; ++i)
	{
		if (i / mds >= 10)
			mds *= 10, ++d;

		for (int j = 1, x = i; j < d; ++j)
		{
			x = (x % 10) * mds + x / 10;
			if (x > i && find(all(recycle[i]), x) == recycle[i].end())
				recycle[i].push_back(x);
		}
	}

	int T;
	cin >> T;
	for (int C = 1; C <= T; ++C)
	{
		int A, B;
		cin >> A >> B;
		int res = 0;
		for (int i = A; i <= B; ++i)
		{
			for (int j = 0; j < recycle[i].size(); ++j)
				if (recycle[i][j] <= B)
					++res;
		}
		printf("Case #%d: %d\n", C, res);
	}
}