#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	int i, j;

	int *d = new int[1000002];

	for (i = 0; i < 1000001; ++i) {
		d[i] = i;
	}

	for (i = 1; i < 1000001; ++i) {
		char buf[100];
		memset(buf, 0x00, sizeof(buf));
		itoa(i, buf, 10);
		int len = strlen(buf);
		reverse(buf, buf + len);
		int newnum = atoi(buf);

		d[newnum] = min(d[newnum], d[i] + 1);
		d[i + 1] = min(d[i + 1], d[i] + 1);
	}

	for(i = 0; i < T; ++i) {
		int N;
		scanf("%d", &N);

		printf("Case #%d: %d\n", i + 1, d[N]);
	}

	return 0;
}
