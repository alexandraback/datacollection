#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    int r,c,w;
    int cases;
    scanf("%d",&t);
    cases=0;
    while(t--)
    {
        cases++;
        scanf("%d%d%d",&r,&c,&w);
        printf("Case #%d: %d\n",cases,c/w+(c%w==0?0:1)+w-1);
    }
    return 0;
}
