#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n, a[1005], b[1005], st[1005];
void solve() {
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d%d", &a[i], &b[i]);
	int now = 0, ans = 0;
	memset(st, 0, sizeof(st));
	while(1) {
		int change = 0;
		for(int j=0;j<n;j++) {
			if(st[j] < 2 && b[j] <= now) {
				now += 2-st[j];
				st[j] = 2;
				change=1;
				++ans;
			}
		}
		if(change) continue;
		int x = -1;
		for(int j=0;j<n;j++) {
			if(st[j] == 0 && a[j] <= now && (x==-1 || b[j] > b[x]))
				x = j;
		}
		if(x==-1) break;
		++ans;
		st[x] = 1;
		now ++;
	}
	static int cs=0;
	printf("Case #%d: ", ++cs);
	if(now == 2*n) { printf("%d\n", ans); }
	else puts("Too Bad");
	fprintf(stderr, "Case #%d: %d(%d)\n", cs, ans, now==2*n);
}

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}
