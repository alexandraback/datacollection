#include <cstdio>
#include <cstring>

const int MAX = 1000005;

char str[MAX];
int n;
int L;

bool isCon(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return false;
	return true;
}

void proc() {
	int am = 0;
	int r = 0;
	int ans = 0;
	// invariant:
	// [i, r) contains n consec. consonants
	// am is this amount
	for (int i = 0; i < L; i++) {
		if (r < i + n) {
			am = r - i;
		}
		while (am < n && r != L) {
			if (isCon(str[r])) {
				am++;
			} else {
				am = 0;
			}
			r++;
		}
		if (am != n) {
			break;
		}
		// TODO check
		ans += L - r + 1;
	}
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++) {
		scanf("%s %d ", str, &n);
		L = strlen(str);
		printf("Case #%d: ", i);
		proc();
	}

	return 0;
}
