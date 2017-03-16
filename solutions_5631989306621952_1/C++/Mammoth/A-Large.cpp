#include "stdio.h"
#include "string.h"
main()
{
    freopen("A-large.in","r",stdin);
    freopen("1A_L.txt","w",stdout);
    int t,cs;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        char s[1010];
        int pos[1010];
        int fst,lst,i,j,ci;
        char f,l,cw;
        scanf(" %s",s);
        pos[0]=0; f=l=s[0]; lst=fst=0;
        for(i=1;i<strlen(s);i++)
        {
            if(s[i]-f<0)
            {
                pos[i]=++lst;
                l=s[i];
            }
            else
            {
                pos[i]=--fst;
                f=s[i];
            }
        }
        for(i=0;i<strlen(s);i++)
        {
            for(j=1;j<strlen(s);j++)
            {
                if(pos[j-1]>pos[j])
                {
                    ci=pos[j-1]; pos[j-1]=pos[j]; pos[j]=ci;
                    cw=s[j-1]; s[j-1]=s[j]; s[j]=cw;
                }
            }
        }
        printf("Case #%d: %s\n",cs,s);
    }
}
