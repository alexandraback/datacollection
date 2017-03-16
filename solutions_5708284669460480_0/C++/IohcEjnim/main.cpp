#include <stdio.h>

int t, tn;
int k, l, s;
char K[110], L[110];
int rep;
double bri, exp;
double pro[30];

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("result.out", "w", stdout);
    int i, j;
    scanf("%d", &t);
    for (tn = 1; tn <= t; tn++)
    {
        scanf("%d %d %d", &k, &l, &s);
        scanf("%s %s", K+1, L+1);
        
        rep = 0;
        for (i = l-1; i >= 1; i--)
        {
            for (j = 1; j <= i; j++)
                if (L[j] != L[l-i+j]) break;
            if (j == i+1)
            {
                rep = i;
                break;
            }
        }
        
        bri = 1+(s-l)/(l-rep);
        
        for (i = 0; i < 26; i++) pro[i] = 0;
        for (i = 1; i <= k; i++)
            pro[K[i]-'A'] += (double)1/k;
        exp = 1;
        for (i = 1; i <= l; i++)
        {
            exp *= pro[L[i]-'A'];
            if (pro[L[i]-'A'] == 0) bri = 0;
        }
        exp *= s-l+1;
        
        printf("Case #%d: %.8lf\n", tn, bri-exp);
    }
}