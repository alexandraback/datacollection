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

int main () {
	int pocet, i, a1, a2, a3, ii, iii, draw, j, a, b, pali[5], vys, y, z;
	long long p1, p2;
	string r;
	cin >> pocet;
	for (i = 0; i < pocet; i++) {
		cin >> a;
		cin >> b;
		a = (a + 1) * (a + 1) - a * a;
		y = 2 * b;
		z = 4 - 2 * a;
		p1 = (long long)(z + sqrt((double)pow(z, 2) + 16.0 * (double)y)) / 8.0;
		//cout << p1 << endl;
		p2 = (long long)(z - sqrt((double)pow(z, 2) + 16.0 * (double)y)) / 8.0;
		//cout << p2 << endl;
		if (p1 < p2)
			p1 = p2;
		p1 = trunc(p1);
		cout << "Case #" << i + 1 << ": " << p1 << endl;
	}
	return 0;
}
