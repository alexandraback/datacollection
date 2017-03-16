#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment(linker, "/STACK:300000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <complex>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (int i=int(a); i<int(b); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

ll p, q;

bool read(){
	return (scanf("%I64d/%I64d", &p, &q));
}

ll gcd(ll a, ll b){
	if (a == 0) return b;
	return gcd(b%a,a);
}

void solve(){
	ll g = gcd(p,q);
	p /= g;
	q /= g;
	if (!((q & (q-1)) == 0))
		puts("impossible");
	else{
		int pw = -1, ans = INF;
		forn(i,41){
			if ((1ll<<i) & q)
				pw = i;
		}
		forn(i,pw+1){
			if ((1ll<<i) & p){
				ans = min(ans, pw-i);
			}
		}
		printf("%d\n", ans);
	}
	
}

int main(){
#ifdef dudkamaster
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
	int tc;
	scanf("%d", &tc);
	for (int tt=1; tt<=tc; tt++){
		read();
		printf("Case #%d: ", tt);
		solve();
	}
	return 0;
}