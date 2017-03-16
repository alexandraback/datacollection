#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define sqr(x) ((x) * (x))
#define two(x) (1 << (x))
#define ord(x, y, z) ((x) <= (y) && (y) <= (z))
#define X first
#define Y second

typedef long long LL;
typedef pair<int, int> pair2;

const int N = 111;
const double eps = 1e-9;
const int oo = 1000000000;

int n, s, p, a[N];

int main()
{
	int T, cas = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &s, &p);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		int t1 = 0, t2 = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] == p * 3 - 4 && a[i] >= 2 || a[i] == p * 3 - 3 && a[i] >= 3) {
				++t1;
			} else if (a[i] >= 3 * p - 2) {
				++t2;
			}
		}
		cout << "Case #" << ++cas << ": " << min(t1, s) + t2 << endl;
	}
	return 0;
}

