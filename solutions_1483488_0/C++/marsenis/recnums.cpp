#include <cstdio>
#include <set>
#include <cmath>

using namespace std;

int digs(int n) { return (int)floor(log10(n)) + 1; }

set<int> seen;

int main() {
	int tst, a, b, ans, d, m, n, k, p[8];
	scanf("%d", &tst);

	p[0] = 1;
	for (int i=1; i<8; i++) p[i] = 10*p[i-1];

	for (int t=0; t<tst; t++) {
		scanf("%d%d", &a, &b);
		ans = 0;

		for (n=a; n<=b; n++) {
			d = digs(n);
			seen.clear();

			for (k=1; k<d; k++){
				m = (n % p[k])*p[d-k] + n/p[k];
				if ( digs(m) == d && m > n && m <= b && seen.find(m) == seen.end()) {
					ans++;
					seen.insert(m);
					//printf("%d: (%d, %d)\n", ans, n, m);
				}
			}
		}
		printf("Case #%d: %d\n", t+1, ans);

	}
	return 0;
}
