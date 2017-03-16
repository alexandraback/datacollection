#include <iostream>
#include <cstdio>
#include <cstring>  
#include <string>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <bitset>

using namespace std;
 
const int maxh = 2500;

int a[maxh + 5];

int main() {
	int cases;
	scanf("%d", &cases);
	for (int o = 0; o < cases; ++o) {
		int n;
		memset(a, 0, sizeof(a));
		scanf("%d", &n);
		for (int i = 0; i < n + n - 1; ++i) {
			for (int j = 0; j < n; ++j) {
				int x;
				scanf("%d", &x);
				++a[x];
			}
		}
		printf("Case #%d:", o + 1);
		for (int i = 1; i <= maxh; ++i) {
			if ((a[i] & 1) == 1) {
				printf(" %d", i);
			}
		}
		printf("\n");
	}
	return 0;
}


