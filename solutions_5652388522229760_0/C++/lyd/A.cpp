#include<stdio.h>
#include<string.h>

int getSleep(int n)
{
    if( n == 0 ) return -1;
    int num = 0;
    int bFound[10];
    memset(bFound,0,sizeof(bFound));
    int res = 0;
    while( num < 10 )
    {
        res += n;
        int p = res;
        while(p)
        {
            if( !bFound[p%10] )
            {
                bFound[p%10] = 1;
                num++;
            }
            p/=10;
        }
    }
    return res;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int p = 0;
        scanf("%d",&p);
        int res = getSleep(p);
        if( res < 0 ) 
            printf("Case #%d: INSOMNIA\n",i+1);
        else
            printf("Case #%d: %d\n",i+1,res);
    }
    return 0;
}

