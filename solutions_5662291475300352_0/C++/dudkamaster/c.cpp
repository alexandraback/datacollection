# define _USE_MATH_DEFINES
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <fstream>
#include <iostream>
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

#define forn(i,n) for (int i=0; i<int(n); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;


const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

vector <pair <double, double> > hikers;

void read(){
    int n;
    hikers.clear();
    scanf("%d", &n);
    forn(i,n) {
        int d, h, m;
        scanf("%d%d%d", &d, &h, &m);
        forn(j,h) {
            hikers.pb(mp((double)d, (double)m+j));
        }
    }
}

void solve(){
    if (sz(hikers) < 2) {
        puts("0");
    } else {
        double end[2];
        forn(i,2) {
            end[i] = (360-hikers[i].first)/360.0 * hikers[i].second;
        }
        if (end[0] < end[1]) {
            swap(hikers[0], hikers[1]);
            swap(end[0], end[1]);
        }
        double fpos[2];
        forn(i,2)
            fpos[i] = hikers[i].first + 360.0/hikers[i].second*end[0];
        if (fpos[1] >= 720)
            puts("1");
        else
            puts("0");
    }
}

int main(){
#ifdef dudkamaster
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int test_cases;
    scanf("%d", &test_cases);
    for (int test = 1; test <= test_cases; test++) {
        read();
        printf("Case #%d: ", test);
        solve();
    }
    return 0;
}
