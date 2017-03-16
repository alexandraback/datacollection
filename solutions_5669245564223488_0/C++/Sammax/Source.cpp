/*
ID: 
PROG: kimbits
LANG: C++
*/
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
#include <memory.h>
#include <ctime>
#include <stack>
#ifdef SAMMAX
#include <ctime>
clock_t beg;
#endif

const double pi = 3.1415926535897932384626433832795;
double EPS = 10e-4;
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
	freopen("in_b.txt", "r", stdin);
	freopen("out_b.txt", "w", stdout); 
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

int t, ans, n;
vector <string> all;
vector <int> a;

bool check() {
	int was[30], pos = 0;
	string s = "";
	FOR(i, 0, 30) {
		was[i] = 0;
	}
	FOR(i, 0, n)
		s += all[a[i]];
	int l = s.size();

	FOR(i, 0, l) {
		if (!was[s[i] - 'a']) {
			was[s[i] - 'a'] = 1;
		}
		else {
			if (s[i - 1] != s[i])
				return false;
		}
	}

	return true;
}
int main() {
	ifd();

	
	scanf("%d", &t);

	FOR(cs, 1, t + 1) {
		all.clear();
		a.clear();
		ans = 0;
		scanf("%d", &n);
		all.resize(n);
		FOR(i, 0, n) {
			cin >> all[i];
			a.push_back(i);
		}

		do {
			if (check()) {
				ans++;
			}
		} while (next_permutation(ALL(a)));

		printf("Case #%d: %d\n", cs, ans);
	}

	tme();
	return 0;
}