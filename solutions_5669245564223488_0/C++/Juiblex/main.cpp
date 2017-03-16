#include <cstdio>
#include <vector>
#include <string>
using namespace std;

const int BIGNUM = 1000000007;
const int CHAINES = 100;
const int TAILLE = 102;

char chaines[CHAINES][TAILLE];

vector<int> voitures;
int nbVoitures;

inline bool peutRajouter(int voit) {
	for (int i = 0; i < voitures.size(); i++)
		if (voitures[i] == voit)
			return false;
	return true;
}

int valide() {
	string train;
	bool vue[26], finie[26];
	for (int i = 0; i < voitures.size(); i++)
		train.append(chaines[voitures[i]]);
	for (int i = 0; i < 26; i++)
		vue[i] = finie[i] = false;
	for (int pos = 0; pos < train.size(); pos++) {
		if (vue[train[pos]-'a'] == false) {
			vue[train[pos]-'a'] = true;
			if (pos > 0)
				finie[train[pos-1]-'a'] = true;
		} else if (finie[train[pos]-'a'])
			return false;
	}
	return true;
}

int genere(int pos) {
	int ok = valide(), total = 0;
	if (pos == nbVoitures)
		return ok;
	if (ok == 0)
		return 0;
	for (int voit = 0; voit < nbVoitures; voit++)
		if (peutRajouter(voit)) {
			voitures.push_back(voit);
			total += genere(pos+1);
			total %= BIGNUM;
			voitures.pop_back();
		}
	return total % BIGNUM;
}

int main(void) {
	int nbTests;
	scanf("%d", &nbTests);
	for (int test = 1; test <= nbTests; test++) {
		scanf("%d", &nbVoitures);
		for (int i = 0; i < nbVoitures; i++)
			scanf("%s", chaines[i]);
		printf("Case #%d: %d\n", test, genere(0));
	}
	return 0;
}
