#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[1000005];
int main()
{
    int c,T,n,i,len,l,cnt,pre;
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&T);
    for(c=1;c<=T;c++)
    {
        printf("Case #%d: ",c);
        scanf("%s%d",str,&n);
        len=strlen(str);
        l=cnt=0;
        pre=-1;
        for(i=0;i<len;i++)
        {
            if(str[i]!='a'&&str[i]!='e'&&str[i]!='i'&&str[i]!='o'&&str[i]!='u')
            {
                l++;
                if(l==n) pre=i-n+1;
                if(l>n) pre++;
            }
            else l=0;
            if(pre>=0) cnt+=pre+1;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
