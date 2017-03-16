#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin ("C.in");
ofstream fout ("C.out");

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define pb push_back
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()


struct attack {
	int w, e, d, s;
};

bool firstat (attack a, attack b) {
	return a.d < b.d;
}

int main() {
	int T, c, i, N, j;
	fin >> T;
	int d, w, e, n, s, deltad, deltap, deltas, res;
	vi height, nexth;
	attack x;
	vector<attack> at;
	bool succ;

	for (c = 1; c <= T; c++) {
		height.resize(2001, 0);
		fin >> N;
		for (i = 0; i < N; i++) {
			fin >> d >> n >> w >> e >> s >> deltad >> deltap >> deltas;
			x.w = w;
			x.e = e;
			x.d = d;
			x.s = s;
			at.pb(x);
			for (j = 1; j < n; j++) {
				x.w += deltap;
				x.e += deltap;
				x.d += deltad;
				x.s += deltas;
				at.pb(x);
			}
		}

		sort (all(at), firstat);

		res = 0;
		d = at[0].d;
		nexth = height;
		for (i = 0; i < sz(at); i++) {
			x = at[i];
			if (x.d != d) {
				height = nexth;
				d = x.d;
			}
			succ = false;
			for (j = x.w; j < x.e; j++) {
				if (x.s > height[j+1000]) {
					succ = true;
					if (nexth[j+1000] < x.s) {
						nexth[j+1000] = x.s;
					}
				}
			}
			if (succ) res++;

//			if (succ) fout << 1 << ' ';
//			else fout << 0 << ' ';
//			fout << x.d << ' ' << x.s << ' ' << x.w << ' ' << x.e << endl;
		}

		fout << "Case #" << c <<": " << res << endl;

		nexth.clear();
		height.clear();
		at.clear();
	}

	return 0;
}
