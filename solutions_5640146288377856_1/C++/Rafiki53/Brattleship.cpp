#include<bits/stdc++.h>
#define rep(i,k,n) for(int i= (int) k;i< (int) n;i++)
#define mp make_pair
#define pb push_back
#define ft first
#define sd second
typedef long long ll;
const long long inf = 9223372036854775807ll;
const int iinf = 2147483647;
const int limit = 1048576;
using namespace std;

int main(){
    freopen("A-large.in", "r", stdin);
    freopen("A-out.out", "w",stdout);
    int t; cin >> t;
    rep(cas, 1, t + 1){
        int r, c, w; cin >> r >> c >> w;
        vector<int> dp(c + 5);
        dp[w] = w;
        rep(i, w + 1, c + 1){
            if(i <= 2 * w)
                dp[i] = w + 1;
            else{
                dp[i] = iinf;
                rep(j, 1, i + 1){
                    if(j >= w + 1)
                        dp[i] = min(dp[i], 1 + dp[j - 1] + (i - j) / w);
                    if(j <= i - w)
                        dp[i] = min(dp[i], 1 + (j - 1) / w + dp[i - j]);
                }
            }
        }
        cout << "Case #" << cas << ": " << dp[c] + (r - 1) * (c / w) << "\n";
    }
    return 0;
}

