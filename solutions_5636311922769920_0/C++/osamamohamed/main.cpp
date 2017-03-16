#include <iostream>
#include <cmath>
#include <cstdio>
#include <assert.h>
#include <algorithm>

using namespace std;

int k , c , s;

long long expo(long long base  , long long exp)
{
    long long ans = 1;
    while(exp)
    {
        if(exp & 1)     ans *= base;
        base *= base;
        exp >>= 1;
    }
    return ans;
}

int main()
{
    freopen("D-small-attempt0.in" , "r" , stdin);
    freopen("out.out" , "w" , stdout);

    int T , cc = 0;
    scanf("%d" , &T);
    while(T--)
    {
        ++cc;
        scanf("%d%d%d" , &k , &c , &s);
        long long all = expo(k , c);


        vector < long long > ans;

        for(int i = 1;i <= k;i += c)
        {
            long long z = (i - 1) * (all / k) + 1;
            long long block = (all / k);
            for(int j = i + 1;j <= min(k , i + c - 1);++j)
            {
                assert(block > 1);
                z += (j - 1) * (block /= k);
            }
            ans.push_back(z);
        }
        printf("Case #%d: " , cc);
        if(ans.size() > s)
            printf("IMPOSSIBLE");

        else
            for(int i = 0;i < (int)ans.size();++i)
                printf("%lld " , ans[i]);

        cerr << cc << "   -> done    " << s << "  " << ans.size() << "\n";
        printf("\n");
    }
    return 0;
}

//int main()
//{
//    freopen("D-small-attempt0.in" , "r" , stdin);
//    freopen("out.out" , "w" , stdout);
//    int T , cc = 0;
//    scanf("%d" , &T);
//    while(T--)
//    {
//        ++cc;
//        scanf("%d%d%d" , &k , &c , &s);
//
//        printf("Case #%d: " , cc);
//        for(int i = 0;i < k;++i)
//            printf("%d " , i + 1);
//
//
//        printf("\n");
//    }
//    return 0;
//}
