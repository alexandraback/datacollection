#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int M = 16807;
string s;
int P[11] = {0, 0, 3, 2, 3, 2, 7, 2, 3, 2, 3};
int a[11][50];
int n, m;
int dp[32][M];
int transfer(int A, int sgn, int pos) {
    int c[5];
    for(int i = 0 ; i < 5 ; i ++) {
        c[i] = A % 7;
        A /= 7;
    }
    for(int i = 0, j = 2 ; i < 5 ; i ++ , j += 2) {
        c[i] = ((c[i] + sgn * a[j][pos]) % P[j] + P[j]) % P[j];
    }
    int B = 0;
    for(int i = 4 ; i >= 0 ; i --) {
        B = B * 7 + c[i];
    }
    return B;
}
void update(int &A, int B) {
    A += B;
    if (A >= 1000000) A = 1000000;
}
void dfs(int idx, int state, int cnt, string str) {
    if(!cnt) return;
    if (idx == 0) {
        for(int i = 0 ; i < cnt ; i ++) {
            printf("1%s11", str.c_str());
            for(int j = 2 ; j <= 10 ; j ++) {
                printf(" %d", P[j]);
            }
            puts("");
        }
        return ;
    }

    for (int i = 0 ; i < 2 ; i ++) {
        int nxt = transfer(state, -1 * i, idx + 1);
        char now = char('0' + i);
        if(dp[idx - 1][nxt] >= cnt) {
            dfs(idx - 1, nxt, cnt, str + now);
            break;
        }
        else {
            dfs(idx - 1 , nxt , dp[idx - 1][nxt], str + now);
            cnt -= dp[idx - 1][nxt];
        }
    }
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int t, cas = 0;
    scanf ("%d" , &t);
    for(int i = 2 ; i <= 10 ; i ++) {
        a[i][0] = 1;
        for (int j = 1 ; j < 50 ; j ++) {
            a[i][j] = (a[i][j - 1] * i) % P[i];
        }
    }
    while (t --) {
        scanf ("%d %d", &n, &m);
        memset (dp, 0, sizeof (dp));

        int st = 0;
        for(int i = 10; i >= 2; i -= 2) {
            st = st * 7 + (1 + i + a[i][n - 1]) % P[i];
        }
        printf("Case #%d:\n", ++ cas);

        dp[0][st] = 1;
        for(int i = 0; i < n - 3; i ++) {
            for(int j = 0 ; j < M ; j ++) {
                if(!dp[i][j]) continue;
                for(int k = 0 ; k < 2 ; k ++) {
                    int nxt = transfer(j, k, i + 2);
                    update(dp[i + 1][nxt], dp[i][j]);
                    //cout << i + 1 << " " << nxt << " " << dp[i + 1][nxt] << endl; 
                } 
            }
        }

        dfs(n - 3, 0, m, "");
    }
	return 0;
}
	
