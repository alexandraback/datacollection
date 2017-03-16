#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define ALL(c) (c).begin(),(c).end()
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << x << endl;

typedef long long ll;
typedef long double ld;
typedef unsigned long ulong;
typedef unsigned long long ull;

pair<int, int> s[1001];
char was[1001];

int main() {
	//freopen("problem.in", "r", stdin);
	//freopen("problem.out", "w", stdout);
	int tnum;
	cin >> tnum;
	FOR(ti,1,tnum) {
		memset(was, 0, sizeof(was));
		memset(s, 0, sizeof(s));
		int n;
		int score = 0;
		int cnt = 0;
		cin >> n;
		REP(i,n)
			cin >> s[i].first >> s[i].second;
		for(;;) {
			int si = -1, fi = -1, sv = 2012, fv = 2012;
			bool ok = 0;
			REP(i,n) {
				if (was[i] < 2)
					ok = true;
				if (was[i] < 2 && s[i].second < sv) {
					si = i;
					sv = s[i].second;
				}	
				if (was[i] < 1 && (fi == -1 || s[i].first < s[fi].first || 
					(s[i].first == s[fi].first && s[i].second > s[fi].second)
				)) {
					fi = i;
					fv = s[i].first;
				}
			}
			if (!ok)
				break;
			++cnt;
			if (sv <= score) {
				score += 2-was[si];
				was[si] = 2;
			} else if (fv <= score) {
				score += 1;
				was[fi] = 1;
			} else {
				cnt = -1;
				break;
			}
		}
		if (cnt < 0)
			printf("Case #%d: Too Bad\n", ti);
		else
			printf("Case #%d: %d\n", ti, cnt);
	}
	return 0;
}