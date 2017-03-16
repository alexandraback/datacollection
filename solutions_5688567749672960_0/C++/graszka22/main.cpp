#include <bits/stdc++.h>
#define LL long long int
#define ULL unsigned long long int
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, f, n) for(int i = (f); i <= (n); ++i)
using namespace std;

const int N = 5e6+10;
int t[N], t2[N];

LL rev(LL x)
{
    LL w = 0;
    while(x)
    {
        w *= 10;
        w += x%10;
        x /= 10;
    }
    return w;
}

int brut()
{
    t[1] = 1;
    for(int i = 2; i < N; ++i)
    {
        if(rev(i) < i && rev(rev(i)) == i)
        {
            if(t[rev(i)] < t[i-1])
            {
                t[i] = t[rev(i)]+1;
                t2[i] = rev(i);
            }
            else
            {
                t[i] = t[i-1]+1;
                t2[i] = i-1;
            }
            if(t[rev(i)] > t[i]+1)
                printf("MAMY PROBLEM\n");
        }
        else
        {
            t[i] = t[i-1]+1;
            t2[i] = i-1;
        }
    }
}


int main()
{
    brut();
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i)
    {
        int n;
        scanf("%d", &n);
        printf("Case #%d: %d\n", i, t[n]);
    }
    return 0;
}

