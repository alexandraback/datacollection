
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <string.h>
#include <string>
#include <limits.h>
#include <algorithm>
#include <set>
#include <ctime>
#include <sstream>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i=a; i<(int)n; i++)
#define per(i,n,a) for (int i=n; i>=a; i--)
#define hk push_back
#define pk pop_back
#define mp make_pair
#define PI 3.141592653589793
#define clr(a) memset(a, 0, sizeof(a))
#define clr1(a) memset(a, -1, sizeof(a))
typedef vector<int> VI;
typedef vector< pair<int, int> > VIP;
typedef vector< pair<int, pair<int, double> > > VIPP;
typedef vector<string> VS;
typedef vector <double> VD;
typedef vector <bool> VB;
typedef long long ll;
#define MAX_V 1000
const ll mod = 1000000007;
ll powmod(ll a, ll b) {
	ll res = 1; a %= mod; for (; b; b >>= 1){ if (b & 1)res = res*a%mod; a = a*a%mod; }return res;
}

int T;
string s, s1, s2, s3, s4, s5;

ll getDiff(string l, string r) {
	stringstream ss, ss1;
	ll a, b;
	ss.str(l);
	ss1.str(r);
	ss >> a;
	ss1 >> b;

	return a - b;
}

int main() {
	cout.precision(12);
	cin >> T;
	int T1 = 0;
	while (T1++ < T) {
		ll ret = 0;
		cin >> s;
		int tmp1 = s.length();
		while (tmp1 > 1) {
			ret += 1;
			ll add1 = 0;
			ll add2 = 0;
			ll tmp = 1;
			rep(i, 0, tmp1 / 2) {
				add1 += 9 * tmp;
				tmp *= 10;
			}
			tmp = 1;
			rep(i, 0, (tmp1 - 1) / 2) {
				add2 += 9 * tmp;
				tmp *= 10;
			}
			ret += add1 + add2;
			tmp1--;
		}
		if (s.length() <= 1) {
			cout << "Case #" << T1 << ": " << s[0] << endl;
			continue;
		}

		s1 = "1";
		rep(i, 0, s.length() - 1) s1 += "0";
		s2 = "1";
		rep(i, 0, s.length() - 2 - (s.length() - 1) / 2) s2 += "0";
		per(i, (s.length() - 1) / 2, 0) s2 += s[i];
		s3 = "";
		per(i, s.length() - 1, 0) s3 += s2[i];
		if (s3 > s) {
			int idx = -1;
			rep(i, s.length() - (s.length() - 1) / 2 - 1, s.length()) {
				if (s2[i] != '0') {
					idx = i;
					s2[i]--; break;
				}
			}
			per(i, idx - 1, s.length() - (s.length() - 1) / 2 - 1) {
				s2[i] = '9';
			}
			s3 = "";
			per(i, s.length() - 1, 0) s3 += s2[i];
		}




		s4 = "1";
		rep(i, 0, s.length() - 1 - s.length() / 2) s4 += "0";
		per(i, s.length() / 2 - 1, 0) s4 += s[i];
		s5 = "";
		per(i, s.length() - 1, 0) s5 += s4[i];
		if (s5 > s) {
			int idx = -1;
			rep(i, s.length() - s.length() / 2, s.length()) {
				if (s4[i] != '0') {
					idx = i;
					s4[i]--; break;
				}
			}
			per(i, idx - 1, s.length() - s.length() / 2) {
				s4[i] = '9';
			}
			s5 = "";
			per(i, s.length() - 1, 0) s5 += s4[i];
		}





		ret += min(getDiff(s, s1), min(getDiff(s2, s1) + 1 + getDiff(s, s3), getDiff(s4, s1) + 1 + getDiff(s, s5)));

		cout << "Case #" << T1 << ": " << ret << endl;
	}

	return 0;
}