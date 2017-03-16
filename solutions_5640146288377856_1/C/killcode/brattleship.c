#include<stdio.h>
int main()
{
    int t,r,c,w,i=1,p;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&r,&c,&w);
        p=w+(c/w)*r;
        if(c%w==0)
            p=p-1;
        printf("Case #%d: %d\n",i,p);
        i++;
    }
    return 0;
}
