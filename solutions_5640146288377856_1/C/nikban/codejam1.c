#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,r,c,w,i,j,ans;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
        {
        ans=0;
        scanf("%d%d%d",&r,&c,&w);
            ans=(r-1)*(c/w);
        ans=ans+c/w+w-1;
        if(c%w!=0)
        	ans=ans+1;
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}

