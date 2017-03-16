#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1000;
struct TPoint {
	int x, y, z;
	bool operator<(const TPoint &t)const {
		return y < t.y || y == t.y && x > t.x;
	}
} a[N];
int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int ii, tt;
	int i, j, k, s, t, n;
	scanf("%d", &tt);
	for (ii = 1; ii <= tt; ii++) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d%d", &a[i].x, &a[i].y);
			a[i].z = 0;
		}
		sort(a, a + n);
		s = 0;
		t = 0;
		k = 1;
		for (i = 0; i < n; i++) {
			while (s < a[i].y) {
				for (j = n - 1; j >= i; j--) {
					if (a[j].x <= s) {
						a[j].z = 1;
						s++;
						t++;
						break;
					}
				}
				if (j == i - 1) {
					k = 0;
					break;
				}
			}
			if (k == 0)break;
			if (a[i].z == 0) {
				s += 2;
				t++;
				a[i].z = 2;
			} else if (a[i].z == 1) {
				s++;
				t++;
				a[i].z = 2;
			}
		}
		printf("Case #%d: ", ii);
		if (k == 1)printf("%d\n", t);
		else printf("Too Bad\n");
	}
	return 0;
}
