#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<int> tbl;

void init() {
	tbl.push_back(0);
	int cur = 0;
	for ( int i = 0; ; i += 2 ) {
		int d = i * 2 + 1;
		cur += d;
		if ( cur > 1001820 ) break;
		tbl.push_back(cur); 
	}
//	cout << tbl.size() << endl;
}

static double f[5000][5000];

double calc(int n, int x, int y) {
	if ( x < 0 ) x = -x;
	int k = upper_bound( tbl.begin(), tbl.end(), n ) - tbl.begin();
	while ( n <= tbl[k] ) --k;
	int rem = n - tbl[k];
	int cap = k * 2;
	//cout << "k = " << k << endl;
	//cout << "rem = " << rem << endl;
	//cout << "x + y = " << x + y << endl;
	//cout << "cap = " << cap << endl;
	if ( x + y < cap ) return 1;
	if ( x + y > cap ) return 0;
	
	for ( int j = 0; j <= cap+1; ++j ) f[0][j] = 0;
	f[0][0] = 1;
	for ( int i = 0; i <= rem; ++i ) {
		for ( int j = 0; j <= cap+1; ++j ) {
			f[i+1][j] = 0;
		}
		for ( int j = 0; j <= cap && j <= i; ++j ) {
			//printf("f[%d][%d] = %f\n", i, j, f[i][j]);
			if ( i - j == cap ) {
				f[i+1][j+1] += f[i][j];
			} else if ( j == cap ) {
				f[i+1][j] += f[i][j];
			} else {
				f[i+1][j] += f[i][j] * 0.5;
				f[i+1][j+1] += f[i][j] * 0.5; 
			}
		}
	}
	double ans = 0;
	for ( int k = y+1; k <= cap+1; ++k )
		ans += f[rem][k];
	return ans;
}

void solve(int ri) {
	int n, x, y; cin >> n >> x >> y;
	double ans = calc(n, x, y);
	printf("Case #%d: %.10f\n", ri, ans);
}

int main() {
	init();
	//for (int n; cin >> n;) calc(n, 0, 0); 
	int re; cin >> re;
	for ( int ri = 1; ri <= re; ++ri ) solve(ri);
}
