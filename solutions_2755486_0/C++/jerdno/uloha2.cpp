#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>

#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
//#include <random>
#include <time.h>

using namespace std;

#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define SZ size

char zle[5];

typedef struct utok {
	int den, pocet, x1, x2, sila, oddych, cesta, zmena_sila;
} UTOK;


int main () {
	int pocet, i, a1, a2, a3, ii, iii, draw, j, pali[5], vys, y, z, x, kon, den, pom;
	long long p1, p2, a, b;
	UTOK utoky[20];
	int stena[1000], stena2[1000];
	vector<int> akt;
	string r, o;
	cin >> pocet;
	for (i = 0; i < pocet; i++) {
		cin >> x;
		y = 0;
		for (ii = 0; ii < x; ii++) {
			cin >> utoky[ii].den >> utoky[ii].pocet >> utoky[ii].x1
				>> utoky[ii].x2 >> utoky[ii].sila >> utoky[ii].oddych >>
				utoky[ii].cesta >> utoky[ii].zmena_sila;
			/*cout << utoky[ii].den << utoky[ii].pocet << utoky[ii].x1
				<< utoky[ii].x2 << utoky[ii].sila << utoky[ii].oddych <<
				utoky[ii].cesta << utoky[ii].zmena_sila << endl;*/
			utoky[ii].x1 = utoky[ii].x1 + 500;
			utoky[ii].x2 = utoky[ii].x2 + 500;
		}
		for (ii = 0; ii < 1000; ii++) {
			stena[ii] = 0;
			stena2[ii] = 0;
		}
		kon = 0;
		vys = 0;
		while (kon == 0) {
			den = -1;
			for (ii = 0; ii < x; ii++) {
				if (utoky[ii].pocet > 0) {
					if (den == -1 || utoky[ii].den < den) {
						akt.clear();
						akt.PB(ii);
						den = utoky[ii].den;
					} else if (utoky[ii].den == den) {
						akt.PB(ii);
					}
				}
			}
			for (ii = 0; ii < akt.SZ(); ii++) {
				pom = 0;
				for (iii = utoky[akt[ii]].x1; iii <= utoky[akt[ii]].x2; iii++) {
					if (stena[iii] < utoky[akt[ii]].sila)
						pom = 1;
				}
				for (iii = utoky[akt[ii]].x1; iii < utoky[akt[ii]].x2; iii++) {
					if (stena2[iii] < utoky[akt[ii]].sila)
						pom = 1;
				}
				if (pom == 1) {
					vys++;
					//cout << den << " " << utoky[akt[ii]].sila << " " << utoky[akt[ii]].x1 << " " << utoky[akt[ii]].x2 << endl;
				}
			}
			for (ii = 0; ii < akt.SZ(); ii++) {
				for (iii = utoky[akt[ii]].x1; iii <= utoky[akt[ii]].x2; iii++) {
					stena[iii] = max(utoky[akt[ii]].sila, stena[iii]);
				}
				for (iii = utoky[akt[ii]].x1; iii < utoky[akt[ii]].x2; iii++) {
					stena2[iii] = max(utoky[akt[ii]].sila, stena[iii]);
				}
				utoky[akt[ii]].den += utoky[akt[ii]].oddych;
				utoky[akt[ii]].sila += utoky[akt[ii]].zmena_sila;
				utoky[akt[ii]].x1 += utoky[akt[ii]].cesta;
				utoky[akt[ii]].x2 += utoky[akt[ii]].cesta;
				utoky[akt[ii]].pocet--;
			}
			kon = 1;
			for (ii = 0; ii < x; ii++) {
				if (utoky[ii].pocet > 0)
					kon = 0;
			}
		}
		cout << "Case #" << i + 1 << ": " << vys << endl;
	}
	return 0;
}