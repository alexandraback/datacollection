#include <bits/stdc++.h>
#define LL long long int
#define ULL unsigned long long int
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, f, n) for(int i = (f); i <= (n); ++i)
using namespace std;

const int N = 10;

int str[N];
char target[N];
char keyboard[N];
int k, l, s;
LL maxi = 0;
LL fun(int p)
{
    LL sum = 0;
    if(p == s)
    {
        for(int i = 0; i <= s-l; ++i)
        {
            bool ok = true;
            for(int j = 0; j < l; ++j)
            {
                if(str[i+j] != target[j])
                {
                    ok = false;
                    break;
                }
            }
            sum += ok;
        }
        maxi = max(maxi, sum);
        return sum;
    }

    REP(i, k)
    {
        str[p] = keyboard[i];
        sum += fun(p+1);
    }
    return sum;
}

LL pot(int x, int n)
{
    LL w = 1;
    REP(i, n)
        w *= x;
    return w;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t)
    {
        scanf("%d%d%d", &k, &l, &s);
        scanf(" %s %s", keyboard, target);
        maxi = 0;
        LL sum = fun(0);
        printf("Case #%d: %f\n", t, maxi-(double)(sum)/pot(k, s));
    }
    return 0;
}

