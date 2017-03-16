#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

#define e '\n'
#define INF 1023456789
#define ll long long

//#define FILE "seif"

#ifdef FILE
ifstream f(string (string(FILE) + ".in").c_str());
ofstream g(string (string(FILE) + ".out").c_str());
#endif
#ifndef FILE
#define f cin
#define g cout
#endif

string s1, s2, s3;
int i, ii, j, n, m, t, k;
string str[1000];
char cc[1000];
int vv[1000];
bool wrong;
char aux;


int x, y, z;
int rez;

int main() {

	f >> t;
	for (ii=1; ii<=t; ii++) {

		f >> x >> y >> z;
		rez = 0;

		for (i=0; i<x; i++) {
			for (j=0; j<y; j++) {
				if ((i & j) < z) {
					rez++;
				}
			}
		}


		g << "Case #" << ii << ": " << rez << e;
	}


	return 0;

}
