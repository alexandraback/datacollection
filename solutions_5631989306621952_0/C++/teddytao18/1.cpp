#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1010];
char ans[2010];

int main()
{
    int i,l,t,start,end,T;
    scanf("%d",&T);
    for (t=1;t<=T;t++)
    {
        printf("Case #%d: ",t);
        scanf("%s",s);
        l=strlen(s);
        start=1000; end=1001;
        ans[start]=s[0];
        for (i=1;i<l;i++)
        {
            if (ans[start]>s[i])
                ans[end++]=s[i];
            else ans[--start]=s[i];
        }
        ans[end]=0;
        printf("%s\n",ans+start);
    }
}
