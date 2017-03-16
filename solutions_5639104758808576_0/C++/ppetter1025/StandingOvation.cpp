#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++) {
		int n;
		scanf("%d ", &n);
		int ans = 0, sum = 0;
		for(int i = 0; i <= n; i++) {
			int x;
			scanf("%1d", &x);
			if(!x)	continue;

			while(sum < i)	sum++, ans++;
			sum += x;
		}
		printf("Case #%d: %d\n", kase, ans);
	}

	return 0;
}
