#include <iostream>
#include <string>

using namespace std;

long long deg[11][33];
int a[11];

int main() {
	
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	for (int  i = 2; i <= 10; ++i) {
		deg[i][0] = 1;
		for (int j = 1; j <= 32; ++j) {
			deg[i][j] = i * deg[i][j - 1];
		}
	}
	int t;
	cin >> t;
	int n, jey;
	cin >> n >> jey;
	printf("Case #1:");
	for (long long  num = (1ll << (n - 1)) + 1; num < (1ll << n) && jey > 0; num += 2) {	
		for (int i = 2; i <= 10; ++i) {
			a[i] = 0;
			long long ans = 0;
			int j = 0;
			long long number = num;
			while (number) {
				ans += deg[i][j++] * (number % 2);
				number = number / 2;
			}
			if (ans % 2 == 0) {
				a[i] = 2;
			} else if (ans % 3 == 0) {
				a[i] = 3;
			} else if (ans % 5 == 0) {
				a[i] = 5;
			} else if (ans % 7 == 0) {
				a[i] = 7;
			} else if (ans % 11 == 0) {
				a[i] = 11;
			} else if (ans % 13 == 0) {
				a[i] = 13;
			}
			if (a[i] == 0) {
				break;
			}
			if (i == 10) {
				printf("\n");
				for (int k = 0; k < n; ++k) {
					printf("%d", ((num & (1ll << (n - k - 1))) > 0));
				}
				for (int k = 2; k <= 10; ++k) {
					printf(" %d ", a[k]);
				}
				--jey;
			}
		}
	}

    return 0;
}