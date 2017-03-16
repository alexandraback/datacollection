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
#include <sstream>

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

int vys;

void rec(int i, int pole[], int a, int b, int max, int akt, int p) {
	if (i >= p) {
		if (akt > vys) {
			vys = akt;
		}
		//cout << "hej" << endl;
	}
	else
		for (int ii = 0; ii <= a; ii++) {
			rec(i + 1, pole, min(a - ii + b, max), b, max, akt + (ii * pole[i]), p);
		}
}

int main () {
	int pocet, i, a1, a2, a3, ii, iii, draw, j, a, b, pole[12], pocet2, y, ok, z, iiii, iiiii, uz;
	long long p1, p2;
	string r;
	
	string str;
	cin >> pocet;
	cin >> pocet;
	cin >> a;
	cin >> b;
	cin >> j;
	for (i = 0; i < pocet; i++) {
		stringstream ss;
		for (ii = 0; ii <  j; ii++)
			cin >> pole[ii];
		uz = 0;
		for (ii = 2; ii <= b; ii++) {
			for (iii = 2; iii <= b; iii++) {
				for (iiii = 2; iiii <= b; iiii++) {
					ok = 1;
					for (iiiii = 0; iiiii < j; iiiii++) {
						if (ii * iii * iiii != pole[iiiii] && ii * iii != pole[iiiii] && ii * iiii != pole[iiiii] && iii * iiii != pole[iiiii] && ii != pole[iiiii]
						&& iii!= pole[iiiii] && iiii != pole[iiiii] && 1 != pole[iiiii])
							ok = 0;
					}
					if (ok == 1 && uz == 0) {
						//ss.clear();
						ss << ii << iii << iiii;
						//str.clear();
						str = ss.str();
						uz = 1;
					}
				}
			}
		}
		
		//rec(0, pole, a, b, a, 0, pocet2);
		if (i == 0)
			cout << "Case #" << i + 1 << ":" << endl << str << endl;
		else
			cout << str << endl;

	}
	return 0;
}
