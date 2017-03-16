#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>

using namespace std;


class Solution {
public:
	const static int N = 1000000+10;
	map<int, int> m;
	void solve() {
		int tcase;
		cin >> tcase;
		pre_compute();
		for (int i = 1; i <= tcase; i++) {
			int n;
			cin >> n;

			cout << "Case #" << i << ": " << f[n] << endl;
		}
	}
	int *f;
	void pre_compute() {
		f = new int[N];
		memset(f, 0, sizeof(int)* N);
		f[0] = 0;
		f[1] = 1;
		for (int i = 2; i < N; i++) {
			int i_reverse = reverse(i);
			if (i_reverse < i && i%10 != 0) f[i] = min(f[i-1], f[i_reverse]) + 1;
			else f[i] = f[i-1] + 1;
		}
//		for (int i = 1; i < 30; i++) {
//			cout << "i:" << i << " " << f[i] << endl;
//		}
	}
	int reverse(int k) {
		int ans = 0;
		while (k > 0) {
			ans *= 10;
			ans += k%10;
			k /= 10;
		}
		return ans;
	}
};

class Solution2 {
public:
	const static int R_MAX = 16+1;
	const static int C_MAX = 16+1;
	int board[R_MAX][C_MAX];
	int m[R_MAX][C_MAX][R_MAX];
	void init() {
		for (int i = 0; i < R_MAX; i++) for (int j = 0; j < C_MAX; j++) {
			board[i][j] = 0;
			for (int k = 0; k < R_MAX; k++) m[i][j][k] = 1<<30;
		}
	}
	void solve() {
		init();
		for (int r = 1; r < R_MAX; r++) {
			for (int c = 1; c < C_MAX; c++) {
				if (r * c > 16) continue;
				compute(r, c, 0);
//				printf("r:%d, c:%d  \n", r, c);
			}
		}
//		compute(3,3,0);
//		for (int k = 0; k <= 9; k++) {
//			printf("K:%d value:%d\n", k, m[3][3][k]);
//		}
		int tcase ;
		cin  >> tcase;

		for (int i = 1; i <= tcase; i++) {
//			cout << "@" << endl;
			int r, c, k;
			cin >> r >> c >> k;
			cout << "Case #" << i << ": " << m[r][c][k] << endl;
		}
	}
	void compute(int r, int c, int step) {
		if (step >= r * c) {
			// update unhappiness;
			int k = 0, unhappiness = 0;
			for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) if (board[i][j] == 1) k++;
			for (int i = 1; i < r; i++) {
				for (int j = 1; j <= c; j++) {
					if (board[i][j] && board[i+1][j]) unhappiness++;
				}
			}
			for (int j = 1; j < c; j++) {
				for (int i = 1; i <= r; i++) {
					if (board[i][j] && board[i][j+1]) unhappiness++;
				}
			}
			m[r][c][k] = min(m[r][c][k], unhappiness);
		} else {
			board[step/c + 1][step%c + 1] = 1;
			compute(r, c, step+1);
			board[step/c + 1][step%c + 1] = 0;
			compute(r, c, step+1);
		}
	}
};

class Solution3 {
public:
	const static int N = 1000+10;
	int d[N], h[N], m[N];
	int n;
	void solve() {
		int t_case;
		cin >> t_case;
		for (int i = 1; i <= t_case; i++) {
			cin >> n;
			for (int j = 0; j < n; j++) {
				cin >> d[j] >> h[j] >> m[j] ;
			}
			vector<double> v;
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < h[j]; k++) {
					double f1 = (360 - d[j]) / 360.0 * (m[j]+k);
					double f2 = f1 + m[j]+k;
					v.push_back(f1);
					v.push_back(f2);
					v.push_back(f1 * 0.5 + f2 * 0.5);
//					cout << "@" << f1 << " " << f2 << endl;
				}
			}
			sort(v.begin(), v.end());
//			for (int i = 0; i < v.size(); i++) cout << "#" << v[i] << endl;
			int min_cross = 1<<30;
//			for (int j = 0; j < v.size(); j++) {
//				if (j == 0) {
//					min_cross = min(min_cross, get_cross(v[j]));
//				} else {
//					min_cross = min(min_cross, get_cross(v[j]));
//					min_cross = min(min_cross, get_cross(v[j-1]/2.0 + v[j]/2.0));
//				}
//			}
			int m1, d1, m2, d2;
			if (n == 2) {
				m1 = m[0];
				d1 = d[0];
				m2 = m[1];
				d2 = d[1];
			} else {
				m1 = m[0]; d1 = d[0]; m2 = m1+1; d2 = d1;
			}
			double dd1 = (360-d1)/360.0 * m1;
			double dd2 = (360-d2)/360.0 * m2;
			if (dd1 < dd2 && (dd2 < dd1 + m1 || fabs(dd2-dd1-m1) <= 1e-9)) min_cross = 0;
			else if (dd1 > dd2 && (dd1 < dd2 + m2 || fabs(dd1-dd2-m2) <= 1e-9)) min_cross = 0;
			else min_cross = 1;
			cout << "Case #" << i << ": " << min_cross << endl;
		}
	}
	int get_cross(double m0) {
//		cout << "!" << m0 << endl;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < h[i]; j++) {
				ans += get_cross_count(d[i], m[i] + j, m0);
			}
		}
		return ans;
	}
	int get_cross_count(int di, int mi, double m0) {
		double tmp = m0 - (360 - di) / 360.0 * mi;
		tmp /= mi;
		if (tmp < 0) return 1;
//		cout << "**" << di << " " << mi << " " << m0 << " " << tmp << endl;
		return int(tmp);
	}
};

int main() {
	Solution3 solution;
	solution.solve();
	return 0;
}
