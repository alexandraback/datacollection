#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;

const int l = 105;
int a[l][l];
int b[l][l];
int c[l];
int n, m, t;
bool printed;

bool valid(int no) {
	int c1;
	for (int i = 0; i < n; i++) {
		c1 = 0;
		for (int j = 0; j < m; j++)
			if (a[i][j] == no || b[i][j] <= no)
				c1++;
		if (c1 == m)
			for (int j = 0; j < m; j++)
				b[i][j] = no;
	}

	for (int i = 0; i < m; i++) {
		c1 = 0;
		for (int j = 0; j < n; j++)
			if (a[j][i] <= no)
				c1++;
		if (c1 == n)
			for (int j = 0; j < n; j++)
				b[j][i] = no;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == no && b[i][j] != no)
				return 0;
	return 1;
}

int main() {
	scanf("%d", &t);

	for (int C = 1; C <= t; C++) {
		printf("Case #%d: ", C);

		scanf("%d %d", &n, &m);
		memset(c, 0, sizeof c);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				scanf("%d", &a[i][j]);
				c[a[i][j]]++;
				b[i][j] = 100;
			}

		printed = 0;
		for (int i = 1; i <= 100 && !printed; i++)
			if (c[i]) {
				if (!valid(i)) {
					puts("NO");
					printed = 1;
				}
			}
		if (!printed)
			puts("YES");
	}

	return 0;
}
