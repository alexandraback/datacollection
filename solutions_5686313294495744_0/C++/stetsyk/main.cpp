#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <set>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#ifdef lyosha
#define files freopen("input.txt", "r", stdin);
#else
#define files //freopen("howmany.in","r",stdin); freopen("howmany.out","w",sdout);
#endif
using namespace std;
typedef long long ll;
#define y1 fjlwekf
double EPS = 1e-9;
double INF = 1e-9;
const ll mod = 1e9 + 7;
const ll N = 2005;
int n;
int dp[(1 << 16)];
string s[N][2];
int a[N][2];
int main()
{
    freopen("C-small-attempt0.in","r",stdin); freopen("output.txt","w",stdout);
    ll T;
    cin >> T;
    for(ll qw = 1; qw <= T; ++qw)
    {
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> s[i][0] >> s[i][1];
        }
        map<string, int> mp;
        for(int i = 0; i < n; ++i){
            if(mp.count(s[i][0])){
                a[i][0] = mp[s[i][0]];
            }
            else{
                a[i][0] = mp.size();
                mp[s[i][0]] = a[i][0];
            }
            if(mp.count(s[i][1])){
                a[i][1] = mp[s[i][1]];
            }
            else{
                a[i][1] = mp.size();
                mp[s[i][1]] = a[i][1];
            }
        }
        memset(dp, 0, sizeof(dp));
        for(int msk = 0; msk < (1 << n); ++msk){
            for(int i = 0; i < n; ++i){
                if((1 << i) & msk) continue;
                int fl1 = 0;
                int fl2 = 0;
                for(int j = 0; j < n; ++j){
                    if((1 << j) & msk){
                        if(a[j][0] == a[i][0]) fl1 = 1;
                        if(a[j][1] == a[i][1]) fl2 = 1;
                    }
                }
                if(fl1 && fl2)
                    dp[msk | (1 << i)] = max(dp[msk | (1 << i)], dp[msk] + 1);
                else
                    dp[msk | (1 << i)] = max(dp[msk | (1 << i)], dp[msk]);
            }
        }
        cout << "Case #" << qw << ": " << dp[(1 << n) - 1] << "\n";
    }
    return 0;
}
