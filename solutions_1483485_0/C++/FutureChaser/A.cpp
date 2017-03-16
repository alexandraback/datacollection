#include <stdio.h>
#include <string.h>

char s[256];
//            abcdefghijklmnopqrstuvwxyz
char map[] = "yhesocvxduiglbkrztnwjpfmaq";

int main() {
	int n;
	scanf("%d\n", &n);
	for (int k = 0; k < n; ++k) {
		scanf("%[^\n]\n", s);
		for (int i = 0; i < strlen(s); ++i) {
			if (s[i] != ' ')
				s[i] = map[s[i] - 'a'];
		}
		printf("Case #%d: %s\n", k + 1, s);
	}
	return 0;
}
