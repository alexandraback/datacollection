#include <cstdio>
#include <cstring>

const int a[10] = {0, 6, 4, 8, 3, 5, 7, 2, 1, 9};
const char b[11] = "ZXUGHFVWOI";
const char c[10][10] = {
	"ZERO", "ONE", "TWO", "THREE", "FOUR",
	"FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};

char s[2001];
int n[26], ans[10];
int ls;

int main() {
	int t, tt;
	scanf("%d", &t);
	for (tt = 1; tt <= t; tt++) {
		scanf("%s", s);
		ls = strlen(s);
		for (int i = 0; i < 26; i++) n[i] = 0;
		for (int i = 0; i < ls; i++) n[s[i] - 'A']++;
		for (int i = 0; i < 10; i++) {
			int j = a[i];
			const char cc = b[i], *ss = c[j];
			ans[j] = n[cc - 'A'];
			for (int k = 0; ss[k] != '\0'; k++) {
				n[ss[k] - 'A'] -= ans[j];
			}
		}
		printf("Case #%d: ", tt);
		for (int i = 0; i < 10; i++) {
			while (ans[i]--) printf("%d", i);
		}
		printf("\n");
	}
	return 0;
}
