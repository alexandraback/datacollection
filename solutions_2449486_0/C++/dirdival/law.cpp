#include <stdio.h>

struct {
	int wart;
	bool ciety;
}
t[128][128];
int wiersze, kolumny;

int tnijPoziomo() {
	int tnij = 0;
	for (int w = 0; w < wiersze; ++w) {
		int max = -1;
		for (int k = 0; k < kolumny; ++k)
			if (max < t[w][k].wart) max = t[w][k].wart;
		for (int k = 0; k < kolumny; ++k)
			if (t[w][k].wart ==	max && !t[w][k].ciety) {
				t[w][k].ciety = true;
				++tnij;
			}
	}
	return tnij;
}

int tnijPionowo() {
	int tnij = 0;
	for (int k = 0; k < kolumny; ++k) {
		int max = -1;
		for (int w = 0; w < wiersze; ++w)
			if (max < t[w][k].wart) max = t[w][k].wart;
		for (int w = 0; w < wiersze; ++w)
			if (t[w][k].wart ==	max && !t[w][k].ciety) {
				t[w][k].ciety = true;
				++tnij;
			}
	}
	return tnij;
}


int main() {
	int testy;
	scanf("%d",&testy);
	for (int te = 1; te <= testy; ++te) {
		int ileSciete = 0;
		scanf("%d %d", &wiersze, &kolumny);
		for (int w= 0; w < wiersze; ++w)
			for (int k = 0; k < kolumny; ++k) {
				scanf("%d", &t[w][k].wart);
				t[w][k].ciety = false;
			}
		ileSciete += tnijPoziomo();
		ileSciete += tnijPionowo();
		if (ileSciete == wiersze * kolumny)
			printf("Case #%d: YES\n", te);
		else
			printf("Case #%d: NO\n", te);
	}
	

	return 0;
}
