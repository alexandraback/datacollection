// Tapan Sahni
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <iomanip>
#include <map>
#include <complex>
#include <set>

using namespace std;
typedef long long LL;
typedef pair <int, int> PII;

const int N = 2e5 + 10;
const LL mod = 1000000007;

LL pw(LL x, LL exp1) {
	if(exp1 == 0)
		return 1;
	LL y = pw(x, exp1 / 2);
	y = y * y;
	if(exp1 & 1)
		y = y * x;
	return y;
}

int ans[55][55];
void solve() {
	int t, tNUm = 1;
	cin >> t;
	while(t--) {
		memset(ans, 0, sizeof ans);
		int b; LL m;
		cin >> b >> m;
		cout << "Case #" << tNUm << ": ";
		tNUm++;
		if(pw(2, b - 2) < m) {
			cout << "Impossible\n";
			continue;
		}
		cout << "Possible\n";
		if(pw(2 , b - 2) == m) {
			for(int i = 1; i <= b; i++) {
				for(int j = i + 1; j <= b; j++)
					ans[i][j] = 1;
			}
			for(int i = 1; i <= b; i++) {
				for(int j = 1; j <= b; j++) {
					cout << ans[i][j];
				}
				cout << endl;
			}
			continue;
		}
		LL jn = 0;
		for(LL i = 51; i >= 0; i--) {
			if((1LL << i) & m) {
				jn = i;
				break;
			}
		}
		for(LL i = 2; i <= jn + 2; i++) {
			for(LL j = i + 1; j <= jn + 2; j++) {
				ans[i][j] = 1;
			}
		}
		for(LL i = 2; i <= jn + 2; i++) {
			ans[i][b] = 1;
		}
		ans[1][2] = 1;
		for(LL i = jn - 1; i >= 0; i--) {
			if((1LL << i) & m) {
				ans[1][jn + 2 - i] = 1;
			}
		}
		for(int i = 1; i <= b; i++) {
			for(int j = 1; j <= b; j++) {
				cout << ans[i][j];
			}
			cout << endl;
		}
	}
	return; 
}
int main() {
    ios::sync_with_stdio(false) ; cin.tie(nullptr);
    solve();
    return  0;
}
// Never Quit