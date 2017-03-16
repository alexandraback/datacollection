#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
#include <memory.h>
#include <ctype.h>
  
#include <iostream>
  
#include <string>
#include <complex>
#include <numeric>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <sstream>
  
using namespace std;
  
template<typename TYPE> inline TYPE sqr(const TYPE& a) { return (a) * (a); }
  
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
  
typedef long long li;
typedef double ld;
typedef pair<int, int> pt;
  
const int INF = 1000 * 1000 * 1000;
const ld EPS = 1e-9;
const ld PI = 2 * acos(0.0);
const int N = 100;

int main() {
	int tests;
	scanf("%d", &tests);
	for1(it, tests) {
		ld c, f, x;
		scanf("%lf%lf%lf", &c, &f, &x);
		ld res = INF;
		ld v = 2;
		ld t = 0;
		while (true) {
			ld val = t + x / v;
			res = min(res, val);
			t += c / v;
			if (t > res)
				break;
			v += f; 
		}
		printf("Case #%d: %.7lf\n", it, res);
	}
  
    return 0;
}
