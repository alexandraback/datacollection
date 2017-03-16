#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

/*
const int N = 10 * 1000 * 1000 + 3;

inline bool isPalindrome(li x)
{
	string s;

	while (x)
	{
		s.pb(x % 10);
		x /= 10;
	}
	
	reverse(all(s));
	forn(i, sz(s) >> 1)
		if (s[i] != s[sz(s) - 1 - i])
			return false;
			
	return true;
}

inline void prepare()
{
	for (li i = 1; i * i <= li(1e15); i++)
	{
		if (isPalindrome(i) && isPalindrome(sqr(i)))
		{
			sz++;
			cout << i << ", ";
		}
	}
	
	cout << sz << endl;
}
*/

const int N = 48;

li p[N] = { 1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 1001, 1111, 2002, 10001, 10101, 10201, 11011, 11111, 11211, 20002, 20102, 100001, 101101, 110011, 111111, 200002, 1000001, 1001001, 1002001, 1010101, 1011101, 1012101, 1100011, 1101011, 1102011, 1110111, 1111111, 2000002, 2001002, 10000001, 10011001, 10100101, 10111101, 11000011, 11011011, 11100111, 11111111, 20000002 };

li a, b;

inline bool read()
{
	return scanf("%I64d%I64d", &a, &b) == 2;
}

inline void solve(int test)
{
	int cnt = 0;
	
	forn(i, N)
		if (a <= sqr(p[i]) && sqr(p[i]) <= b)
			cnt++;

	printf("Case #%d: %d\n", test + 1, cnt);
}

int main()
{
#ifdef SU2_PROJ
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
        
	cout << setprecision(10) << fixed;
	cerr << setprecision(5) << fixed;
	
	int testCount;
	cin >> testCount;
	
	forn(test, testCount)
	{
		assert(read());
		solve(test);
	}
        
	return 0;
}