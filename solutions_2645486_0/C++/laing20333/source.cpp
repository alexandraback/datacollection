#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>
#include<climits>
#include<cmath>
#include<memory.h>
#include<sstream>
#include<queue>
#include<time.h>

using namespace std;
typedef long long ll;

ll dp[101][101][101] = {};
int ration[101];

int main(){
    #ifdef LOCAL
        //freopen("input.txt", "r", stdin);
        freopen("B-small-attempt0.in", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif


    int ntest;
    while(cin>>ntest){
        for(int tt=1; tt<=ntest; tt++){
            memset(dp, 0, sizeof(dp));
            int mpower, regain, num;
            cin>>mpower>>regain>>num;
            for(int i=0; i<num; i++){
                cin>>ration[i];
            }

            for(int i=0; i<=mpower; i++){
                dp[0][mpower][i] = ration[0]*i;
                for(int k=0; k<=mpower-i+regain; k++){
                    dp[1][mpower-i+regain][k] = max(dp[1][mpower-i+regain][k], dp[0][mpower][i]);
                }
            }

            for(int i=1; i<num; i++){
                for(int p=0; p<=mpower; p++){
                    for(int r=0; r<=p; r++){
                        if(dp[i][p][r]){
                            dp[i][p][r] =  dp[i][p][r] + ration[i]*r;
                            for(int k=0; k<=p-r+regain; k++){
                                dp[i+1][p-r+regain][k] = max(dp[i+1][p-r+regain][k], dp[i][p][r]);
                            }
                        }
                    }
                }
            }
            ll ans = 0;
            for(int p=0; p<=mpower; p++){
                for(int r=0; r<=p ;r++){
                    ans = max(ans, dp[num-1][p][r]);
                }
            }


            printf("Case #%d: %lld\n", tt, ans);
        }

    }


    return 0;
}
