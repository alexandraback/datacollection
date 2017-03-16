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

int check(string x, int n) {
	int pom = 0, pom2 = 0, vys = 0, ok;
	for (int i = 0; i < x.size(); i++) {
		ok = 1;
		for (int ii = 0; ii < 5; ii++)
			if (x[i] == zle[ii])
				ok = 0;
		if (ok == 1)
			pom++;
		else {
			if (pom > pom2)
				pom2 = pom;
			pom = 0;
		}
		if (pom >= n || pom2 >= n)
			vys++;
	}
	return vys;
}

int main () {
	int pocet, i, a1, a2, a3, ii, iii, draw, j, pali[5], y, z, pom, last_start, last_end, n, ok;
	long long p1, p2, a, b, vys;
	string r, o;
	cin >> pocet;
	zle[0] = 'a';
	zle[1] = 'e';
	zle[2] = 'i';
	zle[3] = 'o';
	zle[4] = 'u';
	for (i = 0; i < pocet; i++) {
		cin >> r;
		cin >> n;
		vys = 0;
		pom = 0;
		last_start = -1;
		last_end = 0;
		for (ii = 0; ii < r.size(); ii++) {
			ok = 1;
			for (iii = 0; iii < 5; iii++)
				if (zle[iii] == r[ii])
					ok = 0;
			if (ok == 1)
				pom++;
			else 
				pom = 0;
			if (pom >= n) {
				a1 = ii - n + 1;
				a2 = ii;
				if (a1 - last_start > 0)
					y = a1 - last_start;
				else
					y = 1;
				z = r.size() - a2;
				p1 = z * y;
				vys = vys + p1;
				last_start = a1;
			}
		}
		cout << "Case #" << i + 1 << ": " << vys << endl;
	}
	return 0;
}
