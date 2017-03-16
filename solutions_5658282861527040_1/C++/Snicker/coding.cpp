#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
int T;
long long A,B,K;
long long dp[100][2][2][2];
long long search(int pos, int bigA, int bigB, int big) {
    if(pos == -1) {
        return 1;
    }
    if(dp[pos][bigA][bigB][big] != -1) {
        return dp[pos][bigA][bigB][big];
    }
    dp[pos][bigA][bigB][big] = 0;
    
    long long topa = bigA, topb = bigB;
    long long sa = 0, sb = 0, ss = 0;
    if( ((1ll<<pos) & A) ) {
        topa = 1;
        sa = 1;
    }

    if( ((1ll<<pos) & B) ) {
        topb = 1;
        sb = 1;
    }

    if( ((1ll<<pos) & K) ) {
        ss = 1;
    }

    for(long long a = 0; a <= topa; a++) {
        for(long long b = 0; b <= topb; b++) {
            long long nx = (a & b);
            if(big || ss) {
                dp[pos][bigA][bigB][big] += search(pos - 1, a < sa || bigA, b < sb || bigB, nx < ss || big);    
            } else {
                if(nx == 0) {
                    dp[pos][bigA][bigB][big] += search(pos - 1, a < sa || bigA, b < sb || bigB, nx < ss || big);    
                }
            }
        }
    }
    return dp[pos][bigA][bigB][big];
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    int cas = 0;
    while(T--) {
        cin>>A>>B>>K;
        A--, B--, K--;
        memset(dp, -1, sizeof(dp));
        printf("Case #%d: %I64d\n", ++cas, search(40, 0, 0, 0));
    }
    return 0;
}
