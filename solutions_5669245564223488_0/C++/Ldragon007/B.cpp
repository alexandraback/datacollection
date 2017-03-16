#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

#define mod 1000000007

char s[100][100];
int pre[30], end[30], p[30], vis[30];
bool bo[30];
int link[30];
int N, n;

long long jc(int n) {
    long long ans = 1;
    for (int i = 1; i <= n; i ++ )
        ans = ans * i % mod;
    return ans;
}

bool check(int i) {
    int j = link[i];
    memset(bo, 0, sizeof(bo));
    bo[i] = true;
    while (j != -1 && !bo[j]) {
        bo[j] = true;
        j = link[j];
    }
    return j != -1;
}

int main() {
    freopen("B0.in", "r", stdin);
    freopen("B0.out", "w", stdout);
    int T;
    cin>>T;
    for (int ca = 1; ca <= T; ca ++ ) {
        cin>>N;
        memset(pre, 0, sizeof(pre));
        memset(end, 0, sizeof(end));
        memset(p, 0, sizeof(p));
        memset(vis, 0, sizeof(vis));
        memset(link, -1, sizeof(link));
        memset(bo, 0, sizeof(bo));
        n = 0;
        for (int i = 0; i < N; i ++ ) {
            cin>>s[i];
            bool flag =false;
            for (int j = 0; j < strlen(s[i]); j ++ ) {
                if (j != 0 && s[i][j] != s[i][j - 1]) {
                    pre[s[i][j - 1] - 'a'] ++ , end[s[i][j] - 'a'] ++ ;
                    link[s[i][j - 1] - 'a'] = s[i][j] - 'a';
                    flag = true;
                }
                vis[s[i][j] - 'a'] ++ ;
            }
            if (!flag) p[s[i][0] - 'a'] ++ ;
        }
        long long ans = 1;
        for (int i = 0; i < 26; i ++ ) {
            if (vis[i]) {
                if (check(i)) ans = 0;
                n ++ ;
            }
            if (pre[i]) n -- ;
            if (pre[i] > 1 || end[i] > 1) ans = 0;
            else ans = ans * jc(p[i]) % mod;
        }
        ans = ans * jc(n) % mod;
        cout<<"Case #"<<ca<<": "<<ans<<endl;
    }
    return 0;
}
