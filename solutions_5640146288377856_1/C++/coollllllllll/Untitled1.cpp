#include<stdio.h>
#include<stdlib.h>
main()
{
    int ttt;
    scanf("%d",&ttt);
    for(int tttt=0;tttt<ttt;tttt++)
    {
        int c,r,w;
        scanf("%d %d %d",&r,&c,&w);
        unsigned long long cnt=0;
        for(int i=0;i<r;i++)
        {
            cnt+=c/w;
        }
        if(c%w==0)cnt+=(w-1);
        else cnt+=w;
        printf("Case #%d: ",tttt+1);
        printf("%llu\n",cnt);
    }
}
