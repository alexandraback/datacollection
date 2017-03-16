#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>
#include <conio.h>
#include <functional>
#include <math.h>
#include <algorithm>
#include <time.h>
using namespace std;
int n;
int c[2555];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int runs = 1;
	int T; for (scanf("%d", &T); T--;) {
		scanf("%d", &n);
		memset(c, 0, sizeof(c));
		for (int i = 0; i < 2 * n - 1; i++) {
			int x;
			for (int j = 0; j < n; j++) {
				scanf("%d", &x); c[x]++;
			}
		}
		printf("Case #%d:", runs++);
		for (int i = 1; i <= 2500; i++) if (c[i] & 1) printf(" %d", i);
		printf("\n");
	}
	return 0;
}