#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int a[10];
int bo[1000];

int main() {
	freopen("C-small-1-attempt0.in", "r", stdin);
	freopen("C-small-1-attempt0.out", "w", stdout);
	int n, tmp, TT = 0;
	scanf("%d", &tmp);
	scanf("%d", &n);
	scanf("%d", &tmp);
	scanf("%d", &tmp);
	scanf("%d", &tmp);
	cout << "Case #1:" << endl;
	while (n--) {
		int ans = false;
		for (int i = 0; i < 7; i++) scanf("%d", &a[i]);
		for (int i = 2; i <= 5; i++)
			for (int j = 2; j <= 5; j++)
				for (int k = 2; k <= 5; k++) if (!ans) {
					memset(bo, 0, sizeof(bo));
					bo[1] = true;
					bo[i] = true;
					bo[j] = true;
					bo[k] = true;
					bo[i * j] = true;
					bo[i * k] = true;
					bo[j * k] = true;
					bo[i * j * k] = true;
					int t = 0;
					for (int p = 0; p < 7; p++) t += bo[a[p]];
					if (t == 7) {
						cout << i << j << k << endl;
						ans = true;
					}
				}
	}
	return 0;
}
