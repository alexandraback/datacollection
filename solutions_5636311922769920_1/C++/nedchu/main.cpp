#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
// head

int main() {
	int t, k, c, s, cas = 1;
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &k, &c, &s);
		printf("Case #%d: ", cas++);
		if (k > s*c) {
			puts("IMPOSSIBLE");
		} else {
			int n = (k + c-1) / c;
			for (int i = 0; i < n; i++) {
				LL st = i*c ;
				LL cur = 0;
				for (int j = 0; j < c; j++) {
					cur *= k;
					cur += min((LL)k-1, st + j);
				}
				printf("%I64d%c", cur+1, i==n-1 ? '\n' : ' ');
			}
		}
	}
	return 0;
}
