#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int arr[10000];

int main()
{
	freopen("B1.in", "r", stdin);
	freopen("B1.txt", "w", stdout);
	int T, n;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		memset(arr, 0, sizeof(arr));

		scanf("%d", &n);		
		for (int i = 0; i < 2 * n - 1; i++) {
			for (int j = 0; j < n; j++) {
				int x;
				scanf("%d", &x);
				arr[x]++;
			}
		}

		printf("Case #%d:", t);
		for (int i = 0; i <= 3000; i++)
			if (arr[i] % 2)
				printf(" %d", i);

		printf("\n");
	}
}
