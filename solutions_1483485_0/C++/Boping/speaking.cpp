#include <cstdio>

char key[27] = "yhesocvxduiglbkrztnwjpfmaq"; // deduced from sample

int main() {
	FILE * fin = fopen("speaking.in", "r"), * fout = fopen("speaking.out", "w");
	int T, t, c;
	fscanf(fin, "%d\n", &T);
	for (t = 1; t <= T; ++t) {
		fprintf(fout, "Case #%d: ", t);
		while ((c = getc(fin)) != '\n') {
			if (c != ' ') {
				putc(key[c - 'a'], fout);
			} else {
				putc(' ', fout);
			}
		}
		putc('\n', fout);
	}
	return 0;
}