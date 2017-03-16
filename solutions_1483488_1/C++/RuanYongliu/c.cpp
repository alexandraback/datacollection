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

const int N = 2000001;
const double eps = 1e-9;
const int oo = 1000000000;
const int t[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

int flag[N];

int len(int x)
{
	int ret = 0;
	while (x) {
		++ret;
		x /= 10;
	}
	return ret;
}

int main()
{
	int T, cas = 0;
	scanf("%d", &T);
	while (T--) {
		int n, m, ans = 0;
		scanf("%d%d", &n, &m);
		memset(flag, 0, sizeof(flag));
		for (int i = n; i <= m; ++i) {
			int l = len(i);
			for (int j = 1; j < l; ++j) if (i % t[j] >= t[j - 1]) {
				int p = i % t[j] * t[l - j] + i / t[j];
				if (p > i && p <= m) {
					if (flag[p] != i) {
						++ans;
					}
					flag[p] = i;
				}
			}
		}
		cout << "Case #" << ++cas << ": " << ans << endl;
	}
	return 0;
}

