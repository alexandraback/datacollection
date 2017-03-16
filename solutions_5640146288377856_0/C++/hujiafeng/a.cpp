#include<iostream>
#include<stdio.h>
#include<assert.h>
using namespace std;


int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T;
    scanf("%d",&T);
    int r,c,w;

    for(int cas=0;cas<T;cas++)
    {
        scanf("%d %d %d",&r,&c,&w);

        int ans=0;
        if(c%w==0)
        {
            ans=c/w+(w-1);

        }else
        {
            ans=c/w+w;

        }
        printf("Case #%d: %d\n",cas+1,ans);

    }
    return 0;
}
