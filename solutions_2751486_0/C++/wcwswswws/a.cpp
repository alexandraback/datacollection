#include<string.h>
#include<stdio.h>
char s[1000000];
int n,tt,L;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        scanf("%s%d",s,&n);L=strlen(s);
        long long ans=0;
        int l=0,c=0;
        for (int i=0;i<L;i++)
        if ((s[i]=='a')||(s[i]=='e')||(s[i]=='i')||(s[i]=='o')||(s[i]=='u'))
        {
            c=0;
        } else
        {
            c++;
            if (c>n) c--;
            if (c==n)
            {
                long long x=0,y=0;
                x=i-c+2-l;
                y=L-i;
                ans+=x*y;
                l=i-c+2;
            }
        }
        printf("Case #%d: %I64d\n",t,ans);
    }
    return 0;
}
