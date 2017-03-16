#include <bits/stdc++.h>
const int M = 500;
const int CD = 26;
int ch[M][CD];
int Q[M];
int fail[M];
int val[M];
int sz;
int ID[256];
void Reset() 
{
    sz = 1;
    val[0] = 0;
    fail[0] = 0;
    memset(ch[0],0,sizeof(ch[0]));
    for(int i = 0; i < 26; i++) ID['A'+i] = i;
}
void Insert(char *s) 
{
    int p = 0;
    for(;*s;s++) {
        int c =  ID[*s];
        if(!ch[p][c]) {
            val[sz] = 0;
            memset(ch[sz],0,sizeof(ch[sz]));
            ch[p][c] = sz++;
        }
        p = ch[p][c];
    }
    val[p]++;
}
void Construct() 
{
    int *s = Q, *e = Q;
    for(int i = 0; i < CD; i++) {
        if(ch[0][i]) {
            *e++ = ch[0][i];
            fail[ch[0][i]] = 0;
        }
    }
    while(s!=e) {
        int u = *s ++;
        for(int i = 0; i < CD; i++) {
            int &v = ch[u][i];
            if(v) {
                fail[v] = ch[fail[u]][i];
                *e ++ = v;
                val[v] += val[fail[v]];
            } else {
                v = ch[fail[u]][i];
            }
        }
    }
}

//length , node , count of appearance 
double dp[110][M][110];
int f[110][M];
void solve(int len, double p[], int count[])
{
        memset(f, -1, sizeof(f));
        f[0][0] = 0;
        for(int i = 0 ; i <= len; i++) {
                for(int j = 0 ; j < sz; j++) {
                        for(int cnt = 0; cnt <= len; cnt++) {
                                dp[i][j][cnt] = 0.0;
                        }
                }
        }
        /*
        for(int i = 0; i < sz; i++) {
                printf("%d ", val[i]);
        }
        puts("");
        */
        dp[0][0][0] = 1.0;

        for(int i = 0; i < len; i++) {
                for(int j = 0; j < sz; j++) {
                      //  printf("f[%d][%d]=%d\n", i, j, f[i][j]);
                        for(int c = 0; c < 26; c++) if(count[c] && f[i][j] != -1){
                                int to = ch[j][c];
                                f[i + 1][to] = std::max(f[i + 1][to], f[i][j] + val[to]);
                        }
                        for(int cnt = 0; cnt <= len; cnt++) {
                                for(int c = 0; c < 26; c++) {
                                        int to = ch[j][c];
                                        dp[i + 1][to][cnt + val[to]] += dp[i][j][cnt] * p[c];
                                }
                        }
                }
        }
        int mx = 0;
        double ret = 0;
        for(int i = 0; i < sz; i++) {
                mx = std::max(mx, f[len][i]);
                for(int cnt = 0; cnt <= len; cnt++) {
                        ret += cnt * dp[len][i][cnt];
                }
        }
       // printf("mx=%d ret=%.10f\n", mx, ret);
        printf("%.10f\n", (double)mx - ret);
}
int main()
{
        freopen("B.in", "r", stdin);
        freopen("out.txt", "w", stdout);
        int t, ca = 1;
        scanf("%d", &t);
        while(t--) {
                int K, L, S;
                scanf("%d%d%d", &K, &L, &S);
                char origin[110], target[110];
                int cnt[26];
                memset(cnt, 0, sizeof(cnt));
                scanf("%s", origin);
                for(int i = 0; i < K; i++) {
                        cnt[origin[i] - 'A']++;
                }
                double p[26];
                for(int i = 0; i < 26; i++) {
                        p[i] = (double)cnt[i] / K;
                }
                scanf("%s", target);
                Reset();
                Insert(target);
                Construct();
                printf("Case #%d: ", ca++);
                solve(S, p, cnt);
        }
        return 0;
}
