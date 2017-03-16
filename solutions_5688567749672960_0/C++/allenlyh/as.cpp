#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

const int maxn = 1000000 + 10;
int n;
int f[maxn];
deque<int> que;

int getrev(int n) {
	int ret = 0;
	while (n > 0) {
		ret = ret * 10 + n % 10;
		n /= 10;
	}
	return ret;
}

void work() {
	que.clear();
	memset(f, 0x3f, sizeof(f));
	f[1] = 1;
	que.push_back(1);
	while (!que.empty()) {
		int vis = que.front();
		que.pop_front();
		if (vis + 1 <= n && f[vis + 1] > f[vis] + 1) {
			f[vis + 1] = f[vis] + 1;
			que.push_back(vis + 1);
		}
		int tmp = getrev(vis);
		if (tmp > n) continue;
		if (f[tmp] > f[vis] + 1) {
			f[tmp] = f[vis] + 1;
			que.push_back(tmp);
		}
	}
	printf("%d\n", f[n]);
}

int main() {
	int T;
	int cas = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		printf("Case #%d: ", ++cas);
		work();
	}
	return 0;
}
