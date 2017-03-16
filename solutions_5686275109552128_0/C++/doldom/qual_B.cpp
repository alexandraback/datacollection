#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int d, p[1000];

int main() {
	freopen("qual\\B-small-attempt1.in", "r", stdin);
	freopen("qual\\B-small.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int N=1; N<=T; ++N) {
		scanf("%d", &d);
		for (int i=0; i<d; ++i)
			scanf("%d", p+i);
		int lo = 1, hi = *max_element(p, p+d);
		while (lo<hi) {
			int mid = (lo+hi)/2;
			int cnt = 0;
			bool success = false;
			priority_queue<int> pq(p, p+d);
			while (cnt < mid) {
				int c = pq.top();
				pq.pop();
				if (mid - cnt >= c) {
					success = true;
					break;
				}
				pq.push(c/2);
				pq.push(c-c/2);
				++cnt;
			}
			if (success) hi = mid;
			else lo = mid + 1;
		}
		/*for (int i=0; i<d; ++i)
			printf(" %d", p[i]);
		puts("");*/
		printf("Case #%d: ", N);
		printf("%d\n", lo);
	}
}