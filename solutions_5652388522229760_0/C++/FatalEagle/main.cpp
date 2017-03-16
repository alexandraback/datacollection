#include <bits/stdc++.h>

using namespace std;

void _main(int TEST)
{
    int N;
    scanf("%d", &N);
    vector<bool> seen(10);
    if(N==0)
        printf("INSOMNIA\n");
    else
    {
        for(int i=1; i<=1000000; i++)
        {
            long long x=1LL*i*N;
            while(x)
            {
                seen[x%10]=true;
                x/=10;
            }
            bool good=true;
            for(int i=0; i<10; i++) if(!seen[i])
                good=false;
            if(good)
            {
                printf("%lld\n", 1LL*i*N);
                return;
            }
        }
        fprintf(stderr, "ERROR\n");
    }
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int TEST;
    scanf("%d", &TEST);
    for(int i=1; i<=TEST; i++)
    {
        printf("Case #%d: ", i);
        _main(i);
    }
    return 0;
}
