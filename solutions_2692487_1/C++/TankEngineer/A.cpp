#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 105;

int size[N], a, n;

int main() {
	int T;
	scanf("%d", &T);
	for (int V = 1; V <= T; ++V) {
	  scanf("%d %d", &a, &n);
	  for (int i = 1; i <= n; ++i) {
	    scanf("%d", &size[i]);
		}
		sort(size + 1, size + 1 + n);
		int ans = 105, ops = 0;
		if (a == 1) {
		  printf("Case #%d: %d\n", V, n);
			continue;
		}
		for (int i = 1; i <= n; ++i) {
			if (a > size[i]) {
			  a += size[i];
			} else {
			  //delete
			  ans = min(ans, ops + n - i + 1);
			  while (a <= size[i]) {
			    ++ops;
			    a += a - 1;
				}
				a += size[i];
			}
		}
		ans = min(ans, ops);
		printf("Case #%d: %d\n", V, ans);
	}
	return 0;
}

