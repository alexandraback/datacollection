#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int T, N;
int step[1000050];
int ans, test;
queue<int> *q;

inline int reverse(int num) {
	int ret = 0;

	while (num) {
		ret = ret * 10 + num % 10;
		num /= 10;
	}
	
	return ret;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);

		memset(step, 0xff, sizeof step);

		q = new queue<int>;
		q->push(1);
		step[1] = 0;

		if (N == 1) goto out;

		while (!q->empty()) {
			int cur = q->front(); q->pop();

			int tmp = cur + 1;
			if (step[tmp] == -1) {
				step[tmp] = step[cur] + 1;
				if (tmp == N) goto out;
				q->push(tmp);
			}

			tmp = reverse(cur);
			if (step[tmp] == -1) {
				step[tmp] = step[cur] + 1;
				if (tmp == N) goto out;
				q->push(tmp);
			}
		}
	
out:		printf("Case #%d: %d\n", ++test, step[N] + 1);
		delete q;
	}

	return 0;
}
