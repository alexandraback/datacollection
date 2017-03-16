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

int t, k, s, l;
string keyboard;
string target;

int bananas(int mask) {
	string res = "";
	int ans = 0;
	FOR(i, 0, s) {
		res += keyboard[mask % k];
		mask /= k;
	}
	FOR(start, 0, s - l + 1) {
		if (res.substr(start, l) == target)
			ans++;
	}
	return ans;
}

int main() {
	ifd();

	cin >> t;
	
	FOR(tc, 1, t + 1) {
		cin >> k >> l >> s;
		cin >> keyboard >> target;

		double ensure = 0;
		int total_ways = 1;
		int total_bananas = 0;

		FOR(i, 0, s) {
			total_ways *= k;
		}

		FOR(i, 0, total_ways) {
			int now = bananas(i);
			ensure = MAX(ensure, now);
			total_bananas += now;
		}

		double expected = static_cast<double>(total_bananas) / static_cast<double>(total_ways);
		
		printf("Case #%d: %.20lf\n", tc, MAX(ensure - expected, 0.0));
	}

	tme();
	return 0;
}