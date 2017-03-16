#include <iostream>
#include <map>
#include <set>
using namespace std;

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};

int C[200][200], F[200][200], H, nr, nc;

bool canmove(int r, int c, int rr, int cc) {
	if (C[rr][cc] - F[r][c] < 50) return false;
	if (C[rr][cc] - F[rr][cc] < 50) return false;
	if (C[r][c] - F[rr][cc] < 50) return false;
	return true;
}

int main() {
	int T, CN = 1;
	cin >> T;
	while (T-- && cin >> H >> nr >> nc) {
		for (int i = 0; i < nr; ++i)
			for (int j = 0; j < nc; ++j)
				cin >> C[i][j];
		for (int i = 0; i < nr; ++i)
			for (int j = 0; j < nc; ++j)
				cin >> F[i][j];

		map<pair<int, int>, int> mm;
		set<pair<int, pair<int, int> > > q;
		mm[make_pair(0, 0)] = H;
		q.insert(make_pair(-H, make_pair(0, 0)));

		int best = -1000000;
		while (!q.empty()) {
			int h = -q.begin()->first;
			int r = q.begin()->second.first;
			int c = q.begin()->second.second;
			q.erase(q.begin());

			if (r == nr-1 && c == nc-1) {
				best = h;
				break;
			}

			if (h == H) {
				for (int k = 0; k < 4; ++k) {
					int rr = r + dr[k], cc = c + dc[k];
					if (rr >= 0 && rr < nr && cc >= 0 && cc < nc) {
						if (canmove(r, c, rr, cc) && C[rr][cc] - h >= 50 &&
							(mm.find(make_pair(rr, cc)) == mm.end() ||
  							 mm[make_pair(rr, cc)] < H)) {
							mm[make_pair(rr, cc)] = H;
							q.insert(make_pair(-H, make_pair(rr, cc)));
						}
					}
				}
			}

			for (int k = 0; k < 4; ++k) {
				int rr = r + dr[k], cc = c + dc[k];
				if (rr >= 0 && rr < nr && cc >= 0 && cc < nc) {
					if (canmove(r, c, rr, cc)) {
						int w = max(0, 50 - (C[rr][cc] - h));
						int hh = h - w;
						if (h - w - F[r][c] < 20) hh -= 100;
						else hh -= 10;

						if (mm.find(make_pair(rr, cc)) == mm.end() ||
  				    		mm[make_pair(rr, cc)] < hh) {

							mm[make_pair(rr, cc)] = hh;
							q.insert(make_pair(-hh, make_pair(rr, cc)));
						}
					}
				}
			}
		}

		cout.setf(ios::fixed);
		cout.precision(5);
		cout << "Case #" << CN++ << ": " << (long double)(H-best)/10.0 << endl;
	}
}