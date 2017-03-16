#include<stdio.h>
#include<string.h>
char c[30]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
char s[105];
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        gets(s);
        printf("Case #%d: ",++cas);
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            if(s[i]>='a'&&s[i]<='z')
                printf("%c",c[s[i]-'a']);
            else
                printf("%c",s[i]);
        }
        puts("");
    }
    return 0;
}
