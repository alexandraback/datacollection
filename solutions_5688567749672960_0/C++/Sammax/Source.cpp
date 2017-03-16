/*
ID:
PROG: kimbits
LANG: C++
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <complex>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <complex>
#include <stdio.h>
#include <cstdlib>
#include <unordered_set>
#include <memory.h>
#include <ctime>
#include <stack>
#include <unordered_map>
#ifdef SAMMAX
#include <ctime>
clock_t beg;
#endif


const double pi = 3.1415926535897932384626433832795;
double EPS = 10e-9;
const int INF = 2000000000;

#pragma comment(linker, "/stack:1500000000")
#define sz size()
#define mp make_pair
#define pb push_back
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define MEMS(a,b) memset(a,b,sizeof(a))
#define sqr(a) ((a)*(a))
#define HAS(a,b) ((a).find(b)!=(a).end())
#define MAX(a,b) ((a>=b)?a:b)
#define MIN(a,b) ((a<=b)?a:b)
#define ABS(a) ((a<0)?-(a):a)
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define FORD(i,a,b) for (int i=(a);i>(b);--i)
#define VVI vector < vector <int> >
#define VI vector <int>
#define LL long long    
#define U unsigned
#define pnt pair <int,int>
LL gcd(LL a, LL b){ if (a == 0) return b; return gcd(b%a, a); }
LL lcm(LL a, LL b){ return a / gcd(a, b) * b; }

using namespace std;

void ifd() {
#ifdef SAMMAX
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	beg = clock();
#else
	//freopen("kimbits.in", "r", stdin);
	//freopen("kimbits.out", "w", stdout);
#endif  
}
void tme() {
#ifdef SAMMAX
	fprintf(stderr, "*** Total time: %.3lf ***\n", 1.0*(clock() - beg) / CLOCKS_PER_SEC);
#endif
}

int n, t;
int was[1000010];

int rev(int k) {
	int res = 0, d = 1;
	VI a;
	while (k) {
		a.push_back(k % 10);
		k /= 10;
	}
	int pos = 0;
	while (a[pos] == 0)
		pos++;
	reverse(a.begin() + pos, a.end());
	FOR(i, pos, a.size()) {
		res += a[i] * d;
		d *= 10;
	}
	return res;
}

int main() {
	ifd();

	cin >> t;
	
	FOR(tc, 1, t + 1) {
		cin >> n;

		FOR(i, 0, 1000010)
			was[i] = 0;

		queue<pair<int, int> > q;

		q.push(make_pair(1, 1));
		was[1] = 1;

		int ans;

		while (!q.empty()) {
			int cur = q.front().first;
			int cnt = q.front().second;
			q.pop();

			if (cur == n) {
				ans = cnt;
				break;
			}

			if (!was[cur + 1]) {
				q.push(make_pair(cur + 1, cnt + 1));
				was[cur + 1] = 1;
			}

			int rvsd = rev(cur);
			if (!was[rvsd]) {
				q.push(make_pair(rvsd, cnt + 1));
				was[rvsd] = 1;
			}
		}
	
		printf("Case #%d: %d\n", tc, ans);
	}

	tme();
	return 0;
}