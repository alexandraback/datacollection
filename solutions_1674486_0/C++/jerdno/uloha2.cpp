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
	int i, pocet2, N, M, ii, j, k;
	cin >> pocet2;
	for (i = 0; i < pocet2; i++) {
		cin >> N;
		vys = 0;
		for (ii = 0; ii < N; ii++) {
			cin >> M;
			farba[ii] = 0;
			pocet[ii] = M;
			//hrany[ii].clear();
			for (j = 0; j < M; j++) {
				cin >> k;
				//cout << k << endl;
				//hrany[ii].PB(k);
				hrany[ii][j] = k - 1;
			}
		}
		for (ii = 0; ii < N; ii++) {
			if (farba[ii] == 0) {
				dfs(ii, ii + 1);
			}
		}
		if (vys == 1) {
			cout << "Case #" << i + 1 << ": Yes" << endl;
		} else {
			cout << "Case #" << i + 1 << ": No" << endl;
		}
	}
	return 0;
}