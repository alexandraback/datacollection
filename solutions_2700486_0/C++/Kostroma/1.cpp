#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();
//void precalc();

#define FILENAME "change me please"
int main(){
	string s = FILENAME;
#ifdef room210
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	//cout<<FILENAME<<endl;
	//assert (s != "change me please");
	clock_t start = clock();
#else
	//freopen(FILENAME ".in", "r", stdin);
	//freopen(FILENAME".out", "w", stdout);
#endif
	cout.sync_with_stdio(0);
	int t = 1;
	//precalc();
	//cout << "done!\n";
	cin >> t;
	//gen();
	while (t--)
		solve();
	/*
#ifdef room210
	cout<<"\n\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif*/
	return 0;
}

int timer = 0;
//#define int li

void solve() {
	++timer;
	cout << "Case #" << timer << ": ";
	int n, x, y;
	cin >> n >> x >> y;
	if (x < 0)
		x = -x;
	int level = (x + y) / 2;
	int pref = 0;
	for (int i = 0; i < level; ++i) {
		pref += 1 + 4 * i;
	}
	if (pref >= n) {
		cout << "0.000000000000\n";
		return;
	}
	if (pref + 1 + 4 * level <= n) {
		cout << "1.00000000000\n";
		return;
	}

	if (x == 0) {
		cout << "0.0000000000\n";
		return;
	}

	vector <vector<double> > dp(2 * level + 1, vector<double>(2 * level + 1, 0.0));
	dp[0][0] = 1.0;
	for (int sum = 0; sum < 4 * level; ++sum) {
		for (int i = 0; i <= sum && i <= 2 * level; ++i) {
			int j = sum - i;
			if (j > 2 * level)
				continue;
			if (i < 2 * level)
				dp[i + 1][j] += dp[i][j] / 2.0;
			else
				dp[i][j + 1] += dp[i][j] / 2.0;
			if (j < 2 * level)
				dp[i][j + 1] += dp[i][j] / 2.0;
			else
				dp[i + 1][j] += dp[i][j] / 2.0;
		}
	}

	n -= pref;
	if (n < y + 1) {
		cout << "0.00000000000000\n";
		return;
	}
	if (2 * level + y + 1 <= n) {
		cout << "1.0000000000\n";
		return;
	}
	double res = 0.0;
	for (int i = y + 1; i <= 2 * level && i <= n; ++i)
		res += dp[n - i][i];
	printf("%.10lf\n", res);

}