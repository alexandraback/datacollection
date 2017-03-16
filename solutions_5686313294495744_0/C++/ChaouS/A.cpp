#include <bits/stdc++.h>

using namespace std;

const int maxN = 16;

string a[maxN][2];
bool ok[maxN][2][1<<maxN];
int n , dp[1<<maxN];
int solve(int mask){
    if(mask == (1<<n) - 1){
        return 0;
    }
    if(dp[mask]!= -1){
        return dp[mask];
    }

    int answer = 0;
    for(int i = 0; i < n; ++i){
        if(mask & (1<<i)){
            continue;
        }
        int tmp = 0;
        if(ok[i][0][mask] && ok[i][1][mask]){
            tmp = 1;
        }
        answer = max(answer , tmp + solve(mask|(1<<i)));
    }
    return dp[mask] = answer;
}

int main(){

    freopen("C-small-attempt0.in","r",stdin);
    freopen("on.c","w",stdout);

    int tc ;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++){
        scanf("%d",&n);
        for(int i = 0; i < n ; ++i){
            cin >> a[i][0] >> a[i][1];
        }

        for(int mask = 0; mask < 1<<n; mask++){
            for(int type = 0; type < 2; type++){
            set<string> s;
                for(int i = 0; i < n; ++i){
                    if(mask & (1<<i)){
                        s.insert(a[i][type]);
                    }
                }
                for(int i = 0; i < n; ++i){
                    if(s.find(a[i][type]) != s.end()){
                        ok[i][type][mask] = true;
                    }else{
                        ok[i][type][mask] = false;
                    }
                }
            }
        }

        memset(dp, -1,sizeof dp);
        int answer = solve(0);
        printf("Case #%d: %d\n",tt,answer);
    }






    return 0;
}
