#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>
#include <bitset>
#include <list>
#include <queue>
#include <sstream>

using namespace std;

#define e '\n'
#define INF 1023456789
#define ll long long

//#define FILE "data"

#ifdef FILE
ifstream f(string (string(FILE) + ".in").c_str());
ofstream g(string (string(FILE) + ".out").c_str());
#endif
#ifndef FILE
#define f cin
#define g cout
#endif

ll mul_inv(ll a, ll b)
{
	ll b0 = b, t, q;
	ll x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

ll t, n, rez, x, m, k;
int i, j, ii;
string s, s1, s2;

int v[55][55];

vector< vector<int> * > res;
int bktArray[5];
ll wear[16][5][5];
int a[5];

void bkt(int position) {

	if (position == 4) {

		bool canDo = true;

		for (int i = 1; i <= 3; i++) {
			for (int j = i + 1; j <= 3; j++) {
				if (wear[i * 3 + j][bktArray[i]][bktArray[j]] == 0) {
					canDo = false;
					break;
				}
			}
		}

		if(canDo) {
			vector<int> * newSol = new vector<int>();
			newSol->push_back(bktArray[1]);
			newSol->push_back(bktArray[2]);
			newSol->push_back(bktArray[3]);

			res.push_back(newSol);

			for (int i = 1; i <= 3; i++) {
				for (int j = i + 1; j <= 3; j++) {
					wear[i * 3 + j][bktArray[i]][bktArray[j]]--;
				}
			}

		}
	}

	for (int i = 1; i <= a[position]; i++) {
		bktArray[position] = i;
		bkt(position + 1);
	}
}

int main() {
	f >> t;

	for (int ii = 1; ii <= t; ii++) {
		f >> a[1] >> a[2] >> a[3] >> k;

		res.clear();
		for (i = 1; i <= 3; i++) {
			bktArray[i] = 0;
		}

		for (int l = 1; l <= 9; l++) {
			for (i = 1; i <= 3; i++) {
				for (j = 1; j <= 3; j++) {
					wear[l][i][j] = k;
				}
			}

		}

		int oldSz = -1000;
		while ((int) res.size() - oldSz> 1) {
			oldSz = (int) res.size();
			bkt(1);
		}

		g << "Case #" << ii << ": " << res.size() << e;
		for (vector<vector<int> * >::iterator it = res.begin(); it != res.end(); it++) {
			g << (**it)[0] << " " << (**it)[1] << " " << (**it)[2] << e;
			delete (*it);
		}
	}
}

