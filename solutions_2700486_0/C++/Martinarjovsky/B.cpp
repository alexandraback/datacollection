#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin ("B.in");
ofstream fout ("B.out");

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define pb push_back
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()

#define MAXN 10010
unsigned long long int comb[MAXN+10][MAXN+10];



int main() {
	int x, y, T, i, c, n, N, j;
	double p, r;
	fin >> T;


	for (c = 1; c <= T; c++) {
		fin >> N >> x >> y;
		n = (abs(x) + y);
		N = N - (n * (n-1))/2;
//		fout << n << ' ' << N << ' ';
		if (N <= 0) {
			fout << "Case #" << c <<": " << 0.0 << endl;
			continue;
		}
		if (x == 0) {
			if (N < (n + n + 1)) {
				fout << "Case #" << c <<": " << 0.0 << endl;
				continue;
			}
			else {
				fout << "Case #" << c <<": " << 1.0 << endl;
				continue;
			}
		}
		while (N > n) {
			N -= 2;
			y --;
		}
		if (y < 0) {
			fout << "Case #" << c <<": " << 1.0 << endl;
			continue;
		}
		if (N < y + 1) {
			fout << "Case #" << c <<": " << 0.0 << endl;
			continue;
		}

//		fout << N <<' ' << y << ' ';
		p = 0.0;
		for (i = 0; i <= y; i++) {
			r = 1.0;
			for (j = 1; j <= N; j++) {
				r *= 0.5 * (double) j;
				if (j <= i) {
					r /= j;
				}
				if (j <= N - i) {
					r /= j;
				}
			}
			p += r;
		}

		p = 1.0 - p;

		fout << "Case #" << c <<": " << p << endl;

	}
}
