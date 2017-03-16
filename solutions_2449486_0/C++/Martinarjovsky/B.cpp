#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin ("B.in");
ofstream fout ("B.out");

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define pb push_back
#define sz(a) int((a).size()
#define all(c) (c).begin(),(c).end()

int main() {
	int T, M, N, c, i, j, q;
	bool yes1, yes2, can;
	vvi loan;

	fin >> T;
	for (c = 1; c <= T; c++) {
		fin >> N >> M;
		loan.clear();
		loan.resize(N, vi(M, 0));

		for (i = 0; i < N; i ++) {
			for (j = 0; j < M; j++) {
				fin >> loan[i][j];
			}
		}

		for (i = 0; i < N; i ++) {
			for (j = 0; j < M; j++) {
				can = true;
				yes1 = true;
				yes2 = true;
				for (q = 0; q < N; q++) {
					if (loan[q][j] > loan[i][j]) {
						yes1 = false;
						break;
					}
				}
				for (q = 0; q < M; q++) {
					if (loan[i][q] > loan[i][j]) {
						yes2 = false;
						break;
					}
				}
				if (!yes2 && !yes1) {
					can = false;
					break;
				}
			}
			if (!can) {
				break;
			}
		}

		if (!can) {
			fout << "Case #" << c << ": NO" << endl;
		}
		else {
			fout << "Case #" << c << ": YES" << endl;
		}

	}
}
