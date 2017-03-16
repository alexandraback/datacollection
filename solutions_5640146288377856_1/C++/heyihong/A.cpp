#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	freopen("in.txt", "r", stdin);
	int test_case;
	scanf("%d", &test_case);
	for (int tc = 1; tc <= test_case; ++tc) {
		int n, m, l;
		scanf("%d%d%d", &n, &m, &l);
		printf("Case #%d: %d\n", tc,  n * (m / l) + (m % l == 0 ? l - 1 : l));	
	}
}
