#include <cstdio>

using namespace std;

#define maxn 100010

int n, m, t, k, c, s;
long long pt[maxn];

int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);

    scanf("%d", &t);

    for(int test=1; test<=t; ++test)
    {
        scanf("%d%d%d", &k, &c, &s);

        printf("Case #%d:", test);

        if(s*c<k)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }

        pt[0]=1;
        for(int i=1; i<=c; ++i)
            pt[i]=pt[i-1]*k;

        int pz=0;
        long long cr=0;

        for(int i=1; i<=k; ++i)
        {
            cr += pt[pz]*(i-1);
            ++pz;
            if(i%c==0)
            {
                printf(" %lld", cr+1);
                cr=0;
                pz=0;
            }
        }

        if(k%c!=0)
            printf(" %lld", cr+1);
        printf("\n");
    }

    return 0;
}





