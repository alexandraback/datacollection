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
#include <stack>

#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define SZ size

//map<int, int>
//pair<int, int>
//vector< pair<int, int> >
//map<int, int>::iterator it;

/*int compare (const void *a, const void *b) {
	struct Dvojice a1 = *(struct Dvojice*)a;
	struct Dvojice b1 = *(struct Dvojice*)b;
	return (a1.id-b1.id);
}*/

/*
for (i = 0; i < (1 << n); i++) {
	for (ii = 0; ii < n; ii++) {
		if (i & (1 << ii)) {
        } else {
        }
	}
}
*/
long long convert(string s) {
	int i, ii = s.SZ();
	long long pom = 1, vys = 0;
	for (i = 0; i < ii - 1; i++)
		pom = pom * 10;
	for (i = 0; i < ii; i++) {
		vys = vys + pom * (s[i] - '0');
		pom = pom / 10;
	}
	return vys;
}

long long gcd (long long a, long long b) {
  if (a == 0) 
	  return b;
  return gcd (b % a, a);
}

long long check(long long p) {
	if (p % 2 != 0)
		return p;
	return check(p / 2);
}

int main() {
	int i, ii, pocet, pocet2, pom, zac, sumaMin, sumaMax, vys;
	long long pom1, pom2, pom3;
	double pom4, pom5;
	string a;
	vector<int> min, maxV;
	vector< pair<int, int> > suma;
	cin >> pocet;
	for (i = 0; i < pocet; i++) {
		cin >> a;
		unsigned pos = a.find("/");
		pom1 = convert(a.substr(0, pos));
		pom2 = convert(a.substr(pos + 1));
		pom3 = gcd(pom1, pom2);
		pom1 = pom1 / pom3;
		pom2 = pom2 / pom3;
		if (check(pom2) != 1) {
			cout << "Case #" << i + 1 << ":" << " impossible" << endl;
			continue;
		}
		pom4 = 1;
		vys = 0;
		pom5 = (double) pom1 / (double)pom2;
		while (pom4 > pom5) {
			pom4 = pom4 / 2;
			vys++;
		}
		cout << "Case #" << i + 1 << ": " << vys << endl;
	}
	return 0;
}