#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <string.h>
#include <sstream>
#include <math.h>
using namespace std;




int dp[20][10];

int getMaxValue(int v[], int n, int E, int R)
{
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<=E; ++i)
        dp[0][i] = 0;
    for(int i=1; i<=n; ++i){
        for(int r = 0; r <= E; ++r){
            //if(dp[i-1][r] == -1) continue;
            for(int spend = 0; spend <= r; ++spend){
                int maxValue = dp[i-1][r] + v[i-1]*spend;
                int left = min(r-spend+R, E);
                dp[i][left] = max(dp[i][left], maxValue);
                //cout << "dp["<<i<<"][" <<left<<"]="<< dp[i][left] << endl;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<=E; ++i)
    ans = max(ans, dp[n][i]);
    return ans;
}


int value[100];

int main()
{
    int T;
    //ull r, t;
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int E,R,N;
    cin>>T;
    for(int ca=1; ca<=T; ++ca){
        //scanf("%ulld%ulld", &r, &t);
        cin>>E>>R>>N;
        for(int i=0; i<N; ++i)
        cin>>value[i];
        int ans = getMaxValue(value, N, E, R);
        cout << "Case #" << ca << ": "<< ans << endl;
        //printf("Case #%d: %ulld\n", ca, ans);
    }
    return 0;
}
