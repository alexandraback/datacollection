#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>

using namespace std;

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int tt;
	scanf("%d", &tt);
	for (int qq = 1; qq <= tt; qq++) {
		printf("Case #%d:", qq);
		int k, c, s;
		scanf("%d %d %d", &k, &c, &s);
		unsigned long long gap = pow(k, c - 1);
		for (unsigned long long i = 0; i < k; i++) {
			printf(" %llu", i * gap + 1llu);
		}
		printf("\n");
	}
	return 0;
}
