#include <cstdio>
#include <set>

using namespace std;

int main() {
	int r, cs = 0;
	scanf("%d", &r);
	while (r--) {
		int a, b;
		scanf("%d %d", &a, &b);
		int t;
		int fac = 1, f, f2, n;
		int sol = 0;
		t = a;
		while(t / 10) { t /= 10; fac *= 10; }
		for (int i = a; i < b; ++i) {
			t = i;
			f = fac;
			f2 = 10;
			set<pair<int, int> > chk;
			while (t / 10) {
				n = (i % f2) * f + i / f2;
				if (n > i && n <= b && chk.find(make_pair(i, n)) == chk.end()) {
					
					chk.insert(make_pair(i, n));
					//printf("%d %d\n", i, n);
					sol++;
				}
				t /= 10;
				f /= 10;
				f2 *= 10;
			}
		}
		printf("Case #%d: %d\n", ++cs, sol);
	}
	return 0;
}
