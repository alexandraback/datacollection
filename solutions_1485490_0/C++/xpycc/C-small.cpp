#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int ca, cb;
int a[200], b[200];
typedef long long LL;
LL aa[200], bb[200];

LL f[200][200];

int main() {
	int test; scanf("%d", &test);
	for (int cas = 1; cas <= test; ++cas) {
		int n, m; scanf("%d%d", &n, &m);
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		memset(aa, 0, sizeof aa);
		memset(bb, 0, sizeof bb);
		ca = 0; cb = 0;
		for (int i = 0; i < n; ++i) {
			int pa; LL ta;
			scanf("%I64d%d", &ta, &pa);
			if (pa == a[ca])
				aa[ca] += ta;
			else {
				aa[++ca] = ta;
				a[ca] = pa;
			}
		}
		for (int i = 0; i < m; ++i) {
			int pb; LL tb;
			scanf("%I64d%d", &tb, &pb);
			if (pb == b[cb])
				bb[cb] += tb;
			else {
				bb[++cb] = tb;
				b[cb] = pb;
			}
		}
		memset(f, 0, sizeof f);
		LL ans = 0;
		for (int i = 1; i <= ca; ++i) {
			for (int j = 1; j <= cb; ++j) {
				LL ad = 0, tt = aa[i];
				f[i][j] = f[i - 1][j];
				for (int k = j; k > 0; --k) {
					LL ch = 0;
					if (a[i] == b[k])
						ch = min(tt, bb[k]);
					ad += ch;
					tt -= ch;
					f[i][j] = max(f[i][j], f[i - 1][k - 1] + ad);
				}
				ans = max(ans, f[i][j]);
			}
		}
		if (ca == 3 && a[1] == a[3]) {
			LL ta = 0;
			for (int i = 1; i <= cb; ++i)
				if (a[1] == b[i])
					ta += bb[i];
			ta = min(ta, aa[1] + aa[3]);
			ans = max(ans, ta);
		}
		printf("Case #%d: %I64d\n", cas, ans);
	}
	return 0;
}
