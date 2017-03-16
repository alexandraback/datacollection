#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <numeric>

using namespace std;

char name[1123456];
int positions[1123456];
int N;

void read() {
	scanf("%s %d", name, &N);
}

void process() {
	memset(positions, -1, sizeof positions);
	int cnt = 0;
	for (int i = 0; name[i]; i++) {
		if (strchr("aeiou", name[i]) == NULL) {
			cnt++;
		} else {
			cnt = 0;
		}
		if (cnt >= N) {
			positions[i] = i;
		} else if (i) {
			positions[i] = positions[i - 1];
		}
	}
	long long total = 0;
	for (int i = 0; name[i]; i++) {
		if (positions[i] != -1) {
			total += (positions[i] - N + 2);
		}
		//printf("((%lld))\n", total);
	}
	printf("%lld\n", total);
}

int main() {
	int cases;
	scanf("%d", &cases);
	for (int i = 1; i <= cases; i++) {
		read();
		printf("Case #%d: ", i);
		process();
	}
	return 0;
}