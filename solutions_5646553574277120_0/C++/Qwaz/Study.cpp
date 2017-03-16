#include <cstdio>

typedef long long ll;

const int MAX = 110;

ll coins[MAX];

int main() {
	freopen("C.out", "w", stdout);

	int numCase, nowCase;
	scanf("%d", &numCase);

	for(nowCase = 1; nowCase <= numCase; nowCase++) {
		int c, kind, maxValue;
		scanf("%d%d%d", &c, &kind, &maxValue);

		int i;
		for(i = 0; i < kind; i++)
			scanf("%lld", &coins[i]);

		ll currentMax = 0;
		int added = 0;
		for(i = 0; i < kind; i++) {
			while(coins[i] > currentMax + 1 && currentMax < maxValue) {
				currentMax = currentMax + (currentMax+1)*c;
				added++;
			}
			currentMax = currentMax + coins[i]*c;

			if(currentMax >= maxValue) break;
		}

		while(currentMax < maxValue) {
			currentMax = currentMax + (currentMax+1)*c;
			added++;
		}

		printf("Case #%d: %d\n", nowCase, added);
	}

	return 0;
}