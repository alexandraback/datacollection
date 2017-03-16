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

template <class T> void print(T a, int n, int br = 1, const string& deli = ", ") { cout << "{ "; for (int i = 0; i < n; ++i) { cout << a[i]; if (i + 1 != n) cout << deli; } cout << " }"; while (br--) cout << endl; }
template <class T> void print(const vector<T>& v, int br = 1, const string& deli = ", ") { print(v, v.size(), br, deli); }



int main()
{
	int T;
	cin >> T;
	for (int C = 1; C <= T; ++C)
	{
		int n, a[1024], b[1024];
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> a[i] >> b[i];

		vector<pint> x, y;
		for (int i = 0; i < n; ++i)
		{
			x.push_back(pint(a[i], i));
			y.push_back(pint(b[i], i));
		}
		sort(rall(x));
		sort(rall(y));

		int done[1024];
		CL(done, 0);
		int res = 0, star = 0;
		while (!y.empty())
		{
			if (!y.empty() && star >= y.back().first)
			{
				int lv = y.back().second;
				y.pop_back();

				if (done[lv] == 1)
					++star;
				else
					star += 2;

				done[lv] = 2;
				++res;
			}
			else if (!x.empty() && star >= x.back().first)
			{
				int lv = x.back().second;
				x.pop_back();

				if (done[lv] == 0)
				{
					while (star < y.back().first)
					{
						++star;
						done[lv] = 1;
						++res;
					}
				}
			}
			else
				break;
		}

		printf("Case #%d: ", C);
		if (y.empty())
			printf("%d\n", res);
		else
			puts("Too Bad");
	}
}