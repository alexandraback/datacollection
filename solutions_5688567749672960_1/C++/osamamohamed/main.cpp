#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

long long N;

long long po(long long base , long long expo)
{
    long long ret = 1;
    for(int i = 0;i < expo;++i)
        ret *= base;
    return ret;
}

long long cou(long long num)
{
    int c = 0;
    while(num)
    {
        num /= 10;
        ++c;
    }
    return c;
}

long long rev(long long num)
{
    long long value = 0;
    while(num)
    {
        value = value * 10 + num % 10;
        num /= 10;
    }
    return value;
}

int main()
{
    freopen("A-large.in" , "r" , stdin);
    freopen("out.out" , "w" , stdout);
    int T , c = 0;
    scanf("%d" , &T);
    while(T--)
    {
        ++c;
        scanf("%lld" , &N);
        long long ans = 0;
        while(N)
        {
            while(N % po(10 , cou(N) >> 1) > 1)
            {
                --N;
                ++ans;
            }
            if(rev(N) < N && cou(N) == cou(rev(N)))
            {
                N = rev(N);
                ++ans;
            }
            else
            {
                --N;
                ++ans;
            }
        }
        printf("Case #%d: %lld\n" , c , ans);
    }
    return 0;
}
