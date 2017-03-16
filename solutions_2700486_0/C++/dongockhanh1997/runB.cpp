#include<cstdio>
#include<cstdlib>

char s[100];
int main() {
	int T; scanf("%d", &T);
	for(int i = 1; i <= T; ++i) {
		int n, x, y; scanf("%d%d%d", &n, &x, &y);
		FILE * inp = fopen("input.txt", "w");
		fprintf(inp, "%d %d %d\n", n, x, y);
		fclose(inp);
		system("./B.exec < input.txt > output.txt");
		FILE * out = fopen("output.txt", "r");
		fscanf(out, "%s", s);
		fclose(out);
		printf("Case #%d: %s\n", i, s);
	}
	return 0;
}
