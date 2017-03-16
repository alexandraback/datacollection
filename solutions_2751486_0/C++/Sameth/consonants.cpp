#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main () {
	int n, T, dlzka, pocitadlo;
	vector <int> spracuvampozicie;
	long long vysledok;
	char samohlasky [] = {'a', 'e', 'i', 'o', 'u'};
	bool jesam;
	string s;
	scanf("%d ", &T);
	for (int testujem = 0; testujem < T; testujem ++) {
		cin >> s;
		vysledok = 0;
		pocitadlo = 0;
		scanf("%d ", &n);
		dlzka = s.size();
		for (int i = 0; i < dlzka; i++) {
			jesam = false;
			for (int j = 0; j < 5; j++) {
				if (s [i] == samohlasky [j]) jesam = true;
			}
			if (jesam) pocitadlo = 0;
			else pocitadlo ++;
			if (pocitadlo >= n) {
				spracuvampozicie.push_back(i);
			}
		}
		spracuvampozicie.push_back (dlzka);
		for (int i = 0; i < (int) spracuvampozicie.size() - 1; i++) {
			vysledok += (spracuvampozicie [i] - n + 2) * (spracuvampozicie [i + 1] - spracuvampozicie [i]);
		}
//		if (!spracuvampozicie.empty()) vysledok += spracuvampozicie.back() - n + 2;
		spracuvampozicie.clear();
		printf("Case #%d: %lld\n", testujem + 1, vysledok);
	}
	return 0;
}