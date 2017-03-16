#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>

#define rep(i, a, b) for(int i = a; i < b; i++)

#define MAX 15

typedef long long ll;

using namespace std;

int t;
ll e, r, n;
ll dp[MAX][MAX];

int main(){
    cin >> t;
    
    rep(z, 1, t+1){
        cin >> e >> r >> n;
        vector<ll> v(n+1);
        rep(i, 0, n){
            cin >> v[i];
        }
        
        rep(i,0,MAX){
            rep(j,0,MAX){
                dp[i][j] = 0;
            }
        }
        if(r > e) r = e;
        rep(i,0,n){
            rep(j,0,e+1){
                if(j-r < 0)continue;
                rep(k,0,e+r-j+1){
                    if(0 <= (j - r + k)){
                        dp[i+1][j] = max(dp[i+1][j],dp[i][j-r+k]+k*v[i]);
                        //cout << dp[i+1][j] << ' ' << j << ' ' << k << endl;
                    }
                }
            }
            //cout << endl;
        }
        
        cout << "Case #" << z << ": " << dp[n][r] << endl;
    }
    
    
    return 0;
}