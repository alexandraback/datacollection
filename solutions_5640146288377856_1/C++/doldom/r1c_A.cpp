#include <cstdio>
using namespace std;

int r, c, w;

int main() {
	freopen("r1c\\A-large.in", "r", stdin);
	freopen("r1c\\A-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int N=1; N<=T; ++N) {
		scanf("%d%d%d", &r, &c, &w);
		printf("Case #%d: ", N);
		printf("%d\n", (r-1)*(c/w) + (c-1)/w+w);
	}
}