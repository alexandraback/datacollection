#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define X first
#define Y second
#define MP make_pair

const int MAXN = 1000 + 100;

vector<pair<int, int> > a;

int main() {
	int Tc, n;
	scanf("%d", &Tc);
	for (int re = 1; re <= Tc; ++re) {
		scanf("%d", &n);

		a.resize(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &a[i].Y, &a[i].X);
		}

		sort(a.begin(), a.end());

		int ans = n, now = 0;
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			bool changed = true;
			while (changed && a[i].X > now) {
				changed = false;
				for (int j = n - 1; j >= i; --j) {
					if (now >= a[j].Y && a[j].Y >= 0) {
						now++;
						ans++;
						a[j].Y = -1;
						changed = true;
						break;
					}
				}
			}

			if (now < a[i].X) {
				ok = false;
				break;
			}

			if (a[i].Y < 0) {
				now++;
			} else {
				now += 2;
			}
		}

		printf("Case #%d: ", re);

		if (ok) {
			printf("%d\n", ans);
		} else {
			puts("Too Bad");
		}
	}
	return 0;
}
