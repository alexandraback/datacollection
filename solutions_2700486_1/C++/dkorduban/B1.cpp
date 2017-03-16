// Visual C++ 2008 Express
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

#define REP(i,n) FOR(i,0,n)
#define FOR(i,s,n) for(int i=(s); i<(n); ++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())

typedef long long lint;

int h, layer, init_k;
const int DIM = 1500;

double sav[2 * DIM][2 * DIM];

double f(int k, int left) {
	int dropped = init_k - k;
	int right = dropped - left;
	if(k == 0) {
		if(left > h)
			return 1.0;
		else
			return 0.0;
	}
	if(sav[k][left] != -1) {
		return sav[k][left];
	}
	double ans;
	if(right == 2 * layer) {
		ans = f(k - 1, left + 1);
	}
	else if(left == 2 * layer) {
		ans = f(k - 1, left);
	}
	else {
		ans = (f(k - 1, left) + f(k - 1, left + 1)) / 2.0;
	}
	//cout << left << " " << right  << " " << ans << endl;
	return sav[k][left] = ans;
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T;
	cin >> T;
	for(int tc = 1; tc <= T; ++tc) {
		int N, X, Y;
		cin >> N >> X >> Y;
		int U = (X + Y) / 2, V = (Y - X) / 2;
		layer = max(U, V);		
		lint total = 0;
		REP(k, layer) {
			total += (1 + 4 * k);			
		}
		int delta = 1 + 4 * layer;
		double ans = 0;
		//cout << N << " " << layer << " " << total << " " << delta << endl;
		if(N <= total) {
			ans = 0;
		}
		else if(N >= total + delta) {
			ans = 1;
		}
		else {
			
			// total < N < total + delta
			if(X == 0) {
				//cout << "a peak!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				// a peak is always last
				ans = 0;
			}
			else {
				init_k = N - total; // # of drops
				h = U + V;
				//cout << U << " " << V << " " << init_k << " " << h << endl;
				if(init_k + 1 >= 2 * DIM || 2 * (layer + 1) >= 2 * DIM) {
					cerr << "!!!\n";
				}
				REP(i, init_k + 1) REP(j, 2 * (layer + 1)) sav[i][j] = -1;				
				ans = f(init_k, 0);
				//cerr << U << " " << V << " " << init_k << " " << ans << endl;
			}
		}
		printf("Case #%d: %.8lf\n", tc, ans);
	}
	return 0;
}