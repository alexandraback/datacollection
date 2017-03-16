//#pragma comment(linker,"/STACK:100000000000,100000000000")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <iomanip>
#include <queue>
#include <map>
#include <functional>
#include <list>
#include <sstream>
#include <ctime>
#include <climits>
#include <bitset>
#include <list>
#include <cassert>
#include <complex>

using namespace std;

/* Constants begin */
const long long inf = 2e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-12;
const double PI = 2*acos(0.0);
const double E = 2.71828;
/* Constants end */

/* Defines begin */
#define pb push_back
#define mp make_pair
#define ll long long
#define double long double
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define forn(i,n) for (int (i)=0; (i)<(n); ++(i))
#define random (rand()<<16|rand())
#define sqr(x) (x)*(x)
#define base complex<double>
/* Defines end */

int t;
int n;
int a[1005];

void Solve() {
    scanf("%d", &n);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        mx = max(mx, a[i]);
    }
    int res = mod;
    for (int i = 1; i <= mx; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            cnt += (a[j] + i - 1) / i - 1;
        }
        res = min(res, i + cnt);
    }
    printf("%d\n", res);
}

int main(void){
    #ifdef nobik
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        Solve();
    }
    return 0;
}
