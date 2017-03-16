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

vector<vector<pair<int, pii> > > v;
int n, r, p;
int mx = 0;
void check(vi x) {
	int ok = 0;
	int ret = 0;
	loop(i,SZ(x)) {
		int idx = x[i];
		int f = v[i][idx].first;
		int s = v[i][idx].second.first;
		int t = v[i][idx].second.second;
		if (abs(f - s) <= 1 && abs(f - t) <= 1 && abs(s - t) <= 1)
			ok++;
		if (max(f, max(s, t)) >= p)
			ret++;
	}
	if (n - ok == r)
		mx = max(ret, mx);
}
void clc(int idx, vector<int> t) {
	if (idx >= n) {
		check(t);
		return;
	}
	for (int i = 0; i < SZ(v[idx]); i++) {
		t[idx] = i;
		clc(idx + 1, t);
	}
}
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

		v.clear();
		v.resize(n);

		loop(i,SZ(nums)) {
			int cur = nums[i];
			set<pair<int, pii> > vis;
			loop(j,cur+1) {
				int f = j;
				int rem = cur - f;
				if (rem % 2)
					continue;
				int ss = rem / 2;
				if (abs(f - ss) > 1)
					continue;
				if (f > 10 || ss > 10)
					continue;
				if (vis.find(MP(min(f, ss), MP(max(f, ss), max(f, ss))))
						!= vis.end())
					continue;
				v[i].push_back(MP(min(f, ss), MP(max(f, ss), max(f, ss))));
				vis.insert(MP(min(f, ss), MP(max(f, ss), max(f, ss))));
			}
			loop(j,cur+1)
				loop(k,cur+1)
					if (j + k < cur + 1) {
						int q = cur - j - k;
						if ((abs(j - k) > 1 || abs(j - q) > 1 || abs(k - q) > 1)
								&& j <= 10 && k <= 10 && q <= 10) {
							if (abs(j - k) > 2 || abs(j - q) > 2 || abs(k - q)
									> 2)
								continue;
							vi tmp;
							tmp.PB(j);
							tmp.PB(k);
							tmp.PB(q);
							sort(ALL(tmp));
							if (vis.find(MP(tmp[0], MP(tmp[1], tmp[2])))
									!= vis.end())
								continue;
							v[i].push_back(MP(j, MP(k, q)));
							vis.insert(MP(tmp[0], MP(tmp[1], tmp[2])));
						}

					}
		}

//		loop(i,SZ(v)) {
//			loop(j,SZ(v[i]))
//				cout << v[i][j].first << " " << v[i][j].second.first << " "
//						<< v[i][j].second.second << "   , ";
//			cout << endl;
//		}

		mx = 0;
		vi t(n);
		clc(0, t);
		printf("Case #%d: %d\n", tt + 1, mx);
		//	cout << mx << endl;
	}
	return 0;
}
