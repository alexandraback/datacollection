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

#define PROBLEM_NAME "A-large"

int n, k;
char s[1000007];
int good[1000007];

int countGood(int l, int r) {
    if (l == 0) return good[r];
    return good[r]-good[l-1];
}

bool isConsonants(char c) {
    return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void solveCase(int tc) {
    scanf("%s %d\n", s, &k);
    _fill(good, 0);
    n = strlen(s);
    int have = 0;
    rep(i, n) {
        if (isConsonants(s[i])) {
            have++;
            if (have >= k)
                good[i] = 1;
        } else {
            have = 0;
        }
    }
    for (int i = 1; i < n; i++)
        good[i] += good[i-1];
    ll ret = 0;
    int head = 0;
    for (int i = 0; i+k-1 < n; i++) {
        head = max(head, i+k-1);
        while (head < n && countGood(i+k-1, head) == 0)
            head++;
        ret += n-head;
    }
    cout << "Case #" << (tc+1) << ": " << ret << endl;
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
