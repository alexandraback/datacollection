#include <cstdio>
#include <cstring>
#include <string>

const int MAX = 20;
using namespace std;
typedef long long ll;

void makeSame(char *a, char *b, int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] == '?') {
			if (b[i] == '?') {
				a[i] = b[i] = '0';
			} else {
				a[i] = b[i];
			}
		} else {
			if (b[i] == '?') {
				b[i] = a[i];
			}
		}
	}
}

void fill(char c, char *s, char *end) {
	while (s != end) {
		if (*s == '?') *s = c;
		s++;
	}
}

bool inc(char *s, char *tpl, int n) {
	for (int i = n-1; i >= 0; i--) {
		if (tpl[i] == '?') {
			if (s[i] == '9') {
				s[i] = '0';
			} else {
				s[i]++;
				return true;
			}
		}
	}
	return false;
}

bool dec(char *s, char *tpl, int n) {
	for (int i = n-1; i >= 0; i--) {
		if (tpl[i] == '?') {
			if (s[i] == '0') {
				s[i] = '9';
			} else {
				s[i]--;
				return true;
			}
		}
	}
	return false;
}

int main() {
	freopen("output.txt", "w", stdout);

	int numCase, nowCase;
	scanf("%d", &numCase);
	for (nowCase = 1; nowCase <= numCase; nowCase++) {
		int n;
		char f[MAX], s[MAX];
		char rf[MAX], rs[MAX];

		scanf("%s%s", f, s);

		n = strlen(f);

		int diff = -1;
		for (int i = 0; i < n; i++) {
			if (f[i] != '?' && s[i] != '?' && f[i] != s[i]) {
				diff = i;
				break;
			}
		}

		if (diff == -1) {
			//can be same
			makeSame(f, s, n);

			strcpy(rf, f);
			strcpy(rs, s);
		} else {
			ll fsDiff = 1e18;

			auto update = [&](char *fCand, char *sCand) {
				ll rfCand = atoll(fCand);
				ll rsCand = atoll(sCand);
				ll candDiff = abs(rsCand - rfCand);

				if (fsDiff > candDiff ||
					(fsDiff == candDiff &&
					(atoll(rf) > rfCand || (atoll(rf) == rfCand && atoll(rs) > rsCand)))) {
					strcpy(rf, fCand);
					strcpy(rs, sCand);
					fsDiff = candDiff;
				}
			};

			char tf[MAX], ts[MAX];

			if (f[diff] < s[diff]) {
				//f < s
				strcpy(tf, f);
				strcpy(ts, s);
				makeSame(tf, ts, diff);
				fill('9', tf+diff, tf+n);
				fill('0', ts+diff, ts+n);
				update(tf, ts);

				//f > s
				strcpy(tf, f);
				strcpy(ts, s);
				makeSame(tf, ts, diff);
				if (inc(tf, f, diff)) {
					fill('0', tf+diff, tf+n);
					fill('9', ts+diff, ts+n);
					update(tf, ts);
				}

				//f > s
				strcpy(tf, f);
				strcpy(ts, s);
				makeSame(tf, ts, diff);
				if (dec(ts, s, diff)) {
					fill('0', tf+diff, tf+n);
					fill('9', ts+diff, ts+n);
					update(tf, ts);
				}
			} else {
				//f > s
				strcpy(tf, f);
				strcpy(ts, s);
				makeSame(tf, ts, diff);
				fill('0', tf+diff, tf+n);
				fill('9', ts+diff, ts+n);
				update(tf, ts);

				//f < s
				strcpy(tf, f);
				strcpy(ts, s);
				makeSame(tf, ts, diff);
				if (inc(ts, s, diff)) {
					fill('9', tf+diff, tf+n);
					fill('0', ts+diff, ts+n);
					update(tf, ts);
				}

				//f < s
				strcpy(tf, f);
				strcpy(ts, s);
				makeSame(tf, ts, diff);
				if (dec(tf, f, diff)) {
					fill('9', tf+diff, tf+n);
					fill('0', ts+diff, ts+n);
					update(tf, ts);
				}
			}
		}

		//printf("%s %s\n", f, s);
		printf("Case #%d: %s %s\n", nowCase, rf, rs);
	}

	return 0;
}