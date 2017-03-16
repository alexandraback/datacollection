#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
char s[1000];

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int test, nCase = 0;
	scanf("%d", &test);
	while (test --) {
		scanf("%s", s);
		char last;
		int ans = 0;
		for (int i = 0; s[i] ; i ++) {
			last = s[i];
			if (i > 0 && s[i] != s[i - 1]) {
				ans ++;
			}
		}
		if (last == '-') ans ++;
		nCase ++;
		printf("Case #%d: %d\n", nCase, ans);
	}
	return 0;
}
