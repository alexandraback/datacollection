#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long int test;
    scanf("%ld", &test);
    for(long int i=1; i<=test; i++)
    {
        long long int r, t;
        scanf("%I64d %I64d", &r, &t);
        long long int curr = 0LL;
        long  long int count = 0LL;
        for(long long int j=r+1; ; j+=2)
        {
            curr = 2*j-1;
            if(curr<=t)
            {
                t = t - curr;
                count++;
            }
            else
                break;
        }
        printf("Case #%ld: %lld\n", i, count);
    }
    return 0;
}
