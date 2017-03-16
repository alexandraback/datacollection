#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <math.h>
#include <string>
#include <string.h>
#include <iomanip>
#include <map>

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)

using namespace std;

int main() {

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int t, T, i, j, k, N, J, P, S, K, k2, ii, Scount, Scount2, Pcount, Pcount2, j2;
	int combs[1000][3];
	std::map<int, int> JP;
	std::map<int, int> PS;
	std::map<int, int> JS;

	fin >> T;
	for1(t, T) {

		cout << "Case #" << t << ": ";
		fout << "Case #" << t << ": ";

		fin >> J >> P >> S >> K;

		memset(combs, true, sizeof(combs[0]) * 27 * 3);

		for1(i,J)
			for1(j,P)
			for1(k, S) {
			JP[i * 100 + j] = 0;
			PS[j * 100 + k] = 0;
			JS[i * 100 + k] = 0;
		}

		ii = 0;
		Scount = 0;
		for1(i, J) {
			for (j = P; j >= 1;j--) {


				forn(k, S) {

					k2 = (k + Scount) % S + 1;

					if (JP[i * 100 + j] < K && PS[j * 100 + k2] < K && JS[i * 100 + k2] < K) {
						combs[ii][0] = i;
						combs[ii][1] = j;
						combs[ii][2] = k2;
						ii++;
						JP[i * 100 + j]++;
						PS[j * 100 + k2]++;
						JS[i * 100 + k2]++;
						Scount2 = k2;
					}
				}
				Scount = Scount2;
			}
		}

		cout << ii <<' '<< J << ' ' << P << ' ' << S << ' ' << K << endl;
		fout << ii << endl;// << ' ' << J << ' ' << P << ' ' << S << ' ' << K << endl;
		forn(i, ii) {
			cout << combs[i][0] << ' ' << combs[i][1] << ' ' << combs[i][2] << endl;
			fout << combs[i][0] << ' ' << combs[i][1] << ' ' << combs[i][2] << endl;
		}



	}

	return 0;
}