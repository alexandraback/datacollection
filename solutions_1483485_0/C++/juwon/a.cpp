#include <cstdio>
#include <cstring>

char t[30] = {"yhesocvxduiglbkrztnwjpfmaq"};

int main() {
	int r, cs = 0;
	char line[200];
	scanf("%d", &r);
	gets(line);
	while (r--) {
		printf("Case #%d: ", ++cs);
		gets(line);
		int n = strlen(line);
		for (int i = 0; i < n; ++i) {
			if (line[i] != ' ') line[i] = t[line[i] - 'a'];
			printf("%c", line[i]);
		}
		printf("\n");
	}
	return 0;
}
