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
	int pocet, i, a1, a2, a3, ii, iii, draw, j, a, b, pole[12], pocet2, y, z;
	long long p1, p2;
	string r;
	cin >> pocet;
	for (i = 0; i < pocet; i++) {
		cin >> a;
		cin >> b;
		cin >> pocet2;
		vys = 0;
		for (ii = 0; ii <  pocet2; ii++)
			cin >> pole[ii];
		
		rec(0, pole, a, b, a, 0, pocet2);
		cout << "Case #" << i + 1 << ": " << vys << endl;
	}
	return 0;
}
