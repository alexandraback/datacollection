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

#define FILE_NAME "C-small-attempt0"

ll A, B;
char s[107];

bool isPali(ll k) {
    int len = sprintf(s, "%lld", k);
    int lo = 0, hi = len-1;
    while (lo < hi) {
        if (s[lo] != s[hi])
            return false;
        lo++; hi--;
    }
    return true;
}

void solveCase(int tc) {
    cin >> A >> B;
    int a = max(1, int(sqrt(A))-1);
    int b = sqrt(B)+2;
    int ret = 0;
    for (int i = a; i <= b; i++) {
        ll sqi = i*1ll*i;
        if (sqi < A || sqi > B) continue;
        if (isPali(i) && isPali(sqi)) {
            ret++;
            //printf("%d - %lld\n", i, sqi);
        }
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
   freopen(FILE_NAME".in", "rt", stdin);
   freopen(FILE_NAME".out", "wt", stdout);
#endif
   solution();
#ifndef ONLINE_JUDGE
   fprintf(stderr, "Time: %.2lf sec\n", (clock()*1./CLOCKS_PER_SEC));
#endif
   return 0;
}
