#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:16777216")
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <fstream>
#include <math.h>
#include <limits>
#include <set>
#include <map>
#include <sstream>
#include <stdio.h>
#include <time.h>
#include <memory.h>
#include <cassert>
#include <complex>
using namespace std;

///////////////// macros and typedefs ///////////////////
#define rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define repd(i, n) for (int i = (n)-1; i >= 0; --i)
#define _fill(a, x) memset((a), (x), sizeof((a)))
#define DEB(k) cerr<<"debug: "#k<<"="<<k<<endl;
#define all(c) (c).begin(), (c).end()
#define mp(a, b) make_pair(a, b)
#define l(c) (int)((c).size())
#define sqr(a) ((a)*(a))
#define inf 0x7f7f7f7f
#define pb push_back
#define ppb pop_back
#define x first
#define y second
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> pi;

//#define PROBLEM_NAME "my"
#define PROBLEM_NAME "C-small-attempt1"

#define LIM 1000100
#define ID 1000010

int N;
int d[10];
int n[10];
int w[10];
int e[10];
int s[10];
int dd[10];
int dp[10];
int ds[10];
int height[2*LIM];

// day, strength, lo, hi
vector< pair<pi, pi> > attacks;

void solveCase(int tc) {
    _fill(height, 0);
    attacks.clear();
    scanf("%d\n", &N);
    rep(i, N)
        scanf("%d %d %d %d %d %d %d %d", d+i, n+i, w+i, e+i, s+i, dd+i, dp+i, ds+i);
    rep(i, N) {
        rep(j, n[i]) {
            int day = d[i] + j*dd[i];
            int lo = w[i] + j*dp[i];
            int hi = e[i] + j*dp[i] - 1;
            int strength = s[i] + j*ds[i];
            attacks.pb(mp(pi(day, strength), pi(lo, hi)));
        }
    }
    sort(all(attacks));
    //rep(i, l(attacks))
    //    printf("%d %d %d %d\n", attacks[i].x.x, attacks[i].x.y, attacks[i].y.x, attacks[i].y.y);

    int ret = 0;
    for (int i = 0; i < l(attacks); i++) {
        int j = i;
        int day = attacks[i].x.x;
        while (j+1 < l(attacks) && attacks[j+1].x.x == day)
            j++;
        for (int k = i; k <= j; k++) {
            int s = attacks[k].x.y;
            int lo = attacks[k].y.x;
            int hi = attacks[k].y.y;
            for (int o = lo; o <= hi; o++) {
                if (height[ID+o] < s) {
                    ret++;
                    //cout << k << " " << "SUCCESS: " << o << " = " << height[ID+o] << endl;
                    break;
                }
            }
        }
        for (int k = i; k <= j; k++) {
            int s = attacks[k].x.y;
            int lo = attacks[k].y.x;
            int hi = attacks[k].y.y;
            for (int o = lo; o <= hi; o++) {
                if (height[ID+o] < s) {
                    height[ID+o] = s;
                }
            }
        }
        i = j;
    }
    printf("Case #%d: %d\n", tc+1, ret);
}

void solution()
{
    int tc;
    scanf("%d\n", &tc);
    rep(i, tc)
        solveCase(i);
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen(PROBLEM_NAME".in", "rt", stdin);
   freopen(PROBLEM_NAME".out", "wt", stdout);
#endif
   solution();
#ifndef ONLINE_JUDGE
   fprintf(stderr, "Time: %.2lf sec\n", (clock()*1./CLOCKS_PER_SEC));
#endif
   return 0;
}
