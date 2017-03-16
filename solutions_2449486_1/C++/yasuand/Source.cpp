#include<iostream>
#include<vector>
using namespace std;

#define rep(i, from, to) for (i = from; i < to; ++i)

int main()
{
	int t;
	cin >> t;
	int i, j, k;
	rep (i, 0, t) {
		int n, m;
		cin >> n >> m;
		vector<vector<int> > field(n);
		rep (j, 0, n) {
			field[j].resize(m);
			rep (k, 0, m) {
				cin >> field[j][k];
			}
		}
		vector<int> ymax(m, 0);
		vector<int> tmax(n, 0);
		rep (j, 0, n) {
			rep (k, 0, m) {
				tmax[j] = max(tmax[j], field[j][k]);
				ymax[k] = max(ymax[k], field[j][k]);
			}
		}
		bool flg = true;
		rep (j, 0, n) {
			rep (k, 0, m) {
				if (field[j][k] != min(tmax[j], ymax[k])) {
					flg = false;
				}
			}
		}
		if (flg) {
			cout << "Case #" << i + 1 << ": YES\n";
		} else {
			cout << "Case #" << i + 1 << ": NO\n";
		}
	}
	return 0;
}