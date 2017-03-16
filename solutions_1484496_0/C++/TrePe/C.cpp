#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <math.h>
using namespace std;

int i, j, k, kejsis, kejs, n;
int ret;
int a[500];
int m[500];
int s1, s2;
bool done;

void go(int i) {
	if (i == n) {
		s1 = s2 = 0;
		for (j = 0; j < n; j++) {
			if (m[j] == 1) s1 += a[j];
			if (m[j] == 2) s2 += a[j];
		}
		if (s1 == s2 && s1 > 0) done = true;
		return;
	}
	m[i] = 0; go(i+1); if (done) return;
	m[i] = 1; go(i+1); if (done) return;
	m[i] = 2; go(i+1); if (done) return;
}

int main() {
	scanf("%d", &kejsis);
	for (int kejs = 1; kejs <= kejsis; ++kejs) {
		printf("Case #%d:\n", kejs);
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (i = 0; i < n; i++) m[i] = 0;
		done = false; go(0);
		if (done) {
			i = 0;
			for (j = 0; j < n; j++) {
				if (m[j] == 1) {
					if (i++ > 0) printf(" ");
					printf("%d", a[j]);
				}
			}
			printf("\n");
			i = 0;
			for (j = 0; j < n; j++) {
				if (m[j] == 2) {
					if (i++ > 0) printf(" ");
					printf("%d", a[j]);
				}
			}
			printf("\n");
		} else printf("Impossible\n");
	}
	return 0;
}
