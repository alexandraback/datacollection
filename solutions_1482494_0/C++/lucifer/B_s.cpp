#include <stdio.h>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
#define maxl 2010
using namespace std;

int n, mark[maxl];
struct node {
	int a, b, idx;
}
E[maxl];

struct node2 {
	int req, lvl, idx;
}
L[maxl];

bool cmp(node A, node B) {
	return A.a < B.a;
}

bool cmp2(node2 A, node2 B) {
	return A.req < B.req || A.req == B.req && A.lvl < B.lvl;
}

int calc(int mask) {
	int top = 0;
	for(int i=1; i<=n; ++i) {
		if(!(mask & (1 << (i-1)))) continue;
		L[top].req = E[i].a;
		L[top].lvl = 1;
		L[top++].idx = E[i].idx;
	}
	for(int i=1; i<=n; ++i) {
		L[top].req = E[i].b;
		L[top].lvl = 2;
		L[top++].idx = E[i].idx;
	}
	sort(L, L + top, cmp2);

	int s = 0;
	memset(mark, 0, sizeof mark);
	for(int i=0; i<top; ++i) {
		if(s < L[i].req) return -1;
		if(mark[L[i].idx]) {
			s += 1;
		}
		else {
			if(L[i].lvl == 1) s += 1;
			else s += 2;
		}
		mark[L[i].idx] = 1;
	}
	return 1;
}

int cnt(int n) {
	int ans = 0;
	while(n) {
		if(n & 1) ans++;
		n >>= 1;
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	for(int q=1; q<=t; ++q) {
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) {
			scanf("%d%d", &E[i].a, &E[i].b);
			E[i].idx = i;
		}

		sort(E + 1, E + 1 + n, cmp);

		int ans = INF;
		for(int i=0; i<(1<<n); ++i) {
			int tmp = calc(i);
			if(tmp == -1) continue;
			ans = n + cnt(i);
			break;
		}
		printf("Case #%d: ", q);
		if(ans < INF) printf("%d\n", ans);
		else puts("Too Bad");
	}
	return 0;
}

