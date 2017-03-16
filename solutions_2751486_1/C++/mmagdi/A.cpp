/*
 TASK:A
 LANG:C++
 Muhammad Magdi Muhammad
 Email: moh_magdi@acm.org
 */
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

#define all(v)          v.begin(),v.end()
#define allr(v)         v.rbegin(),v.rend()
#define rep(i,m)        for(int i=0;i<(int)m;i++)
#define REP(i,k,m)      for(int i=k;i<(int)m;i++)
#define mem(a,b)        memset(a,b,sizeof(a))
#define mp              make_pair
#define pb              push_back
#define OO ((int)1e9)
#define MAX 100000

typedef long long ll;

int diri[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
int dirj[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int compare(double d1, double d2) {
	if (fabs(d1 - d2) < 1e-9)
		return 0;
	if (d1 < d2)
		return -1;
	return 1;
}
int I, J;
inline bool valid(const int &i, const int &j) {
	if (i < 0 || j < 0 || i >= I || j >= J)
		return false;
	return true;
}

using namespace std;

#define SMALL
#define LARGE
int T;

char arr[] = { 'a', 'e', 'i', 'o', 'u' };
bool isv(char c) {
	rep(i,5)
		if (c == arr[i])
			return 1;
	return 0;
}
void brute(int n, string s, int mn) {
	rep(i,n) {
		REP(j,i,n) {
			string cur = s.substr(i, j - i + 1);
			if (cur.size() >= mn) {
				int cnt = 0;
				rep(k,cur.size()) {
					if (isv(cur[k])) {
						cnt = 0;
						continue;
					}
					cnt++;
					if (cnt >= mn) {
						cout << cur << endl;
						break;
					}
				}
			}
		}
	}
}

int main() {
	freopen("1.in", "rt", stdin);
#ifdef SMALL
	freopen("A-small-attempt0.in","rt",stdin);
	freopen("A-small2.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("A-large.in","rt",stdin);
	freopen("A-large.out","wt",stdout);
#endif

	cin >> T;
	rep(tt,T) {
		printf("Case #%d: ", tt + 1);
		string s;
		int mn, n;
		cin >> s >> mn;
		n = s.size();
		ll ans = 0;
//		brute(n, s, mn);
		int cnt = 0;
		ll bre = 0 ;
		for (int i = n - 1; i >= 0; i--) {
			if (isv(s[i]))
				cnt = 0;
			else {
				cnt++;
				if (cnt >= mn) {
					int rem = n - i - (mn - 1);
					bre = rem ;
				}
			}
//			cout << s[i] << " " << bre << endl ;
			ans += bre;
		}
		cout << ans << endl;
		cerr << tt << endl;
	}
	return 0;
}
//end

