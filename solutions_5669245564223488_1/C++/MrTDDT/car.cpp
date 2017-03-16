#include <cstdio>
#include <vector>
#include <cstring>

struct Car {
	int p, k, id;
	
	Car () {p = k = 0;}
	Car (int _p, int _k, int _id) {p = _p; k = _k; id = _id;};
};
long long int t, n, PODSTAWA = 1000000009, ret;
int il_zak [27], il_jeden [27], il_roznych, il_poczatek [27], il_koniec [27], kolejnosc [27], poczatek, koniec;
char in [200];
std::vector <Car> car_akt;

int main () {
	scanf ("%lld", &t);
	for (int q = 0; q < t; q ++) {
		scanf ("%lld", &n);
		for (int i = 0; i < 27; i ++) il_jeden [i] = il_zak [i] = il_poczatek [i] = il_koniec [i] = poczatek = koniec = 0;
		car_akt.clear ();
		il_roznych = 0;
		ret = 0;

		for (int i = 0; i < n; i ++) {
			scanf ("%s", in);

			bool jeden = true;
			for (int i = 1; i < strlen (in); i ++) {
				if (in [i] != in [i-1]) {
					jeden = false;
					if (in [i] != in [strlen (in) - 1]) il_zak [(int) in [i] - 'a'] ++;
				}

			}

			if (jeden) {
				il_jeden [(int) in [0] - 'a'] ++;
			} else {
				car_akt.push_back (Car ((int) in [0] - 'a', (int) in [strlen (in) - 1] - 'a', i));
				il_poczatek [car_akt [car_akt.size () - 1].p] ++;
				il_koniec   [car_akt [car_akt.size () - 1].k] ++;
			}
		}
		bool nie_da_sie = false;
		bool same_zera = true;
		for (int i = 0; i < 27 && !nie_da_sie; i ++) {
			if (il_poczatek [i] > 1 || il_koniec [i] > 1 || (il_zak [i] != 0 && (il_jeden [i] != 0 || il_poczatek [i] != 0 || il_koniec [i] != 0))) nie_da_sie = true;
		}
		if (nie_da_sie) {
			printf ("Case #%d: 0\n", q+1);
		} else {
			for (int i = 0; i < 27; i ++) 
				if (il_poczatek [i] == 0 && il_koniec [i] == 0 && il_zak [i] == 0 && il_jeden [i] != 0) il_roznych ++;
			for (int i = 0; i < 27; i ++) {
				if (il_poczatek [i] == 1 && il_koniec [i] == 0) poczatek ++;
				if (il_koniec [i] == 1 && il_poczatek [i] == 0) koniec ++;
				if (il_poczatek [i] != 0 || il_koniec [i] != 0) same_zera = false;
			}

			if ((poczatek == koniec && poczatek != 0) || same_zera) {
				il_roznych += poczatek;
				ret = 1;
//				printf ("%d maxa roznych\n", il_roznych);
				for (int i = 1; i <= il_roznych; i ++) ret = (ret*i)%PODSTAWA;
				for (int i = 0; i < 27; i ++) {
					for (int k = 1; k <= il_jeden [i]; k ++) ret = (ret*k)%PODSTAWA;
//					if (il_jeden [i] > 1) printf ("%d kolejny rozny\n", il_jeden [i]);
				}
				printf ("Case #%d: %lld\n", q+1, ret);

			} else {
				printf ("Case #%d: 0\n", q+1);
			}
		
		}	
	}
	return 0;
}
