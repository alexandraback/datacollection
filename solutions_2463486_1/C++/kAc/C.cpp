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
bool check(long long t)
{
	int tot, a[1001];
	tot = 0;
	while(t) { a[++tot] = t % 10; t /= 10; }
	for (int i = 1; i <= tot; i++) if (a[i] != a[tot - i + 1]) return false;
	return true;
}
LL data[1000001], tot;
int main()
{
	freopen("C.in", "r", stdin); freopen("C.out", "w", stdout);
    for (LL i = 1; i <= 100000000; i++){
		if (i % 1000000 == 0) cerr << i << endl;
		if (check(i) && check(i * i))
			data[++tot] = i;
	}
	for (int i = 1; i <= tot; i++) cerr << data[i] << endl;
	int T; scanf("%d", &T);
	for (int ti = 1; ti <= T; ti++){
		printf("Case #%d: ", ti);
		LL L, R;
		cin >> L >> R;
		int ans = 0;
		for (int i = 1; i <= tot; i++) if (L <= data[i] * data[i] && R >= data[i] * data[i]) ++ans;
		cout << ans << endl;
	}	

}
