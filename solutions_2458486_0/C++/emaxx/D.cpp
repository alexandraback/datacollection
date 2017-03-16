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


const int MAXN = 20;
const int MAXK = 201;


int n, start[MAXK], need[MAXN], give[MAXN][MAXK];


void read() {
    int k;
    cin >> k >> n;
    memset(start, 0, sizeof start);
    forn(i,k) {
        int x;
        cin >> x;
        ++start[x];
    }
    forn(i,n) {
        cin >> need[i] >> k;
        memset(give[i], 0, sizeof give[i]);
        forn(j,k) {
            int x;
            cin >> x;
            ++give[i][x];
        }
    }
}


char d[1<<MAXN];

char get_d(int msk, int have[]) {
    if (msk == (1<<n)-1)
        return true;

    char& my = d[msk];
    if (my != -1)
        return my;
    my = false;

    forn(i,n) {
        if (msk & (1<<i))
            continue;
        if (!have[need[i]])
            continue;

        --have[need[i]];
        forn(j, MAXK)
            have[j] += give[i][j];

        my |= get_d(msk + (1<<i), have);

        forn(j, MAXK)
            have[j] -= give[i][j];
        ++have[need[i]];

        if (my)
            break;
    }
    return my;
}

void restore_d(int msk, int have[]) {
    if (msk == (1<<n)-1)
        return;

    forn(i,n) {
        if (msk & (1<<i))
            continue;
        if (!have[need[i]])
            continue;

        --have[need[i]];
        forn(j, MAXK)
            have[j] += give[i][j];

        if (get_d(msk + (1<<i), have)) {
            printf(" %d", i + 1);
            return restore_d(msk + (1<<i), have);
        }

        forn(j, MAXK)
            have[j] -= give[i][j];
        ++have[need[i]];
    }
    throw;
}


void solve() {
    memset(d, -1, sizeof d);

    if (!get_d(0, start)) {
        puts(" IMPOSSIBLE");
        return;
    }

    restore_d(0, start);
    puts("");
}


int main() {
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);

	int ts;
	cin >> ts;
	forn(tt,ts) {
		read();
		if (! cin)  throw;
		printf ("Case #%d:", tt+1);
		solve();
	}
}