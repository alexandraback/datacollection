#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check(char str[],int s,int e,int n)
{
    int i,l=0;
    for(i=s;i<=e;i++)
    {
        if(str[i]!='a'&&str[i]!='e'&&str[i]!='i'&&str[i]!='o'&&str[i]!='u') l++;
        else l=0;
        if(l==n) return 1;
    }
    return 0;
}
int main()
{
    int c,T,i,j,n,len,cnt;
    char name[105];
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    scanf("%d",&T);
    for(c=1;c<=T;c++)
    {
        printf("Case #%d: ",c);
        scanf("%s%d",name,&n);
        cnt=0;
        len=strlen(name);
        for(i=0;i<len-n+1;i++)
        {
            for(j=i+n-1;j<len;j++)
            {
                if(check(name,i,j,n)) cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
