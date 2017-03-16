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

char name[101];
int N;

void read() {
	scanf("%s %d", name, &N);
}

void process() {
	int total = 0;
	for (int i = 0; name[i]; i++) {
		for (int j = i; name[j]; j++) {
			int cnt = 0;
			bool achievedRestriction = false;
			for (int k = i; k <= j; k++) {
				if (strchr("aeiou", name[k]) == NULL) {
					cnt++;
				} else {
					cnt = 0;
				}
				achievedRestriction |= cnt >= N;
			}
			if (achievedRestriction) {
				total++;
			}
		}
	}
	printf("%d\n", total);
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