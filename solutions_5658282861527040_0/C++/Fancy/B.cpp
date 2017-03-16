#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int testnum, a, b, k;
	long long ans;
	scanf("%d", &testnum);
	for (int test = 1; test <= testnum; test++) {
		scanf("%d%d%d", &a, &b, &k);
		ans = 0;
		for (int i = 0;i < a;i++) {
			for (int j = 0;j < b;j++) {
				if ((i & j) < k) ans++;
			}
		}
		printf("Case #%d: %lld\n", test, ans);
	}
	return 0;
}
