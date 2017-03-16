#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int T,t;
    scanf("%d",&T);
    for(t=1;t<=T;t++) {
        int r,c,w;
        scanf("%d %d %d",&r,&c,&w);
        int ans = (r-1)*(c/w) + (c-w)/w;
        if(c%w==0) ans += w;
        else ans+= w+1;
        printf("Case #%d: %d\n",t,ans);
    }
}
