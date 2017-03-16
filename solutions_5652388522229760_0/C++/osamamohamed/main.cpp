#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int get(long long z)
{
    if(!z)      return 1;

    int ret = 0;
    while(z)
    {
        ret |= 1 << (z % 10);
        z /= 10;
    }
    return ret;
}

int main()
{
    freopen("A-small-attempt0.in" , "r" , stdin);
    freopen("out.out" , "w" , stdout);

    int T , c = 0;
    scanf("%d" , &T);
    while(T--)
    {
        ++c;
        int n;
        scanf("%d" , &n);

        printf("Case #%d: " , c);
        if(!n)
        {
            printf("INSOMNIA\n");
            cerr << c  << "    ->  INSOMNIA\n";
        }

        else
        {
            long long done = 0 , k = 1;
            while(done != (1 << 10) - 1)
            {
                done |= get(n * k);
                ++k;
            }
            printf("%lld\n" , n * (k - 1));
            cerr << c << "   ->  done    " << n * (k - 1) << "\n";
        }
    }
    return 0;
}
