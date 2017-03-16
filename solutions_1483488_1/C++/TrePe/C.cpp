#include <stdio.h>
#include <set>
using namespace std;

set<pair<int, int> > s;
pair<int, int> pii;

int i, j, k, q, n, a, b, ten, cnt;

int main() {
	scanf("%d", &n);
	for (int kejs = 1; kejs <= n; ++kejs) {
		printf("Case #%d: ", kejs);
		scanf("%d%d", &a, &b);
		i = a;
		k = 0;
		ten = 1;
		while (i > 0) {
			i /= 10;
			k++;
			ten *= 10;
		}
		ten /= 10;
		for (i = a; i <= b; i++) {
//			fprintf(stderr, "%d\n", i);
			j = i;
			for (q = 1; q < k; q++) {
				j = ten * (j % 10) + (j / 10);
				if (j >= a && j <= b) {
					if (i < j) pii.first = i, pii.second = j;
					if (i > j) pii.first = j, pii.second = i;
					if (i != j) s.insert(pii);
				}
			}
		}
		cnt = 0;
		for (set<pair<int, int> >::iterator it = s.begin(); it != s.end(); ++it) {
			if (it->first >= a && it->first <= b && it->second >= a && it->second <= b) cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
