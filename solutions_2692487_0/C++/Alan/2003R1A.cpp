#include <cstdio>
#include <algorithm>
#define MAXN 1000005
using namespace std;
int t;
int a, n, v[MAXN];
int main() {
	scanf("%d", &t);
	for(int cs = 1; cs <= t; ++cs) {
		scanf("%d%d", &a, &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		if(a == 1) {
			printf("Case #%d: %d\n", cs, n);
			continue;
		}
		sort(v, v + n);
		int cnt = 0, opt = n;
		long long cura = a;
		for(int i = 0; i < n; ++i) {
			if(v[i] < cura) {
				cura = cura + v[i];
			}
			else {
				while(v[i] >= cura) {
					cura = cura * 2 - 1;
					++cnt;
				}
				cura = cura + v[i];
			}
			opt = min(opt, cnt + n - i - 1);
		}
		printf("Case #%d: %d\n", cs, opt);
	}
	return 0;
}
