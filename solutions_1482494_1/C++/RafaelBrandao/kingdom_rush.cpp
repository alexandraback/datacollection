#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
int cn;

int stars[1010], t, p, tot;
int n;
int a[1010], b[1010];

int main() {
	int cases;
	scanf("%d",&cases);
	while (cases--) {
		scanf("%d",&n);
		memset(stars,0,sizeof(stars));
		for (int i=0; i < n; ++i) {
			scanf("%d%d",&a[i],&b[i]);
		}
		t = 0;
		tot = n<<1;
		int res = 0;
		int best = -1;
		while (t < tot) {
			p = t;
			for (int i=0; i < n; ++i) {
				if (stars[i] == 2) continue;
				if (t >= b[i]) {
					if (stars[i] == 1) {
						stars[i]++;
						++t;
						break;
					} else {
						stars[i] += 2;
						t += 2;
						break;
					}
				}
			}
			if (p != t) goto end;
			best = -1;
			for (int i=0; i < n; ++i) {
				if (stars[i] != 0) continue;
				if (t >= a[i]) {
					if (best == -1) best = i;
					else if (b[i] > b[best]) best = i;
				}
			}
			if (best != -1) {
				stars[best]++;
				++t;
			}
			if (p == t) break;
			end:
			++res;
		}
		printf("Case #%d: ",++cn);
		if (t < tot) printf("Too Bad\n");
		else printf("%d\n",res);
	}
	return 0;
}
