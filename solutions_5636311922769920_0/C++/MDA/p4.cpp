#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <string>
#include <assert.h>
#include <set>

using namespace std;



int main() {
	freopen("input.txt", "rt", stdin);
	freopen("C:\\Users\\dmarin3\\Downloads\\D-small-attempt0.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int k, c, s;
		scanf("%d%d%d", &k, &c, &s);
		assert(k == s);
		long long a = 1;
		for (int i = 1; i < c; ++i)
			a *= k;
		printf("Case #%d:", i+1);
		for (int i = 0; i < s; ++i)
			printf(" %lld", (i + 1)*a);
		printf("\n");
	}
}