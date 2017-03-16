/*
 * B
 * Apr 14, 2012,
 * Another buggy code by Khaled Samy;)
 */
#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <valarray>
#include <memory.h>
#include <climits>
using namespace std;
#define PB                      push_back
#define MP                      make_pair
#define ALL(v)                  v.begin(),v.end()
#define SZ(v)					(int)v.size()
#define CLR(v, d)               memset(v, d, sizeof(v))
#define loop(i,n) 		        for(int i=0;i<(int)n;i++)
#define loop2(i,n,m)            for(int i=n;i<(int)(m);i++)
#define MOD(a,b) ((((a)%(b))+(b))%(b))
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef long long ll;
typedef stringstream SS;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int OO = (int) 2e9;
const double PI = 2 * acos(0.0);
const double EPS = 1e-9;

int dcmp(double a, double b) {
	return fabs(a - b) <= EPS ? 0 : a > b ? 1 : 2;
}

int DI[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
int DJ[] = { 0, 1, 0, -1, 1, -1, 1, -1 };

int n, r, p;

int main() {

	freopen("in.in", "rt", stdin);
	freopen("out.out", "wt", stdout);

	int t;
	cin >> t;
	loop(tt,t) {

		cin >> n >> r >> p;
		vi nums(n);
		loop(i,n)
			cin >> nums[i];

		vector<pii> x;

		sort(ALL(nums));
		loop(i,SZ(nums)) {
			int cur = nums[i];
			for (int f = 0; f <= cur; f++) {
				int s = cur - f;
				if (s % 2)
					continue;
				s /= 2;
				if (abs(f - s) > 1)
					continue;
				x.PB(MP(min(f, s), max(f, s)));
			}
		}

		int cnt = 0;
		sort(ALL(x));
//						loop(i,SZ(x))
//							cout << x[i].first << " " << x[i].second << endl;
		int i = 0;
		while (i < SZ(x) && r) {

			if (x[i].second != 0) {
				if (x[i].first * 2 + x[i].second == nums[i] && x[i].first
						!= x[i].second) {
					if (x[i].second >= p)
						r--, cnt++;
				} else {
					if (x[i].second + 1 >= p)
						r--, cnt++;
				}
			} else if (x[i].second >= p)
				cnt++;
			i++;
		}

		while (i < SZ(x))
			if (x[i++].second >= p)
				cnt++;

		printf("Case #%d: %d\n", tt + 1, cnt);

	}
	return 0;
}
