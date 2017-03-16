#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int dp[12][6];

int
main(void)
{
    int T;
    int i, j, ret;
    int a, b, c, e, f;
    int E, R, N;
    int v[10];

    cin >> T;

    for(i=1;i<=T;i++) {
        cin >> E >> R >> N;
        for(j=0;j<N;j++) {
            cin >> v[j];
        }
        memset(dp, 0xff, sizeof(dp));
        
        dp[0][E] = 0;
        for(a=0;a<N;a++) {
            for(b=1;b<=E;b++) {
                if (dp[a][b] < 0)
                    continue;
                for(e=0;e<=b;e++) {
                    dp[a+1][min(b-e+R,E)] = max(dp[a+1][min(b-e+R,E)], dp[a][b] + v[a]*e);
                }
            }
        }
        ret = 0;
        for(a=0;a<=N;a++) {
            for(b=0;b<=E;b++) {
                ret = max(ret, dp[a][b]);
            }
        }
        
        cout << "Case #" << i << ": " << ret << endl;
    }
    
    return 0;
}
