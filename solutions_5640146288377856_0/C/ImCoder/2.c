#include<stdio.h>
int main()
{
    int t,n,r,c,w,i,j;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&t);
    for(j=1;j<t+1;j++)
    {
        scanf("%d%d%d",&r,&c,&w);
        n=w+(c/w)*r;
        if(c%w==0)
            n=n-1;
        printf("Case #%d: %d\n",j,n);
    }
    return 0;
}
