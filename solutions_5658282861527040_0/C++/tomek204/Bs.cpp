#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void solve(int testcase) {
	int a, b, k; scanf("%d%d%d", &a, &b, &k);
	int w = 0;
	for (int i = 0; i < a; i++) for (int j = 0; j < b; j++) if ( (i&j) < k ) w++;
	
	printf("Case #%d: %d\n", testcase, w);
}

int main() {
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; i++) solve(i);
	return 0;
}