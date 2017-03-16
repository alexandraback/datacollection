#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

#define mo (1000000007)
int T;
int n;
int a[30], b[30], c[30];
char s[110];
bool oc[30];
long long ans;
long long f[110];

int tt;

int e[30];


bool check(char *s)
{
    int l = strlen(s);

    oc[s[0]-'a'] = true;
    oc[s[l-1]-'a'] = true;

    int i = 1;
    int j = l-2;
    while (i < l && s[i] == s[0]) ++i;
    while (j >= 0 && s[j] == s[l-1]) --j;
  //  printf("aa%d %d\n", i, j);
    for (int t = i;t <= j;++t)
        if (oc[s[t]-'a']) return false;
    if (i <= j && s[0] == s[l-1]) return false;

    if (s[0] != s[l-1])
    {
        ++a[s[0]-'a'];
        ++b[s[l-1]-'a'];
        e[s[0]-'a'] = s[l-1]-'a';
    }
    else ++c[s[0]-'a'];
    return true;
}

void dfs(int p)
{
   // long long ans = f[c[p]];

    oc[p] = false;
    if (e[p] != -1) dfs(e[p]);



}

void doit(int oo)
{
    scanf("%d", &n);
    for (int i = 0;i < 30;++i)
    {
        a[i] = 0; b[i] = 0;
        c[i] = 0;
        oc[i] = false;
        e[i] = -1;
    }

    ans  = 1; tt = 0;
    for (int i = 1;i <= n;++i)
    {
        scanf("%s", &s);
        if (ans == 1 && !check(s)) ans = 0;
      //   printf("%d\n", ans);
       // printf("%s ", s);
    }

  //  printf("%d\n", ans);
 //   for (int i = 0;i < 4;++i)
    //    printf("%d %d %d %d\n", a[i],b[i],c[i], oc[i]);
    for (int i = 0;i < 26;++i)
        if (a[i] > 1 || b[i] > 1) ans = 0;
    if (ans == 1)
    {
        for (int i = 0;i < 26;++i)
           ans = (ans * f[c[i]]) % mo;
        for (int i = 0;i < 26;++i)
            if (oc[i] && b[i] == 0)
            {
                ++tt;
                dfs( i );
            }
        ans = (ans * f[tt]) % mo;

        for (int i = 0;i < 26;++i)
            if (oc[i]) ans = 0;

    }
    int aa = ans;
    printf("%d\n", aa);
}

int main()
{
    freopen("B-large.in","r", stdin);
    freopen("B1.out","w", stdout);
    f[0] = 1;
    for (int i = 1;i <= 100;++i)
        f[i] = (f[i-1]*i) % mo;
    scanf("%d", &T);
    for (int q = 1;q <= T;++q)

    {
        printf("Case #%d: ", q);
         doit(q);
    }

    return 0;
}
