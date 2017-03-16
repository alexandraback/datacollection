#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 52;
const int maxm = 521196 + 100;

char dic[maxm][20];
int len[maxm];
char s[maxn];
int f[maxn][5];
int T, n, m;

void readdata() {
     m = 0;
     //FILE *dicfile = fopen("garbled_email_dictionary.txt", "r");
     freopen("garbled_email_dictionary.txt", "r", stdin);
     while (scanf("%s",dic[m++]) != EOF)
           len[m-1] = strlen(dic[m-1]);
     --m;
     fclose(stdin);
}

void update(int & a, int b ) { if (b<a) a = b; }

int main() {
    readdata();
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    scanf("%d",&T);
    for (int cas = 1; cas <= T; cas++ ) {
        scanf("%s",s);
        n = strlen(s);
        for (int i = 0; i<maxn; i++ )
            for (int j = 0; j<5; j++ )
                f[i][j] = n;
        f[0][4] = 0;
        for (int i = 0; i<n; i++ )
            for (int j = 0; j<5; j++ )
                if (f[i][j] < n) {
                   for (int k = 0; k<m; k++ )
                       if (i + len[k] <= n) {
                             bool ok = true;
                             int pre = j, cnt = 0;
                             for (int p = 0, t = -1; p<len[k]; p++, t-- )
                                 if (s[i+p] != dic[k][p])
                                    if (pre - t < 5) ok = false;
                                    else { pre = t; ++cnt; }
                             if (ok) update(f[i+len[k]][min(4,pre+len[k])], f[i][j]+cnt);
                       }
                }
        int ans = n;
        for (int i = 0; i<5; i++ )
            ans = min(ans, f[n][i]);
        printf("Case #%d: %d\n",cas,ans);
    }
    //system("pause");
    return 0;
}
