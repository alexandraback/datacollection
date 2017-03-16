#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int N, S, p;
int t[103];

int dp[103][103];
int sol(int n, int s)
{
    int &R = dp[n][s];
    if (R>=0) return R;
    R = 0;
    if (n && s && t[n-1]>=p && t[n-1]>=3*p-4)R = max(R,1+sol(n-1,s-1));
    if (n && t[n-1]>=p && t[n-1]>=3*p-2) R = max(R,1+sol(n-1,s));
    else if (n) R = max(R,sol(n-1,s));
    return R;
}

int main()
{
    //freopen("in.txt", "rt", stdin);
    freopen("B-small-attempt1.in", "rt", stdin);
    freopen("B-small-attempt1.out", "wt", stdout);
    int T;
    cin>>T;
    for (int cas=1; cas<=T; ++cas)
    {
        memset(dp,-1,sizeof dp);
        cin>>N>>S>>p;
        for (int i=0; i<N; ++i) cin>>t[i];
        int cnt = sol(N,S);
        printf("Case #%d: %d\n", cas, cnt);
    }
    return 0;
}
