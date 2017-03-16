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

const int N = 1202;
const double eps = 1e-9;
const int oo = 1000000000;

int n, stt[N];
pair2 coin[N];

int solve()
{
	int cc = 0, ans = 0;
	bool flag;
	memset(stt, 0, sizeof(stt));
	for (int t = 0; t < n; ++t) {
		flag = false;
		for (int i = 0; i < n; ++i) if (stt[i] < 2 && coin[i].Y <= cc) {
			++ans;
			cc += 2 - stt[i];
			stt[i] = 2;
			flag = true;
			break;
		}
		if (!flag) {
			while (!flag) {
				int j = -1;
				for (int i = 0; i < n; ++i) if (stt[i] == 0 && coin[i].X <= cc) {
					if (j == -1 || coin[i].Y > coin[j].Y) {
						j = i;
					}
				}
				if (j == -1) {
					return -1;
				}
				++ans;
				cc += 1;
				stt[j] = 1;
				for (int i = 0; i < n; ++i) if (stt[i] < 2 && coin[i].Y <= cc) {
					++ans;
					cc += 2 - stt[i];
					stt[i] = 2;
					flag = true;
					break;
				}
			}
		}
	}
	return ans;
}

int main()
{
	int T, cas = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &coin[i].X, &coin[i].Y);
		}
		int ret = solve();
		printf("Case #%d: ", ++cas);
		if (ret == -1) {
			puts("Too Bad");
		} else {
			printf("%d\n", ret);
		}
	}
	return 0;
}

