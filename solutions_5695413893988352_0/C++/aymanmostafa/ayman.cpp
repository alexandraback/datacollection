//============================================================================
// Name        : ayman.cpp
// Author      : Ayman Mostafa
// Email       : ayman93live@hotmail.com
// Version     : v5.0
//============================================================================

#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#include <functional>
#include <numeric>

using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define clr(v,d) memset(v,d,sizeof(v));

const double PI = 2 * acos(0.0);
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
void fastInOut();

long long pwr(long long base, long long power) {
	long long res = 1;
	while (power) {
		if (power & 1)
			res *= base;
		base *= base;
		power >>= 1;
	}
	return res;
}
int comp_double(double a, double b) {
	if (fabs(a - b) <= 1e-10)
		return 0;
	return a < b ? -1 : 1;
}
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
string tt;
vector<pair<string, int>> v;
void printt(int ind) {
	if (ind == (int) tt.size()) {
		int x;
		stringstream(tt) >> x;
		v.push_back( { tt, x });
		return;
	}
	if (tt[ind] == '?') {
		for (char i = '0'; i <= '9'; i++) {
			tt[ind] = i;
			printt(ind + 1);
			tt[ind] = '?';
		}
	} else {
		printt(ind + 1);
	}
}
//##########################################################################################
//###################################MAIN FUNCTION##########################################
//##########################################################################################
int main() {
#ifndef ONLINE_JUDGE
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("output.out", "wt", stdout);
#endif
	fastInOut();
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
	int t, i = 1;
	string s, ss;
	vector<pair<string, int>> v1, v2;
	set < pair<int, pair<string, string>>> se;
	set<pair<int, pair<string, string>>> ::iterator it;
	cin >> t;
	while (t--) {
		cin >> s >> ss;
		cout << "Case #" << i++ << ": ";
		v.clear();
		v1.clear();
		v2.clear();
		se.clear();
		tt = s;
		printt(0);
		v1 = v;
		v.clear();
		tt = ss;
		printt(0);
		v2 = v;
		for (auto m : v1) {
			for (auto k : v2) {
				se.insert( { abs(m.second - k.second), { m.first, k.first } });
			}
		}
		it = se.begin();
		cout << it->second.first << " " << it->second.second << endl;
	}
}
void fastInOut() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
