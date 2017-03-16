#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <queue>

using namespace std;

int dist[1000000 + 1];
int N;
int cap;

int raiseToPower(int v) {
	int ov = v;
	int base = 1;
	while (v) {
		base *= 10;
		v /= 10;
	}
	base /= 10;
	if (ov == base) {
		return base;
	} else {
		return base * 10;
	}
}

int reverse(int v) {
	int res = 0;
	while (v) {
		int d = v % 10;
		v /= 10;
		res = res * 10 + d;
	}
	return res;
}

void bfs() {
	queue<int> que;
	dist[1] = 1;
	que.push(1);

	while (!que.empty()) {
		int v = que.front();
		que.pop();

		if (v + 1 <= cap && dist[v + 1] == 0) {
			dist[v + 1] = dist[v] + 1;
			if (v + 1 == N) {
				break;
			}
			que.push(v + 1);
		}
		int rv = reverse(v);
		assert(rv <= cap);
		if (dist[rv] == 0) {
			dist[rv] = dist[v] + 1;
			if (rv == N) {
				break;
			}
			que.push(rv);
		}
	}
}

int 
main(void) {
	int T;
	scanf("%d", &T);

	for (int seqno = 1; seqno <= T; seqno++) {
		scanf("%d", &N);
		cap = raiseToPower(N);
		memset(dist, 0, (cap + 1) * sizeof(int));

		bfs();
		printf("Case #%d: %d\n", seqno, dist[N]);
	}

	return 0;
}
