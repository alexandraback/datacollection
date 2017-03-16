#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200;

char s[MAXN];

bool V(const char x) {
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}

int gao(int a, int b) {
	int cc = 0, mx = 0;
	for (int i=a; i<=b; ++i) {
		if (!V(s[i])) {
			++cc;
		} else {
			mx = max(mx, cc);
			cc = 0;
		}
	}	
	mx = max(mx, cc);
	return mx;
}

int main() {
	int tc, cn = 0;
	int n;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%s%d", s, &n);
		int tot = 0, l = strlen(s);
		for (int i=0; i<l; ++i) {
			for (int j=i; j<l; ++j) {
				if (gao(i, j) >= n) ++tot;
			}
		}
		printf("Case #%d: %d\n", ++cn, tot);
	}

	return 0;
}
