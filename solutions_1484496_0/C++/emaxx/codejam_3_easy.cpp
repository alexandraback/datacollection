#pragma comment (linker, "/STACK:200000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;


typedef long long int64;
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define fore(i,l,n)  for (int i=int(l); i<int(n); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define pb  push_back
#define mp  make_pair


int n, a[100];
pair<int,int> v[1<<21];


void read() {
	cin >> n;
	forn(i,n)
		cin >> a[i];
}


void out (int msk) {
	bool fs = true;
	forn(i,n)
		if (msk & (1<<i)) {
			if (!fs)  printf (" ");
			printf ("%d", a[i]);
			fs = false;
		}
	puts("");
}


void solve() {
	for (int msk=1; msk<(1<<n); ++msk) {
		int s = 0;
		forn(i,n)
			if (msk & (1<<i))
				s += a[i];
		v[msk-1] = mp (s, msk);
	}

	sort (v, v+(1<<n)-1);
	forn(i,(1<<n)-2)
		if (v[i].fs == v[i+1].fs) {
			out (v[i].sc);
			out (v[i+1].sc);
			return;
		}
	puts ("Impossible");
}


int main() {
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
	
	int ts;
	cin >> ts;
	forn(tt,ts) {
		read();
		printf ("Case #%d:\n", tt+1);
		solve();
	}

}