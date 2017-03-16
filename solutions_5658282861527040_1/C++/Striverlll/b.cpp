#include <vector>
#include <list>
#include <map>
#include <set>
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
#define ll long long
#define pb push_back 
#define mp make_pair
#define FOR(x, l, r) for(x = (l); x <= (r); x++)
#define FORD(x, r, l) for(x = (r); x >= (l); x --)
using namespace std;
void work(int a, int bit[])
{
	int i;
	FOR(i, 0, 31) bit[i] = 0;
	i = 0;
	while (a > 0) {
		bit[i ++] = a & 1;
		a /= 2; 
	}
}
int a[1000], b[1000], c[1000];
int main()
{
	int tt, cas = 0, i, j, k, l, m0, m1, n0, n1, n, m;
	ll ans, tmp;
	freopen("binput1", "r", stdin);
	freopen("boutput1", "w", stdout);
	cin >> tt;
	while (tt --) {	
		cin >> n >> m >> k;
		ans = 0;
		work(n, a); work(m, b); work(k, c);
		for (i = 0; i <= 31; i ++)
			if (a[i] == 1)
			for (j = 0; j <= 31; j ++)
				if (b[j] == 1)
				for (k = 0; k <= 31; k ++)
					if (c[k] == 1) {
						tmp = 1;
						FORD(l, 31, k) {
							if (l > i) {
								n0 = a[l] == 0;
								n1 = a[l] == 1;
							}
							else if (l == i) n0 = 1, n1 = 0;
							else n0 = n1 = 1;
							if (l > j) {
								m0 = b[l] == 0;
								m1 = b[l] == 1;
							}
							else if (l == j) m0 = 1, m1 = 0;
							else m0 = m1 = 1;
							if (c[l] == 0 || l == k) tmp = tmp * (n0 * m1 + m0 * n1 + m0 * n0);
							else tmp = tmp * (n1 * m1);
						}
						if (tmp == 0) continue;
						FORD(l, k - 1, 0) {
							if (l > i) {
								n0 = a[l] == 0;
								n1 = a[l] == 1;
							}
							else if (l == i) n0 = 1, n1 = 0;
							else n0 = n1 = 1;
							if (l > j) {
								m0 = b[l] == 0;
								m1 = b[l] == 1;
							}
							else if (l == j) m0 = 1, m1 = 0;
							else m0 = m1 = 1;
							tmp = tmp * (m0 + m1) * (n0 + n1);
						}
						ans += tmp;
					}
		printf("Case #%d: ", ++cas);
		cout << ans << endl;
	}
	return 0;
}
