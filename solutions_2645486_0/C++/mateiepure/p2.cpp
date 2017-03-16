#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

ifstream in("p2.in");
ofstream out("p2.out");

const int N = 100001;
const int M = 21;

int rez[M][N];
int v[N];

int solve(int e, int r, int n) {
	memset(rez, 0, sizeof(rez));

	for (int i = 1; i <= n; ++i)
		for (int j = e; j >= 0; --j)
			for (int k = j; k >= 0; --k) {
				int goin = j - k + r;
				if (goin > e)
					goin = e;
				if (rez[i][goin] < rez[i-1][j] + v[i] * k)
					rez[i][goin] = rez[i-1][j] + v[i] * k;
			}

	int best = 0;
	for (int i = 0; i <= e; ++i)
		if (rez[n][i] > best)
			best = rez[n][i];

	return best;
}

int main() {
	int t;
	in >> t;

	for (int i = 1; i <= t; ++i) {
		if (i == 90)
			i = 90;
		int e, r, n;
		in >> e >> r >> n;
		for (int j = 1; j <= n; ++j)
			in >> v[j];

		out << "Case #" << i << ": " << solve(e, r, n) << "\n";
	}

	return 0;
}
