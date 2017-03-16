#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#define MAX 55

using namespace std;

map<int, int> M;

int main() {
	int a, c, t, i, j, n;
	scanf("%d", &t);
	for (c = 1; c <= t; c++) {
		M.clear();
		scanf("%d", &n);
		for (i = 0; i < 2 * n - 1; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", &a);
				if (M.count(a))
					M[a]++;
				else M[a] = 1;
			}
		}
		printf("Case #%d:", c);
		for (auto it : M)
			if (it.second % 2 == 1)
				printf(" %d", it.first);
		printf("\n");
	}
	return 0;
}

