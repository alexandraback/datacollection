#include <stdio.h>
#include <math.h>
#include <string.h>

int counts[10000005];
char s[105];
int slen, si;

bool palin(long long int n)
{
    sprintf(s, "%lld", n);
    slen = strlen(s);
    for(si=0; si<slen; si++){
        if(s[si] != s[slen-si-1])
            break;
    }
    if(si >= slen) return true;
    return false;
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);

    int testcase;
    scanf("%d", &testcase);

    long long int i, a, b, a2, b2, sq;

    int limit = int(sqrt(1000));
    for(i=1; i<=limit; i++)
    {
        counts[i] = counts[i-1];
        if(palin(i) && palin(i*i))
        {
            counts[i]++;
        }
    }

    for(i=1; i<=testcase; i++)
    {
        printf("Case #%lld: ", i);
        scanf("%lld%lld", &a, &b);
        
        a2 = int(sqrt(a));
        b2 = int(sqrt(b));
        sq = a2;
        sq = sq*sq;
        if (sq == a) a2--;
        
        printf("%d\n", counts[b2] - counts[a2]);
    }

    return 0;
}
