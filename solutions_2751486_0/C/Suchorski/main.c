#include <stdio.h>
#include <string.h>

int main() {
    FILE *fr = fopen("input.txt", "r");
    FILE *fw = fopen("output.txt", "w");
    int total, i, j, k;
    char *pP;
    fscanf(fr, "%d", &total);
    for (i = 0; i < total; ++i) {
		char palavra[1000001];
		int cons, palTam, res = 0;
		fscanf(fr, "%s %d", palavra, &cons);
		palTam = strlen(palavra);
		for (j = 0, pP = palavra; j < palTam - cons + 1; ++j, ++pP) {
			for (k = 0; k < cons; ++k) {
				if (*(pP + k) != 'a' && *(pP + k) != 'e' && *(pP + k) != 'i' && *(pP + k) != 'o' && *(pP + k) != 'u') continue;
				else break;
			}
			if (k == cons) {
				if (j == 0 || j == (palTam - cons)) { res += palTam - cons; }
				else { res += (int) (pP - palavra) * (palTam - (int) (pP - palavra) - cons + 1); }
			}
		}
		fprintf(fw, "Case #%d: %d\n", (i + 1), ++res);
    }
    return 0;
}
