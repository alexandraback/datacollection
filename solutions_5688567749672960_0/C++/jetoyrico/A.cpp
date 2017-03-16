#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define rep(i,m) for(int i=0;i<(int)(m);++i)
#define sz(c) (int((c).size()))
#define fill(a,b) memset(a,b,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define mp make_pair

int ans[10000007];

int rev(int n) {
	int ret = 0;
	int ten = 1;
	while (n) {
		ret *= 10;
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

void pre() {
	for (int i = 0; i <= 1000000; ++i) ans[i] = 1e9;
	for (int i = 1; i <= 10; ++i) ans[i] = i;
	for (int i = 11; i <= 1000000; ++i) {
		ans[i] = min(ans[i], ans[i - 1] + 1);
		int r = rev(i);
		ans[r] = min(ans[r], ans[i] + 1);
	}
}

void solve(int cur_case) {
	int n;
	cin >> n;
	cout << "Case #" << cur_case << ": " << ans[n] << endl;
}

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout << fixed;
	freopen("A-small-attempt0.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	pre();
	clock_t start_time = clock(), check_time;
	int total_cases;
	cin >> total_cases;
	for (int cur_case = 1; cur_case <= total_cases; ++cur_case) {
		solve(cur_case);
		check_time = clock(); cerr << "Case #" << cur_case << " elapsed time: " << check_time - start_time << "ms" << endl; start_time = clock();
	}
	return 0;
}
