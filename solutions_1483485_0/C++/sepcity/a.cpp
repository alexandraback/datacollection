#include<iostream>

using namespace std;
char *mp="yhesocvxduiglbkrztnwjpfmaq";
char s[110];
int main()
{
    int cases;
    freopen("A-small-attempt1(1).in", "r", stdin);
    freopen("A-small-attempt1(1).out", "w", stdout);
    scanf("%d",&cases);
    gets(s);
    for(int ca=1;ca<=cases;ca++)
    {
        gets(s);
        int len=strlen(s);
        printf("Case #%d: ",ca);
        for(int i=0;i<len;i++)
        {
            if(s[i]==' ') printf(" ");
            else
            printf("%c",mp[s[i]-'a']);
        }
        puts("");
    }
}
