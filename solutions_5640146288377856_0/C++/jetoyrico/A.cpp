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

int R, C, W;
int a[11][11];

void solve(int cur_case) {
	cin >> R >> C >> W;
	a[1][1] = 1;
	a[2][1] = 2;
	a[2][2] = 2;
	a[3][1] = 3;
	a[3][2] = 3;
	a[3][3] = 3;
	a[4][1] = 4;
	a[4][2] = 3;
	a[4][3] = 4;
	a[4][4] = 4;
	a[5][1] = 5;
	a[5][2] = 4;
	a[5][3] = 4;
	a[5][4] = 5;
	a[5][5] = 5;
	a[6][1] = 6;
	a[6][2] = 4;
	a[6][3] = 4;
	a[6][4] = 5;
	a[6][5] = 6;
	a[6][6] = 6;
	a[7][1] = 7;
	a[7][2] = 5;
	a[7][3] = 5;
	a[7][4] = 5;
	a[7][5] = 6;
	a[7][6] = 7;
	a[7][7] = 7;
	a[8][1] = 8;
	a[8][2] = 5;
	a[8][3] = 5;
	a[8][4] = 5;
	a[8][5] = 6;
	a[8][6] = 7;
	a[8][7] = 8;
	a[8][8] = 8;
	a[9][1] = 9;
	a[9][2] = 6;
	a[9][3] = 5;
	a[9][4] = 6;
	a[9][5] = 6;
	a[9][6] = 7;
	a[9][7] = 8;
	a[9][8] = 9;
	a[9][9] = 9;
	a[10][1] = 10;
	a[10][2] = 6;
	a[10][3] = 6;
	a[10][4] = 6;
	a[10][5] = 6;
	a[10][6] = 7;
	a[10][7] = 8;
	a[10][8] = 9;
	a[10][9] = 10;
	a[10][10] = 10;
	cout << "Case #" << cur_case << ": " << a[C][W] << endl;
}

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout << fixed;
	freopen("A-small-attempt0.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	clock_t start_time = clock(), check_time;
	int total_cases;
	cin >> total_cases;
	for (int cur_case = 1; cur_case <= total_cases; ++cur_case) {
		solve(cur_case);
		check_time = clock(); cerr << "Case #" << cur_case << " elapsed time: " << check_time - start_time << "ms" << endl; start_time = clock();
	}
	return 0;
}
