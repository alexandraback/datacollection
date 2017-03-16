#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 10

int t, n, m, c;
int f[maxn];

long long solve(long long nr)
{
    memset(f, 0, sizeof(f));
    c=0;
    long long cr=0;
    for(cr = nr; c<10; cr += nr)
    {
        long long x = cr;

        while(x>0)
        {
            if(f[x%10]==0)
            {
                ++c;
                f[x%10]=1;
            }
            x/=10;
        }
        if(c==10)
            return cr;
    }

    return cr;
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("data.out", "w", stdout);

    scanf("%d", &t);
    for(int test=1; test<=t; ++test)
    {
        scanf("%d", &n);
        if(n==0)
             printf("Case #%d: INSOMNIA\n", test);
        else
            printf("Case #%d: %lld\n", test, solve(n));
    }

    return 0;
}


