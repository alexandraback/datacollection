#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>

const int N=31;

using namespace std;

char Hash[N]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

char s[N*N];

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out","w",stdout);
    int ca,t=0;
    for(scanf("%d\n",&ca);ca--;)
    {
        printf("Case #%d: ",++t);
        gets(s);
        for(int i=0;s[i];i++)
        {
            if(s[i]<='z' && s[i]>='a') printf("%c",Hash[s[i]-'a']);
            else printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}
