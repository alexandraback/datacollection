#include <cstdio>
#define FOR(i,x,y) for(int i=x;i<=y;++i)
int t,len,ans;
char s[110],ch;
int main()
{
    scanf("%d",&t);
    FOR(i,1,t)
    {
        printf("Case #%d: ",i);
        scanf("%s",s);
        len=0; ans=1;
        while(s[len]!='\0') ++len;
        while(len-1>=0&&s[len-1]=='+') --len;
        if(len==0) {printf("0\n");continue;}
        ch=s[0];
        FOR(j,1,len-1)
        {
            while(s[j]==ch&&j<len) ++j;
            if(j<len) ++ans;
            ch=s[j];
        }
        printf("%d\n",ans);
    }
    return 0;
}
