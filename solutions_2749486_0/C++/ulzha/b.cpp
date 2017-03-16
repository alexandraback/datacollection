#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const char enws[] = "ENWS";
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
typedef pair<int, int> pi;
const int smax = 100;

int d[smax * 2 + 1][smax * 2 + 1];
int p[smax * 2 + 1][smax * 2 + 1];

int main() {
	int nt, it;

	{
		int x, y;
		vector<pi> q, q1;
		int i, j;

		memset(d, 0, sizeof d);
		q.push_back(pi(0, 0));

		while (q.size()) {
			for (i = 0; i < q.size(); i++) {
				int x = q[i].first, y = q[i].second, l = d[x + smax][y + smax] + 1;

				for (j = 0; j < 4; j++) {
					int x1 = x + l * dx[j], y1 = y + l * dy[j];

					if (abs(x1) <= smax && abs(y1) <= smax) {
						if ((x1 || y1) && !d[x1 + smax][y1 + smax]) {
							d[x1 + smax][y1 + smax] = l;
							q1.push_back(pi(x1, y1));
							p[x1 + smax][y1 + smax] = j;
						}
					}
				}
			}
			q = q1;
			q1.clear();
		}

		// for (i = 10; i >= -10; i--) {
		// 	for (j = -10; j <= 10; j++) {
		// 		cout << setw(3) << d[j + smax][i + smax];
		// 	}
		// 	cout << endl;
		// }
	}

	cin >> nt;
	for (it = 1; it <= nt; it++) {
		int x, y;
		string r;

		cin >> x >> y;

		while (x || y) {
			int j = p[x + smax][y + smax], l = d[x + smax][y + smax];
			int x0 = x - l * dx[j], y0 = y - l * dy[j];

			r += enws[j];
			x = x0, y = y0;
		}
		reverse(r.begin(), r.end());

		cout << "Case #" << it << ": " << r << endl;
	}
}
