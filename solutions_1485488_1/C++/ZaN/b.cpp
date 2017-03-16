#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;

double max_time = 1e9;

struct Data {
	Data(int i, int j, double t): i(i), j(j), t(t) {}
	int i, j;
	double t;
	bool operator<(const Data& rhs) const { return t > rhs.t; }
};

int main() {
	int num_tests;
	cin >> num_tests;
	for (int test = 1; test <= num_tests; ++test) {
		double h;
		int n, m;
		cin >> h >> n >> m;
		int c[100][100];
		int f[100][100];
		double d[100][100];
		bool v[100][100];
		priority_queue<Data, vector<Data> > q;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> c[i][j];
				v[i][j] = false;
				d[i][j] = max_time;
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> f[i][j];
			}
		}
		d[0][0] = 0.0;
		q.push(Data(0, 0, 0.0));
		while (!v[n - 1][m - 1]) {
			Data top = q.top();
			q.pop();
			if (v[top.i][top.j]) {
				continue;
			}
			v[top.i][top.j] = true;
			for (int i = top.i - 1; i <= top.i + 1; ++i) {
				for (int j = top.j - 1; j <= top.j + 1; ++j) {
					if (i < 0 || i >= n || j < 0 || j >= m || (i != top.i && j != top.j) || v[i][j]) {
						continue;
					}
					if (c[i][j] - f[i][j] < 50 || c[top.i][top.j] - f[i][j] < 50 ||
						c[i][j] - f[top.i][top.j] < 50)
					{
						continue;
					}
					double mint = d[top.i][top.j];
					double ht = h - mint*10;
					if (c[i][j] - ht < 50) {
						mint += (50 - c[i][j] + ht) / 10.0;
					}
					ht = h - mint*10;
					if (mint > 1e-10) {
						if (ht - f[top.i][top.j] >= 20.0) {
							mint += 1;
						} else {
							mint += 10;
						}
					}
					if (d[i][j] > mint) {
						d[i][j] = mint;
						q.push(Data(i, j, mint));
					}
				}
			}
		}
		cout << fixed;
		cout.precision(6);
		cout << "Case #" << test << ": " << d[n - 1][m - 1] << endl;
	}
}
