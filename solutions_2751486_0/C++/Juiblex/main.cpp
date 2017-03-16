#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int LEN = 1000*1000+1;

bool consonne(char c) {
	return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main(void) {
	int tests;
	scanf("%d", &tests);
	for (int iTest = 0; iTest < tests; iTest++) {
		int largeur, taille;
		int consonnes = 0;
		char nom[LEN];
		long long int total = 0;
		vector<int> debuts;
		scanf(" %s%d", nom, &largeur);
		taille = strlen(nom);
		for (int fin = 0; fin < taille; fin++) {
			if (consonne(nom[fin]))
				consonnes++;
			if (fin - largeur >= 0 && consonne(nom[fin-largeur]))
				consonnes--;
			if (consonnes >= largeur)
				debuts.push_back(fin-largeur+1);
		}
		for (int deb = 0; deb < debuts.size(); deb++) {
			long long devant = debuts[deb], derriere = taille-(debuts[deb]+largeur);
			if (deb > 0)
				devant -= debuts[deb-1]+1;
			total += (devant+1) * (derriere+1);
		}
		printf("Case #%d: %lld\n", iTest+1, total);
	}
	return 0;
}
