#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	freopen("A.out", "w", stdout);

	int numCase, nowCase;
	scanf("%d", &numCase);

	for(nowCase = 1; nowCase <= numCase; nowCase++) {
		int r, c, w;
		scanf("%d%d%d", &r, &c, &w);

		int candLine = max(1, c/w), remain = c%w;
		printf("Case #%d: %d\n", nowCase, r*candLine + w + (remain == 0 ? -1 : 0));
	}

	return 0;
}