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
#include <queue>
#include <fstream>

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

int main() {
	int i, pocet, ii, n, ok, iii, pom, vys, a, b, c;
	vector<string> st, st2;
	vector<int> pom2;
	vector<vector<int> > pocty;
	string s;
	double pom3;
	char last;
	cin >> pocet;
	for (i = 0; i < pocet; i++) {
		cin >> a;
		cin >> b;
		cin >> c;
		vys = 0;
		for (ii = 0; ii < a; ii++) {
			for (iii = 0; iii < b; iii++) {
				if ((ii & iii) < c)
					vys++;
			}
		}
		cout << "Case #" << i + 1 << ": " << vys << endl;
	}
  	return 0;
}