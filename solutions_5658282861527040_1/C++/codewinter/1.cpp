#include <bits/stdc++.h>
using namespace std;

const int LEN = 30;
long long dp[35][2][2][2];

void add(long long &x,long long y)
{
    x += y;
}

void solve()
{
    int a,b,c;
    cin >> a >> b >> c;
    int bit1[35],bit2[35],bit3[35];
    memset(bit1,0,sizeof(bit1));
    memset(bit2,0,sizeof(bit2));
    memset(bit3,0,sizeof(bit3));
    memset(dp,0,sizeof(dp));
    for(int i = LEN; i >= 0; i --) {
        if(a & (1 << i)) bit1[LEN - i] = 1;
        else bit1[LEN - i] = 0;
        if(b & (1 << i)) bit2[LEN - i] = 1;
        else bit2[LEN - i] = 0;
        if(c & (1 << i)) bit3[LEN - i] = 1;
        else bit3[LEN - i] = 0;
    }
    //for(int i = 1; i <= LEN; i ++) cout << bit1[i];
    //cout << endl;
    //for(int i = 1; i <= LEN; i ++) cout << bit2[i];
    //cout << endl;
    //for(int i = 1; i <= LEN; i ++) cout << bit3[i];
    //cout << endl;
    dp[0][1][1][1] = 1;
    for(int i = 0; i < LEN; i ++) {
        if(dp[i][0][0][0]) {
            add(dp[i + 1][0][0][0],4LL * dp[i][0][0][0]);
        } 
        if(dp[i][0][0][1]) {
            if(bit3[i + 1]) {
                add(dp[i + 1][0][0][1],dp[i][0][0][1]);
                add(dp[i + 1][0][0][0],dp[i][0][0][1] * 3);
            }
            else {
                add(dp[i + 1][0][0][1],dp[i][0][0][1] * 3);
            }
        }
        if(dp[i][1][1][0]) {
            if(bit1[i + 1] && bit2[i + 1]) {
                add(dp[i + 1][1][1][0],dp[i][1][1][0]);
                add(dp[i + 1][0][1][0],dp[i][1][1][0]);
                add(dp[i + 1][1][0][0],dp[i][1][1][0]);
                add(dp[i + 1][0][0][0],dp[i][1][1][0]);
            }
            else if(bit1[i + 1]) {
                add(dp[i + 1][1][1][0],dp[i][1][1][0]);
                add(dp[i + 1][0][1][0],dp[i][1][1][0]);
            }
            else if(bit2[i + 1]) {
                add(dp[i + 1][1][1][0],dp[i][1][1][0]);
                add(dp[i + 1][1][0][0],dp[i][1][1][0]);
            }
            else add(dp[i + 1][1][1][0],dp[i][1][1][0]);
        }
        if(dp[i][1][1][1]) {
            if(bit1[i + 1] && bit2[i + 1]) {
                if(bit3[i + 1]) {
                    add(dp[i + 1][1][1][1],dp[i][1][1][1]);
                    add(dp[i + 1][0][1][0],dp[i][1][1][1]);
                    add(dp[i + 1][1][0][0],dp[i][1][1][1]);
                    add(dp[i + 1][0][0][0],dp[i][1][1][1]);
                }
                else {
                    add(dp[i + 1][0][1][1],dp[i][1][1][1]);
                    add(dp[i + 1][1][0][1],dp[i][1][1][1]);
                    add(dp[i + 1][0][0][1],dp[i][1][1][1]);
                }
            }
            else if(bit1[i + 1]) {
                if(bit3[i + 1]) {
                    add(dp[i + 1][1][1][0],dp[i][1][1][1]);
                    add(dp[i + 1][0][1][0],dp[i][1][1][1]);
                }
                else {
                    add(dp[i + 1][1][1][1],dp[i][1][1][1]);
                    add(dp[i + 1][0][1][1],dp[i][1][1][1]);
                }
            }
            else if(bit2[i + 1]) {
                if(bit3[i + 1]) {
                    add(dp[i + 1][1][1][0],dp[i][1][1][1]);
                    add(dp[i + 1][1][0][0],dp[i][1][1][1]);
                }
                else {
                    add(dp[i + 1][1][1][1],dp[i][1][1][1]);
                    add(dp[i + 1][1][0][1],dp[i][1][1][1]);
                }
            }
            else {
                if(bit3[i + 1]) {
                    add(dp[i + 1][1][1][0],dp[i][1][1][1]);
                }
                else add(dp[i + 1][1][1][1],dp[i][1][1][1]);
            }
        }
        if(dp[i][0][1][0]) {
            if(bit2[i + 1]) {
                add(dp[i + 1][0][1][0],2 * dp[i][0][1][0]);
                add(dp[i + 1][0][0][0],2 * dp[i][0][1][0]);
            }
            else {
                add(dp[i + 1][0][1][0],2 * dp[i][0][1][0]);
            }
        }
        if(dp[i][0][1][1]) {
            if(bit2[i + 1]) {
                if(bit3[i + 1]) {
                    add(dp[i + 1][0][1][1],dp[i][0][1][1]);
                    add(dp[i + 1][0][1][0],dp[i][0][1][1]);
                    add(dp[i + 1][0][0][0],dp[i][0][1][1] * 2);
                }
                else {
                    add(dp[i + 1][0][1][1],dp[i][0][1][1]);
                    add(dp[i + 1][0][0][1],dp[i][0][1][1] * 2);
                }
            }
            else {
                if(bit3[i + 1]) {
                    add(dp[i + 1][0][1][0],dp[i][0][1][1] * 2);
                }
                else {
                    add(dp[i + 1][0][1][1],dp[i][0][1][1] * 2);
                }
            }
        }
        if(dp[i][1][0][0]) {
            if(bit1[i + 1]) {
                add(dp[i + 1][1][0][0],dp[i][1][0][0] * 2);
                add(dp[i + 1][0][0][0],dp[i][1][0][0] * 2);
            }
            else {
                add(dp[i + 1][1][0][0],dp[i][1][0][0] * 2);
            }
        }
        if(dp[i][1][0][1]) {
            if(bit1[i + 1]) {
                if(bit3[i + 1]) {
                    add(dp[i + 1][1][0][1],dp[i][1][0][1]);
                    add(dp[i + 1][1][0][0],dp[i][1][0][1]);
                    add(dp[i + 1][0][0][0],dp[i][1][0][1] * 2);
                }
                else {
                    add(dp[i + 1][0][0][1],2 * dp[i][1][0][1]);
                    add(dp[i + 1][1][0][1],dp[i][1][0][1]);
                }
            }
            else {
                if(bit3[i + 1]) {
                    add(dp[i + 1][1][0][0],dp[i][1][0][1] * 2);
                }
                else {
                    add(dp[i + 1][1][0][1],dp[i][1][0][1] * 2);
                }
            }
        }
    }
    cout << dp[LEN][0][0][0] << endl;
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas = 1; cas <= t; cas ++) {
        printf("Case #%d: ",cas);
        solve();
    }
    return 0;
}
