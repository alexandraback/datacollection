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


vector<string> expand_right(const vector<string>& p)
{
	vector<string> res(p.size());
	for (int i = 0; i < p.size(); ++i)
	{
		string t = p[i];
		t.erase(t.size() - 1);
		res[i] = t;
		reverse(all(t));
		res[i] += t;
	}
	return res;
}
vector<string> expand_left(const vector<string>& p)
{
	vector<string> res = p;
	for (int i = 0; i < res.size(); ++i)
		reverse(all(res[i]));
	res = expand_right(res);
	for (int i = 0; i < res.size(); ++i)
		reverse(all(res[i]));
	return res;
}
vector<string> expand_down(const vector<string>& p)
{
	vector<string> res = p;
	res.pop_back();
	for (int i = p.size() - 2; i >= 0; --i)
		res.push_back(p[i]);
	return res;
}
vector<string> expand_up(const vector<string>& p)
{
	vector<string> res = p;
	reverse(all(res));
	res = expand_down(res);
	reverse(all(res));
	return res;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
bool can_see(const vector<string>& p, int d, int sx, int sy, int dx, int dy)
{
	for (int x = dx, y = dy; x * x + y * y <= d * d; x += dx, y += dy)
		if (p[sy + y][sx + x] == 'X')
			return true;
	return false;
}
int main()
{
	int T;
	cin >> T;
	for (int C = 1; C <= T; ++C)
	{
		int h, w, d;
		cin >> h >> w >> d;
		vector<string> p(h);
		for (int i = 0; i < h; ++i)
			cin >> p[i];

		while (p[0].size() < 10 * d)
			p = expand_right(p);
		p = expand_left(p);
		while (p.size() < 10 * d)
			p = expand_down(p);
		p = expand_up(p);


		int sx, sy;
		for (sy = 0; sy < p.size(); ++sy)
			for (sx = 0; sx < p[sy].size(); ++sx)
				if (p[sy][sx] == 'X' && sx > 2*d && p[sy].size() - sx > 2*d && sy > 2*d && p.size() - sy > 2*d)
					goto loop;
loop:

		int res = 0;
		for (int dx = -1; dx <= 1; ++dx)
			for (int dy = -1; dy <= 1; ++dy)
				if (abs(dx) + abs(dy) == 1 && can_see(p, d, sx, sy, dx, dy))
					++res;

		for (int dx = 1; dx <= d; ++dx)
		{
			for (int dy = 1; dy <= d; ++dy)
			{
				if (gcd(dx, dy) == 1)
				{
					static const int sign[] = { -1, 1 };
					for (int a = 0; a < 2; ++a)
						for (int b = 0; b < 2; ++b)
							if (can_see(p, d, sx, sy, dx * sign[a], dy * sign[b]))
								++res;
				}
			}
		}
		printf("Case #%d: %d\n", C, res);
	}
}