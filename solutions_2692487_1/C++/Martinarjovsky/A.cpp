#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin ("A.in");
ofstream fout ("A.out");

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define pb push_back
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()

int main() {
	int T, c, i, temp, res;
	fin >> T;
	int n = 0, run;
	vi M;
	vi b;
	int A;
	int N;

	for (c = 1; c <= T; c++) {
		M.clear();
		b.clear();
		n = 0;
		run = 0;

		fin >> A >> N;
		for (i = 0; i < N; i++) {
			fin >> temp;
			b.pb(temp);
		}
		if (A == 1) {
			fout << "Case #" << c <<": " << N << endl;
			continue;
		}

		sort (all(b));

		while (run < N) {
			if (b[run] >= A) {
				M.pb(N-run+n);
				while (b[run] >= A) {
					A += A - 1;
					n++;
				}
				A = A + b[run];
				run++;
			}
			else {
				A = A + b[run];
				run++;
			}
		}

		res = n;
		for (i = 0; i < sz(M); i++) {
			if (res > M[i]) res = M[i];
		}

		fout << "Case #" << c <<": " << res << endl;
	}

	return 0;
}
