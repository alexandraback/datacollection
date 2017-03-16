#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment (linker, "/STACK:200000000")
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
//typedef double old_double;
//#define double long double
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


string a[4];


void read() {
    forn(i,4)
        cin >> a[i];
}


void upd_ans(char a, char b, char c, char d, int& ans) {
    string s;
    s += a;
    s += b;
    s += c;
    s += d;
    if (count(all(s), 'X') + count(all(s), 'T') == 4)
        ans = 1;
    if (count(all(s), 'O') + count(all(s), 'T') == 4)
        ans = -1;
}

void solve() {
    int ans = 0;
    forn(i,4) {
        upd_ans(a[i][0], a[i][1], a[i][2], a[i][3], ans);
        upd_ans(a[0][i], a[1][i], a[2][i], a[3][i], ans);
    }
    upd_ans(a[0][0], a[1][1], a[2][2], a[3][3], ans);
    upd_ans(a[0][3], a[1][2], a[2][1], a[3][0], ans);
    if (ans == 1)
        puts("X won");
    else if (ans == -1)
        puts("O won");
    else {
        string s = a[0] + a[1] + a[2] + a[3];
        if (!count(all(s), '.'))
            puts("Draw");
        else
            puts("Game has not completed");
    }
}


int main() {
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);

	int ts;
	cin >> ts;
	forn(tt,ts) {
		read();
		if (! cin)  throw;
		printf ("Case #%d: ", tt+1);
		solve();
	}
}