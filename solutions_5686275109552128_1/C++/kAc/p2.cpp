//I hate this town, bacause it's too filled with memories I'd rather forget.
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
const double pi = acos(-1.0), eps = 1e-9;
const int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
const int MO = (int)(1e9 + 7);

//Two becomes one,and it through all eternity.
#define ALL(x) x.begin(), x.end()
#define fr(x, E) for (__typeof(E.begin()) x = E.begin(); x != E.end(); x++)
#define MP make_pair
#define PB push_back
#define FR first
#define SC second
#define ERR cerr << "ERROR" << endl
#define LL long long
#define LD long double
#define PII pair<int, int>
#define PIII pair<PII, int>
#define PDI pair<double, int>
#define PID pair<int, double>
#define SZ(a) (int)((a).size())
#define VEC vector
#define STR string
#define ISS istringstream
#define OSS ostringstream
#define CLR(a, b) memset(a, b, sizeof(a))
#define gmin(a, b) { if (b < a) a = b; }
#define gmax(a, b) { if (b > a) a = b; }

using namespace std;
int n, a[10000];
bool ok(int t)
{
	bool ans = false;
	for (int i = 0; i < t; i++){
		int tot = 0;
		for (int j = 1; j <= n; j++){
			tot += (a[j] / (t - i));
			if (a[j] % (t - i))
				++tot;
			tot--;
		}
		ans |= (tot <= i);
	}
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("temp.in", "r", stdin); freopen("temp.out", "w", stdout);
#endif
int TestCase; scanf("%d", &TestCase);
for (int ti = 1; ti <= TestCase; ti++){
	printf("Case #%d: ", ti);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int l = 0, r = 10000;
	while(l <= r){
		int m = l + r >> 1;
		if (ok(m))
			r = m - 1;
		else 
			l = m + 1;
	}
	printf("%d\n", l);
}    

}
