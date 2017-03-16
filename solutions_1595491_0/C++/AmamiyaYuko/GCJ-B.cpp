#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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
#include <ctime>
#include <cstring>

//kAc
#define ALL(x) x.begin(), x.end()
#define foreach(x, E) for (__typeof(E.begin()) x = E.begin(); x != E.end(); x++)
#define MP make_pair
#define PB push_back
#define FR first
#define SC second
#define ERR cerr << "ERROR" << endl
#define LL long long
#define LD long double
#define PII pair<int, int>
#define PDI pair<double, int>
#define PID pair<int, double>
#define SZ(a) (int)a.size()
#define VEC vector
#define STR string
#define gmin(a, b) { if (b < a) a = b; }
#define gmax(a, b) { if (b > a) a = b; }
using namespace std;
int a[1000001], n, p, s;
int main()
{
freopen("temp.in", "r", stdin); freopen("temp.out", "w", stdout);
int TEST; scanf("%d", &TEST);	
for (int testi = 1; testi <= TEST; testi++){
	int ans = 0;
	scanf("%d%d%d", &n, &s, &p);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1, greater<int>());
	for (int i = 1; i <= n; i++){
		if (a[i] >= 3 * p - 2) { ++ans; continue; }
		if (a[i] >= max(3 * p - 4, p) && s > 0) { ++ans; --s; continue; }	
	}
	printf("Case #%d: %d\n", testi, ans);
}
}
