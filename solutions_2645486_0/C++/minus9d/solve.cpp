#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

int main(void)
{
    int T;
    cin >> T;

    for(int t = 0; t < T; ++t){
        int E, R, N;
        cin >> E >> R >> N;
        vector<int> values(N);
        for(int i = 0; i < N; ++i){
            cin >> values[i];
        }

        // task, energy
        int dp[11][6] = {0};

        for(int i = 0; i < N; ++i){
            if (i == 0){
                for(int use = 0; use <= E; ++use){
                    int gain = use * values[i];
                    int hp = min(E - use + R, E);
                    dp[i][hp] = max( dp[i][hp], gain );
                }
            }
            else{
                int mx = -1;
                for(int use = 0; use <= E; ++use){
                    for(int rem = 0; rem <= E; ++rem){
                        if (rem < use) continue;
                        int gain = use * values[i];
                        int hp = min(rem - use + R, E);
                        int sum = gain + dp[i-1][rem];
                        
                        dp[i][hp] = max( dp[i][hp], sum );
                    }
                }
            }

            // for(int use = 0; use <= E; ++use){
            //     printf("%d ", dp[i][use]);
            // }
            // printf("\n---\n");
            
            
        }

        int ans = 0;
        for(int use = 0; use <= E; ++use){
            ans = max(ans, dp[N-1][use]);
        }


        cout << "Case #" << (t+1) << ": " << ans << endl;
    }

    return 0;
}
