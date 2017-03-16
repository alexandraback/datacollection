#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include "gmpxx.h"
using namespace std;

#define debug(a) cout << #a << ": " << (a) << endl;
typedef long long int64;
#define long int64
#define fst first
#define snd second
typedef mpz_class big;

typedef pair<int, int> pii;
const int INF   = 0x3f3f3f3f;
const long LINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 20;
 
int E, R, N;
int v[MAXN];

int dp[MAXN][MAXN];

int best(int at, int en)
{
    if (at == N)
        return 0;
    if (dp[at][en] != -1)
        return dp[at][en];
    dp[at][en] = 0;
    int& ret = dp[at][en];
    for (int i=0; i<=en; i++)
    {
        ret = max(ret, best(at+1, min(en-i+R, E))+v[at]*i);
    }
    return ret;
}

int main()
{
    int testcases; cin >> testcases;
    for (int kase=1; kase<=testcases; kase++)
    {
        cout << "Case #" << kase << ": ";
        memset(dp, -1, sizeof(dp));
        cin >> E >> R >> N;
        for (int i=0; i<N; i++)
            cin >> v[i];
        cout << best(0, E) << endl;
    }
    return 0;
}
#undef long
