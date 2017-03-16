#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>

#define si() (scanf("%d", &TEMP), TEMP);

using namespace std;

int TEMP;

char ta[2000];
char re[5000];
int st = 2500;
int ed = 2501;

void solve() {
	scanf("%s", ta);
	int l = strlen(ta);

	st = 2500;
	ed = 2501;
	re[st] = ta[0];

	for (int i = 1; i < l; i++) {
		char nc = ta[i];
		if (nc > re[st]) {
			re[--st] = nc;
		}
		else if (nc < re[st]) {
			re[ed++] = nc;
		}
		else {
			int j = st;
			for (; j < ed - 1; j++) {
				if (re[j] < re[j + 1]) {
					re[ed++] = nc;
					break;
				}
				else if (re[j] > re[j + 1]) {
					re[--st] = nc;
					break;
				}
			}
			if (j == ed - 1) {
				re[ed++] = nc;
			}
		}
	}

	for (int i = st; i < ed; i++) {
		printf("%c", re[i]);
	}
	printf("\n");
}

int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N = si();
	for (int i = 0; i < N; i++) {
		printf("Case #%d: ", i + 1);
		solve();
	}
}

