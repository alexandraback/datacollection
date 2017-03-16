#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
char s[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
char str[1000];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cas;
    int i;
    int ca;
    scanf("%d",&cas);
    gets(str);
    for(ca=1;ca<=cas;ca++)
    {
        gets(str);
        i=0;
        printf("Case #%d: ",ca);
        while(str[i])
        {
            if(str[i]==' ') printf(" ");
            else printf("%c",s[str[i]-'a']);
            i++;
        }
        printf("\n");
    }
    return 0;
}
