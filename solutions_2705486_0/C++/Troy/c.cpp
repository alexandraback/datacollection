#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define ll long long
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
const int totdic = 521196;
const int inf = 1<<29;

char dic[521200][13];
int lendic[521200];
char str[4100];
int n, ans, dp[100][100];
void init() {
    FILE *fd = fopen("garbled_email_dictionary.txt", "r");
    REP(i, totdic) {
        fscanf(fd, "%s", dic[i]);
        lendic[i] = strlen(dic[i]);
        //puts(dic[i]);
    }
    fclose(fd);
}
pii calc(int st, int k, int pv) {
    int pre = (pv == 0 ? -100 : pv), ret = 0;
    for (int i = st, j = 0; j < lendic[k]; i++, j++) {
        if (str[i] != dic[k][j]) {
            if (i - pre < 5) return mp(-1, 0);
            ret++;
            pre = i;
        }
    }
    pre = (pre == -100 ? 0 : pre);
    return mp(ret, pre);
}
int dfs(int p, int pre) {
    if (p >= n+1) {
        return 0;
    }
    if (dp[p][pre] != -1) return dp[p][pre];
    //if (tot >= ans) return;
    //cout <<p <<" "<<tot <<" "<< ans <<endl;
    dp[p][pre] = inf;
    REP(i, totdic) {
        if (p + lendic[i] > n+1) continue;
        pii tmp = calc(p, i, pre);
        if (tmp.fi != -1) dp[p][pre] = min(dp[p][pre], dfs(p + lendic[i], tmp.se) + tmp.fi);
    }
    return dp[p][pre];
}
int main() {
    int T, ca = 0;
    init();
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt1.out", "w", stdout);
    sf("%d", &T);
    while (T--) {
       sf("%s", str+1);
       n = strlen(str+1);
       memset(dp, -1, sizeof(dp));
       ans = dfs(1, 0);
       pf("Case #%d: %d\n", ++ca, ans);
    }
    return 0;
}

