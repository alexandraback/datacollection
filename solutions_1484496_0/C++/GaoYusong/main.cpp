#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <list>

using namespace std;

//GyS Loves Algorithm
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define mk(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define rep(x, n) for (int x = 0; x < n; x++)
#define range(x, a, b)for (int x = a; x <= b; x++)
#define sz(x) x.size()
#define setv(x, y) memset(x, y, sizeof(x))
#define repi(it, x) for (typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define pl() printf("\n")

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

map<int, vector<int> > hh;
int aa[510];

int main()
{
	int T;
	int cn = 0;

	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		hh.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", &aa[i]);
		}
		for (int i = 1; i < 1 << n; i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) {
					sum += aa[j];
				}
			}
			hh[sum].push_back(i);
		}
		int a = -1, b = -1;
		for (map<int, vector<int> >::iterator iter = hh.begin(); iter != hh.end(); ++iter) {
			if (iter->second.size() >= 2) {
				a = iter->second[0];
				b = iter->second[1];
				break;
			}
		}
		printf("Case #%d:\n", ++cn);
		if (a == -1 && b == -1) {
			printf("Impossible\n");
		} else {
			vector<int> a1, a2;

			for (int i = 0; i < n; i++) {
				if (a & (1 << i)) {
					a1.push_back(i);
				}
				if (b & (1 << i)) {
					a2.push_back(i);
				}
			}
			for (int i = 0; i < a1.size(); i++) {
				printf("%d", aa[a1[i]]);
				if (i != a1.size() - 1)
					printf(" ");
			}
			printf("\n");
			for (int i = 0; i < a2.size(); i++) {
				printf("%d", aa[a2[i]]);
				if (i != a2.size() - 1)
					printf(" ");
			}
			printf("\n");
			
		}
	}
	return 0;
}
