#include <stdio.h>
#include <assert.h>

char a[16][16];
bool czyPelna;

bool jestWynik(int x, int o, int t, int test) {
	if (x + t == 4) {
		printf("Case #%d: X won\n", test + 1);
		return true;
	}
	if (o + t == 4) {
		printf("Case #%d: O won\n", test + 1);
		return true;
	}
	return false;
}

bool ocenPoziom(int wiersz, int test) {
	int x = 0, o = 0, t = 0;
	for (int i = 0; i < 4; ++i)
		switch (a[wiersz][i]) {
			case 'X': ++x; break;
			case 'O': ++o; break;
			case '.': czyPelna = false; break;
			case 'T': ++t; break;
			default: assert(0 ==1 && "chyba widzialem koteczka");
		}
	return jestWynik(x, o , t, test);
}

bool ocenPion(int kolumna, int test) {
	int x = 0, o = 0, t = 0;
	for (int i = 0; i < 4; ++i)
		switch (a[i][kolumna]) {
			case 'X': ++x; break;
			case 'O': ++o; break;
			case 'T': ++t; break;
			case '.': czyPelna = false; break;
			default: assert(0 ==1 && "chyba widzialem koteczka");
		}
	return jestWynik(x, o , t, test);
}

bool ocenPrzekantne(int test) {
	int x = 0, o = 0, t = 0;
	for (int i = 0; i < 4; ++i)
		switch (a[i][i]) {
			case 'X': ++x; break;
			case 'O': ++o; break;
			case 'T': ++t; break;
			case '.': czyPelna = false; break;
			default: assert(0 ==1 && "chyba widzialem koteczka");
		}
//	printf("---> %d,%d,%d\n", x,o,t);
	bool wyn = jestWynik(x, o , t, test);
	if (wyn)
		return true;
	x = o = t = 0;
	for (int i = 0; i < 4; ++i)
		switch (a[3-i][i]) {
			case 'X': ++x; break;
			case 'O': ++o; break;
			case 'T': ++t; break;
			case '.': czyPelna = false; break;
			default: assert(0 ==1 && "chyba widzialem koteczka");
		}
//	printf("2---> %d,%d,%d\n", x,o,t);
	return jestWynik(x, o , t, test);
}

int main() {
	int testy;
	scanf("%d\n",&testy);
	for (int t = 0; t < testy; ++t) {
		czyPelna = true;
		bool jestWynik = false;
		for (int i =0 ;i < 4; ++i)
			gets(a[i]);
		
		for (int i = 0; i < 4 && !jestWynik; ++i)
			jestWynik = ocenPoziom(i,t);
		for (int i = 0; i < 4 && !jestWynik; ++i)
			jestWynik = ocenPion(i,t);

		if (!jestWynik)
			jestWynik = ocenPrzekantne(t);

		if (!jestWynik) {
			if (czyPelna)
				printf("Case #%d: Draw\n", t + 1);
			else
				printf("Case #%d: Game has not completed\n", t + 1);
		}

//		for (int i =0 ;i < 4; ++i){
//			for (int j = 0; j < 4; ++j)
//				printf("%c", a[i][j]);
//			printf("\n");
//		}
		gets(a[4]);

	}
	return 0;
}
