#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

char buf[1000];
int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small.out", "w", stdout);
	int _, cas = 1;
	scanf("%d", &_);
	while (_--) {
		printf("Case #%d: ", cas);
		cas++;

		scanf("%s", buf);
		int n = strlen(buf);
		int sections = 0;
		char prec = '+';
		for (int i = n - 1; i >= 0; --i) {
			if (prec != buf[i]) ++sections;
			prec = buf[i];
		}

		printf("%d\n", sections);
	}
	return 0;
}