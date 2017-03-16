#include<cstdio>
#include<cstring>

char p[30] = {"yhesocvxduiglbkrztnwjpfmaq"};

int main()
{
    int T,l,c,d;
    char s[105];
    scanf("%d",&T);
    gets(s);
    for(c=1;c<=T;c++)
    {
        gets(s);
        l = strlen(s);
        printf("Case #%d: ",c);
        for(d=0;d<l;d++)
        {
            if('a'<=s[d] && s[d]<='z') printf("%c",p[s[d]-'a']);
            else printf("%c",s[d]);
        }
        printf("\n");
    }
    return 0;
}
