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
int a[1001][1001], n, m;
int main()
{
	freopen("B.in", "r", stdin); freopen("B.out", "w", stdout);
	int T;scanf("%d", &T);
	for (int ti = 1; ti <= T; ti++){
		printf("Case #%d: ", ti);
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &a[i][j]);
		bool bad = false;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++){
				bool ok1 = true, ok2 = true;
				for (int k = 1; k <= n; k++) if (a[k][j] > a[i][j]) ok1 = false;
				for (int k = 1; k <= m; k++) if (a[i][k] > a[i][j]) ok2 = false;
				if (ok1 == false && ok2 == false) bad = true;
			}
		puts(bad ? "NO" : "YES");
	}
    

}
