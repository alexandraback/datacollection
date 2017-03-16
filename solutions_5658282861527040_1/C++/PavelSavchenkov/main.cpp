#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define foran(i, a, n) for (int i = (int) a; i < (int) n; ++i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define all(C) (C).begin(), (C).end()

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;

const double EPS = 1e-9;

ll brut_solve( int a, int b, int k ) {
	ll res = 0;
	forn(i, a)
		forn(j, b)
			res += int((i & j) < k);

	return res;
}

int geth( int x ) {
	for (int i = 31; i >= 0; --i)
		if  ((x >> i) & 1) {
			return i;
		}

	return -1;
}

ll solve( int a, int b, int k ) {
	if  (a < b) {
		swap(a, b);
	}
	                    
	if  (a <= 5) {
		return brut_solve(a + 1, b + 1, k);
	}

	int ha = geth(a);
	int hb = geth(b);
	int hk = geth(k);

	if  (ha < hk) {
		return (a + 1) * 1ll * (b + 1);
	}	

	if  (ha == hk) {
		if  (hb < ha) {
			return (a + 1) * 1ll * (b + 1);
		} else {
			return solve(a ^ (1 << ha), (1 << hb) - 1, k) + solve((1 << ha) - 1, b ^ (1 << hb), k) + solve(a ^ (1 << ha), b ^ (1 << hb), k ^ (1 << hk)) +
				solve((1 << ha) - 1, (1 << hb) - 1, k);
		}	
	}

	if  (ha > hk) {
		if  (hb < hk) {
			return (a + 1) * 1ll * (b + 1);
		} else if  (hb == ha) {
			return solve(a ^ (1 << ha), (1 << hb) - 1, k) + solve((1 << ha) - 1, b ^ (1 << hb), k) + solve((1 << ha) - 1, (1 << hb) - 1, k);	
		} else {
			return solve(a ^ (1 << ha), b, k) + solve((1 << ha) - 1, b, k);
		}                                         
	}

    return 0;           
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	forn(it, t) {
		int a, b, k;
		scanf("%d%d%d", &a, &b, &k);

//		printf("Case #%d: %I64d\n", it + 1, brut_solve(a, b, k));
		printf("Case #%d: %I64d\n", it + 1, solve(a, b, k));
		/*
		if  (solve(a - 1, b - 1, k) != brut_solve(a, b, k)) {
			printf("%d %d %d\n", a, b, k);
			printf("%I64d\n", solve(a - 1, b - 1, k));
			printf("correct: %I64d\n", brut_solve(a, b, k));
		}
		*/
		//assert(solve(a, b, k) == brut_solve(a, b, k));
	}

	return 0;
}
