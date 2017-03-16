#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1000 + 10;
const int INF = 71227122;
int a[N];

int main() {
	int t;
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)	scanf("%d", a+i);

		int ans = INF;
		for(int i = 1; i <= 1000; i++) {
			int cnt = 0;
			for(int j = 0; j < n; j++) {
				if(a[j] > i)	cnt += (a[j]-1)/i;
			}
			ans = min(ans, cnt+i);
		}

		printf("Case #%d: %d\n", kase, ans);
	}

	return 0;
}
