#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int A[1050] , D;

int check(int mi)
{
    int ret = 0;
    int ma = 0;
    for(int i = 0;i < D;++i)
    {
        if(A[i] > mi)
        {
            ret += ((A[i] + (mi - 1)) / mi) - 1;
            ma = max(ma , mi);
        }
        else
            ma = max(ma , A[i]);
    }

    return ret + ma;
}

int main()
{
    freopen("B-small-attempt1.in" , "r" , stdin);
    freopen("out.out" , "w" , stdout);

    int T , c = 0;
    scanf("%d" , &T);
    while(T--)
    {
        ++c;
        scanf("%d" , &D);

        for(int i = 0;i < D;++i)
            scanf("%d" , &A[i]);

        sort(A , A + D);
        int ans = 1 << 30;
        for(int i = A[D - 1];i > 0;--i)
            ans = min(ans , check(i));

        printf("Case #%d: %d\n" , c , ans);
    }
    return 0;
}
