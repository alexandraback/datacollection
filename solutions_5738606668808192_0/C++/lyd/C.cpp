#include <stdio.h>

void print_2(long long p,int len)
{
    for(int i=len-1;i>=0;i--)
    {
        printf("%s",((p&(1<<i)) ? "1" : "0"));
    }
}

long long base_k(long long p,int k,int len)
{
    long long res = 0;
    for(int i=len-1;i>=0;i--)
    {
        res *= k;
        res += ((p&(1<<i)) ? 1 : 0);
    }
    return res;
}

int main()
{
    int T,ca=1;
    scanf("%d",&T);
    while(T--)
    {
        int n,j;
        scanf("%d%d",&n,&j);
        //if( n%2 ) continue;
        printf("Case #%d:\n",(ca++));
        int len = n/2;
        for(int i=0;i<j;i++)
        {
            long long p = (1<<(len-1)) | (i<<1) | 1;
            print_2(p,len);
            print_2(p,len);
            for(int k=2;k<=10;k++)
            {
                printf(" %lld",base_k(p,k,len));
            }
            printf("\n");
        }
    }
    return 0;
}

