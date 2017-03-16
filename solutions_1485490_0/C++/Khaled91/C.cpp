/*
 * C
 * May 6, 2012,
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
int n, m;
vector<pair<ll, ll> > box, toy, b1, t1;
ll dp[5][5];
ll clc(int i, int j) {
	if (i >= n || j >= m)
		return 0;
	ll &ref = dp[i][j];
	if (ref != -1)
		return ref;
	ref = 0;
	ll c1 = 0, c2 = 0, c3 = 0;
	if (box[i].second == toy[j].second) {
		ll mn = min(box[i].first, toy[j].first);
		c1 = mn + clc(i + 1, j + 1);
	}
	c2 = clc(i + 1, j);
	c3 = clc(i, j + 1);
	ref = max(c1, c2);
	ref = max(ref, c3);
	return ref;
}

int main() {
	freopen("in.in", "rt", stdin);
	freopen("out.txt", "wt", stdout);
	int t;
	cin >> t;
	loop(tt,t) {
		cin >> n >> m;
		box.clear(), toy.clear();
		b1.clear(), t1.clear();
		b1.resize(n), t1.resize(m);
		loop(i,n)
			cin >> b1[i].first >> b1[i].second;
		loop(i,m)
			cin >> t1[i].first >> t1[i].second;
		box = b1;
		//	toy = t1;
		ll res = 0;
		loop(i,SZ(t1))
			loop(j,SZ(t1))
				loop(k,SZ(t1))
					if (i != j && i != k && j != k) {
						toy.clear();
						toy.PB(MP(t1[i].first, t1[i].second));
						toy.PB(MP(t1[j].first, t1[j].second));
						toy.PB(MP(t1[k].first, t1[k].second));
						CLR(dp,-1);
						res = max(res, clc(0, 0));
					}

		printf("Case #%d: ", tt + 1);
		cout << res << endl;

	}
	return 0;
}
