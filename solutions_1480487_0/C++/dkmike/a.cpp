#include <stdio.h>
#include <vector>
#include <cassert>

using std::vector;
using std::swap;

static const double EPS = 1E-5;
static const int INF = 1 << 30;

int gauss(vector < vector < double > > a, vector < double > &ans) {
	int n = (int) a.size();
	int m = (int) a[0].size() - 1;
 
	vector<int> where (m, -1);
	for (int col=0, row=0; col<m && row<n; ++col) {
		int sel = row;
		for (int i=row; i<n; ++i)
			if (abs (a[i][col]) > abs (a[sel][col]))
				sel = i;
		if (abs (a[sel][col]) < EPS)
			continue;
		for (int i=col; i<=m; ++i)
			swap (a[sel][i], a[row][i]);
		where[col] = row;
 
		for (int i=0; i<n; ++i)
			if (i != row) {
				double c = a[i][col] / a[row][col];
				for (int j=col; j<=m; ++j)
					a[i][j] -= a[row][j] * c;
			}
		++row;
	}
 
	ans.assign (m, 0);
	for (int i=0; i<m; ++i)
		if (where[i] != -1)
			ans[i] = a[where[i]][m] / a[where[i]][i];
	for (int i=0; i<n; ++i) {
		double sum = 0;
		for (int j=0; j<m; ++j)
			sum += ans[j] * a[i][j];
		if (abs (sum - a[i][m]) > EPS)
			return 0;
	}
 
	for (int i=0; i<m; ++i)
		if (where[i] == -1)
			return INF;
	return 1;
}

void init(void) {
}

void read(void) {
}

void solve1(int N, vector < double > &m, vector < double > &ans, const double sum) {
	vector < vector < double > > a;

	for (int i = 0; i < N - 1; ++i) {
		vector < double > row;

		for (int j = 0; j < N; ++j) {
			if (i == j) {
				row.push_back(sum);
			} else if (i + 1 == j) {
				row.push_back(-sum);
			} else {
				row.push_back(0.);
			}
		}

		row.push_back(m[i + 1] - m[i]);

		a.push_back(row);
	}

	vector < double > row;
	for (int i = 0; i < N + 1; ++i) {
		row.push_back(1.);
	}
	a.push_back(row);
	if (1 != gauss(a, ans)) {
		assert(false);
	}
}

void solve(void) {
	int N = 0;
	vector < double > ans;

	scanf("%d", &N);
	vector < double > m;
	double sum = 0.;
	for (int i = 0; i < N; ++i) {
		double tmp;
		scanf("%lf", &tmp);
		sum += tmp;
		m.push_back(tmp);
	}

	solve1(N, m, ans, sum);

	vector < double > m1;
	int N1 = 0;
	bool flag = true;
	for (int i = 0; i < N; ++i) {
		if (ans[i] < 0.) {
			flag = false;
		} else {
			m1.push_back(m[i]);
			++N1;
		}
	}

	if (flag) {
		for (int i = 0; i < N; ++i) {
			printf("%.9lf ", 100 * ans[i]);
		}
		puts("");
		return;
	}

	vector <double > ans1;
	solve1(N1, m1, ans1, sum);

	int j = 0;
	for (int i = 0; i < N; ++i) {
		if (ans[i] < 0.) {
			printf("0.0 ");
		} else {
			printf("%.9lf ", 100 * ans1[j++]);
		}
	}
	puts("");

}

int main(void) {
	freopen("a.in", "rt", stdin);
	freopen("a.out", "wt", stdout);

	int T = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		printf("Case #%d: ", i + 1);
		init();
		read();
		solve();
	}

	fcloseall();

	return 0;
}
