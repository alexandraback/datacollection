#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<double>> vvd;
typedef pair<int, int> pii;

#define sz size()
#define pb push_back
#define rep(k,a,b) for (int k = (a); k < (int)(b); k++)
#define rrep(k,a,b) for (int k = (a); k >= (int)(b); k--)
#define irep(k,a) for (auto& k: a)
#define all(c) (c).begin(), (c).end()
#define clr(a) memset((a),0,sizeof(a))
#define mi(r, c, v) vvi(r, vi(c, v))
#define md(r, c, v) vvd(r, vd(c, v))
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

const double eps = 10e-10;
const int inf = 0x3f3f3f3f;

void prt(int r, int c, int pr, int pc, int v) {
	vs grid(r, string(c, '*'));
	rep(i, 0, pr)
		grid[i][0] = grid[i][1] = '.';
	rep(j, 0, pc)
		grid[0][j] = grid[1][j] = '.';

	grid[0][0] = 'c';

	rep(i, 2, pr) {
		rep(j, 2, pc) {
			if (v == 0)
				goto funcend;
			grid[i][j] = '.';
			v--;
		}
	}

funcend:;
	rep(i, 0, r)
		cout << grid[i] << endl;
}

int main() {
	fastio;

	int N, r, c, t;
	cin >> N;
	rep(X, 1, N + 1) {
		cout << "Case #" << X << ":" << endl;
		cin >> r >> c >> t;
		int g = r * c, v = g - t;
		bool good = false;

		if (r == 1 || c == 1) {
			cout << 'c';
			if (c == 1)
				cout << endl;
			rep(i, 1, v) {
				cout << '.';
				if (c == 1)
					cout << endl;
			}
			rep(i, v, g) {
				cout << '*';
				if (c == 1)
					cout << endl;
			}
			if (r == 1 && c != 1)
				cout << endl;

			good = true;
		} else if (v == 1) {
			prt(r, c, 0, 0, 0);
			good = true;
		} else {
			rep(i, 2, r + 1) {
				rep(j, 2, c + 1) {
					int mn = (i + j - 2) * 2;
					int mx = i * j;
					if (v >= mn && v <= mx) {
						prt(r, c, i, j, v - mn);
						good = true;
						goto end;
					}
				}
			}
		}


	end:;
		if (!good)
			cout << "Impossible" << endl;
	}
}