#include <cstdio>

#define N 256

const char tran[27] = "yhesocvxduiglbkrztnwjpfmaq";

int T;
char s[N];

int main() {
	gets(s); sscanf(s, "%d", &T);
	for (int r = 1; r <= T; ++r) {
		printf("Case #%d: ", r);
		gets(s);
		for (int i = 0; s[i]; ++i) putchar(('a' <= s[i] && s[i] <= 'z') ? tran[s[i] - 'a'] : s[i]);
		puts("");
	}
}
