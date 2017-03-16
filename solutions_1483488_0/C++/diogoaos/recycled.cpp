#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 2000001;
const int MAXD = 10;

int first[MAXN][MAXD], sf[MAXN], pow[MAXN];

int main() {
	int ntests;
	scanf("%d", &ntests);
	
	memset(sf, 0, sizeof(sf));
	memset(pow, -1, sizeof(pow));
	
	pow[1] = 1;
	for (int i = 10; i < MAXN; i *= 10) {
		pow[i] = i;
	}
	
	for (int i = 1; i < MAXN; i++) {
		if (pow[i] == -1) {
			pow[i] = pow[i - 1];
		}
		
		int next = i % pow[i] * 10 + i / pow[i];
		while (next != i) {
			if (next < MAXN && next > i) {
				first[next][sf[next]++] = i;
			}
			next = next % pow[i] * 10 + next / pow[i];
		}
	}
	
	int a, b;
	for (int test = 1; test <= ntests; test++) {
		scanf("%d %d", &a, &b);
		int res = 0;
		for (int i = a; i <= b; i++) {
			res += upper_bound(first[i], first[i] + sf[i], b) - lower_bound(first[i], first[i] + sf[i], a);
		}
		printf("Case #%d: %d\n", test, res);
	}
	
	return 0;
}