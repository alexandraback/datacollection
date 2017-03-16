#include <cstdio>
#include <cstring>

const int maxn = 1100;

int casei, cases, ans, n;
int len[maxn];
int q[maxn];
int bff[maxn];
int graph[maxn][maxn];

int cnt(int n1, int n2) {
	int l = 0, r = 1;
	q[0] = n1;
	len[n1] = 0;
	int maxi = 0;
	while (l < r) {
		int now = q[l++];
		for (int i = 1; i <= graph[now][0]; ++i) {
			int tmp = graph[now][i];
			if (tmp == n2) continue;
			q[r++] = tmp;
			len[tmp] = len[now] + 1;
			if (len[tmp] > maxi) maxi = len[tmp];
		}
	}
	return maxi;
}

void pair() {
	int ansp = 0;
	for (int i = 1; i <= n; ++i)
		if (bff[i] > i && bff[bff[i]] == i) {
			int now = bff[i];
			int t1 = cnt(i, now);
			int t2 = cnt(now, i);
			ansp += t1 + t2 + 2;
		}
	if (ansp > ans) ans = ansp;
}

void circle() {
	memset(q, 0, sizeof(q));
	for (int i = 1; i <= n; ++i) if (q[i] == 0) {
		int now = i;
		while (q[now] == 0) {
			q[now] = i;
			now = bff[now];
		}
		if (q[now] != i) continue;
		int ansc = 1;
		int tmp = bff[now];
		while (tmp != now) {
			++ansc;
			tmp = bff[tmp];
		}
		if (ansc > ans) ans = ansc;
	}
}

int main() {
	scanf("%d", &cases);
	for (casei = 1; casei <= cases; ++casei) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) graph[i][0] = 0;
		for (int i = 1; i <= n; ++i) {
			int tmp;
			scanf("%d", &tmp);
			bff[i] = tmp;
			graph[tmp][++graph[tmp][0]] = i;
		}
		
		ans = 0;
		pair();
		circle();
		
		printf("Case #%d: %d\n", casei, ans);
	}
	return 0;
}
