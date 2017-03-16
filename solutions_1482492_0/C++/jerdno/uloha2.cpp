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

using namespace std;

#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define SZ size

int vys;
int farba[1100];
int hrany[1100][20];
int pocet[1100];

void dfs(int akt, int farb) {
	int i, pocet2 = pocet[akt];
	farba[akt] = farb;
	for (i = 0; i < pocet2; i++) {
		if (farba[hrany[akt][i]] != farb) {
			dfs(hrany[akt][i], farb);
		} else if (farba[hrany[akt][i]] == farb) {
			//cout << akt + 1 << ' ' << hrany[akt][i] << endl;
			vys = 1;
		}
	}
}

int main () {
	int ii, pocet2, N, M, j, k, i;
	vector<double> T, X;
	double t, x, a, dlzka, pom, pom2, rychlost, cas, d;
	cin >> pocet2;
	for (i = 0; i < pocet2; i++) {
		cin >> dlzka;
		cin >> N;
		cin >> M;
		X.clear();
		T.clear();
		for (ii = 0; ii < N; ii++) {
			cin >> t;
			cin >> x;
			T.PB(t);
			X.PB(x);
		}
		if (X[N-1] > dlzka) {
			pom = (X[N-1] - X[N-2]) / (T[N-1] - T[N-2]);
			pom2 = (dlzka - X[N-2]) / pom;
			T[N-1] = T[N-2] + pom2;
			X[N-1] = dlzka;
			//cout << pom << endl;
		}
		cout << "Case #" << i + 1 << ":" << endl;
		for (ii = 0; ii < M; ii++) {
			rychlost = 0.0;
			cin >> a;
			d = 0.0;
			cas = sqrt(dlzka * 2 / a);
			if (cas < T[N-1]) {
				cas = T[N-1];
			}
			printf("%.6lf\n", cas);
		}
	}
	return 0;
}