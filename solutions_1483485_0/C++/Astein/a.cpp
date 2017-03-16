#include <cstring>
#include <cstdio>

using namespace std;

char stable[27] = "yhesocvxduiglbkrztnwjpfmaq";

char s[105];

int main() {
	int T;
	fgets(s, 103, stdin);
	sscanf(s, "%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		fgets(s, 103, stdin);
		printf("Case #%d: ", cn);
		int ls = strlen(s);
		for (int i = 0; i < ls; ++i) {
			if (s[i] == ' ') printf(" ");
			if (s[i] >= 'a' && s[i] <= 'z') printf("%c", stable[s[i] - 'a']);
		}
		printf("\n");
	}
}
