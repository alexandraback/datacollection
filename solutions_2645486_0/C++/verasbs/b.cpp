#include <stdio.h>
#include <algorithm>

using namespace std;

int e, r, n, v[32];

int doit(int d, int c, int sf) {
	int ret = 0;
	if(d == n) return sf;

	for(int i = 0; i <= c; i++)
		ret = max(ret, doit(d+1, min(e, c-i + r), sf + i*v[d]));

	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int ca = 1; ca <= T; ca++) {
		scanf("%d%d%d", &e, &r, &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &v[i]);
		printf("Case #%d: %d\n", ca, doit(0, e, 0));
	}
	return 0;
}
