#include <cstdio>
#include <cstring>
#include <cmath>

const int N = 30;
int x[N];
char s1[110];
int p[110];

void init_kmp(char *a, int n)
{
    p[0] = -1;
    p[1] = 0;
    int j = 0;
    for (int i = 2; i <= n; i++)
    {
        while (j != -1 && a[i] != a[j+1]) j = p[j];
        p[i] = ++j;
    }
}


int main()
{
    freopen("in2.txt", "r", stdin);
    freopen("out2", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        int k, l, s;
        scanf("%d%d%d", &k, &l, &s);
        scanf("%s", s1);
        memset(x, 0, sizeof(x));
        for (int i = 0; i < k; ++i)
            x[s1[i]-'A']++;
        scanf("%s", s1+1);
        printf("Case #%d: ", cas);
        bool ff = 0;
        for (int i = 1; i <= l; ++i)
            if (x[s1[i]-'A'] == 0)
            {
                ff = 1;
                break;
            }
        if (ff)
        {
            puts("0.0");
            continue;
        }
        init_kmp(s1, l);
        double tol = (s - p[l]) / (l-p[l]);
        double eat = 0;
        for (int i = 1; i <= l; ++i)
            eat += log(x[s1[i]-'A'] * 1.0/k);
        //printf("%.6f\n", eat);
        double ans = tol - exp(eat) * (s - l + 1);
        printf("%.9f\n", ans);
    }
    return 0;
}
