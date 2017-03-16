#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
/*
double f[200][200];
char c[200];
double p['Z'];
double s[200][200];

int K, L, S, T;

int main()
{
    scanf("%d", &T);
    for(int I = 1; I <= T; I++)
    {
        scanf("%d%d%d", &K, &L, &S);
        scanf("%s", c);
        memset(p, 0, sizeof p);
        for(int i = 0; i < K; i++) p[c[i]]++;
        for(char i = 'A'; i <= 'Z'; i++) p[i] /= (double)K;
        int MAX = 0;
        scanf("%s", c);
        for(int i = 0; i < L; i++)
        {
            bool flg = true;
            for(int j = i; j < L; j++)
                if(c[j] != c[j - i]) flg = false;
            if(flg) MAX = max(MAX, i);
        }
        MAX = L - MAX;
        if(S < L) { printf("Case %d: 0.0\n", I); continue; }
        bool flg = false;
        for(int i = 0; i < L; i++) if(p[c[i]] == 0.0) flg = true;
        if(flg) { printf("Case %d: 0.0\n", I); continue; }

        for(int i = 0; i < L; i++)
        {
            s[i][i] = p[c[i]];
            for(int j = i + 1; j < L; j++)
            {
                s[i][j] = s[i][j - 1] * p[c[j]];
            }
        }
        memset(f, 0, sizeof f);
        for(int i = 0; i < L; i++)
            for(int j = 0; j < i; j++)
                f[i][j] =
    }
    return 0;
}
*/

int T, K, L, S;
char s[10];
char f[10], c[10];
int tot;
int m;
int cc;

void dfs(int dep)
{
    if(dep == S)
    {
        tot++;
        int p = 0;
        for(int i = 0; i <= S - L; i++)
        {
            bool flg = true;
            for(int j = 0; j < L; j++)
                if(f[i + j] != c[j]) flg = false;
            if(flg) { cc++; p++; }
        }
        m = max(m, p);
        return;
    }
    for(int i = 0; i < K; i++)
    {
        f[dep] = s[i];
        dfs(dep + 1);
    }
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    scanf("%d", &T);
    for(int ii = 0; ii < T; ii++)
    {
        scanf("%d%d%d", &K, &L, &S);
        memset(s, 0, sizeof s);
        memset(c, 0, sizeof c);
        scanf("%s%s", s, c);
        if(S < L) { printf("Case #%d: 0.0000\n", ii + 1); continue; }
        tot = 0; m = 0; cc = 0;
        memset(f, 0, sizeof f);
        dfs(0);
        //cout << m << " " << tot << " " << cc << endl;
        if(m == 0) { printf("Case #%d: 0.0000\n", ii + 1); continue; }
        printf("Case #%d: %.9f\n", ii + 1, (double)m - (double)cc / tot);
    }
    fclose(stdout);
    return 0;
}
