#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

#define mo (1000000007)
int T;
int n;
char s[110][110];
bool flag[110];
int ans;
char now[10010];
bool oc[30];

bool check(int l)
{
    for (int i = 0;i < 30;++i)
        oc[i] = false;
    int i = 0;

    while (i < l)
    {
        if (oc[now[i]-'a']) return false;
        oc[now[i]-'a'] = true;
        int j = i+1;
        while (j < l && now[j] == now[i]) ++j;
        i = j;
    }
    return true;
}

void dfs(int k, int l)
{
    int p;

    if (!check(l)) return;
    if (k > n)
    {
        if (++ans == mo) ans = 0;
    }
    else {
            for (int i = 1;i <= n;++i)
                if (!flag[i])
                {
                    p = l;
                    for (int j = 0;j < strlen(s[i]);++j)
                        now[p++] = s[i][j];
                    flag[i] = true;
                    dfs(k+1, p);
                    flag[i] = false;
                }
       }
}

void doit()
{
    scanf("%d", &n);
    for (int i = 1;i <= n;++i)
    {
        scanf("%s", &s[i]);
        flag[i] = false;
    }
    ans = 0;
    dfs(1, 0);
    printf("%d\n", ans);
}

int main()
{
    freopen("B-small.in","r", stdin);
    freopen("b.out","w", stdout);
    scanf("%d", &T);
    for (int q = 1;q <= T;++q)
    {
        printf("Case #%d: ", q);
        doit();
    }
}
