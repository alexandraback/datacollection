#include <cstdio>

#define MAXN 1001

int a[MAXN];
int b[MAXN];

int stars, total;

bool check2(int n) {
	for (int i = 0; i < n; ++i) {
		if (b[i] != -1 && b[i] <= stars) {
			stars += (a[i] != -1) + 1;
			b[i] = -1;
			total++;
			return true;
		}
	}

	return false;
}

bool check1(int n) {
	int max = -1;
	int index = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] != -1 && b[i] != -1 && b[i] > max && a[i] <= stars) {
			max = b[i];
			index = i;
		}
	}

	if (max == -1)
		return false;
	
	a[index] = -1;
	stars++;
	total++;
	return true;
}

int main() {

	int t,n,i, count;

	scanf("%d",&t);

	for (int tc = 0; tc < t; ++tc) {
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			scanf("%d %d",a+i,b+i);
		}

		stars = total = 0;
		count = n;
		while (count > 0) {
			if (check2(n)) {
				count--;
				continue;
			}
			if (!check1(n)) {
				count = -10;
				break;
			}
		}

		if (count == -10)
			printf("Case #%d: Too Bad\n",tc+1);
		else
			printf("Case #%d: %d\n",tc+1, total);

	}

	return 0;
}

