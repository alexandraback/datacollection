#include <cstdio>
using namespace std;
typedef long long ll;

int n, d[1000], h[1000], m[1000];
ll sn, start[500000], revtime[500000];

int main() {
	freopen("r1b\\C-small-1-attempt0.in", "r", stdin);
	freopen("r1b\\C-small-1.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int N=1; N<=T; ++N) {
		scanf("%d", &n);
		sn = 0;
		for (int i=0; i<n; ++i) {
			scanf("%d%d%d", d+i, h+i, m+i);
			for (int j=0; j<h[i]; ++j) {
				start[sn] = d[i];
				revtime[sn] = m[i] + j;
				++sn;
			}
		}
		printf("Case #%d: ", N);
		if (sn == 1)
			puts("0");
		else {
			int slow = 0;
			if ((360-start[0])*revtime[0] < (360-start[1])*revtime[1])
				slow = 1;
			int fast = 1 - slow;
			if ((360-start[slow])*revtime[slow] >= (720-start[fast])*revtime[fast])
				puts("1");
			else
				puts("0");
		}
	}
}