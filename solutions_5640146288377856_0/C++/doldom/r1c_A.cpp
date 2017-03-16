#include <cstdio>
using namespace std;

int r, c, w;

int main() {
	freopen("r1c\\A-small-attempt0.in", "r", stdin);
	freopen("r1c\\A-small.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int N=1; N<=T; ++N) {
		scanf("%d%d%d", &r, &c, &w);
		printf("Case #%d: ", N);
		printf("%d\n", (c-1)/w+w);
	}
}