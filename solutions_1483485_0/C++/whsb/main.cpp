#include <iostream>
#include <string.h>
#include <stdio.h>

char Table[26]= {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

using namespace std;
int main()
{
    //freopen("A-small-attempt0.in","r",stdin);
    //freopen("out","w",stdout);
    char Str[1500];
    int n;
    scanf("%d\n",&n);
    for(int Case=0; Case<n; ++Case)
    {
        gets(Str);
        for(int j=0; Str[j]; ++j)
        {
            if(Str[j] >= 'a' && Str[j] <= 'z')
                Str[j] = Table[Str[j] - 'a'];
        }
        printf("Case #%d: %s\n", Case+1, Str);
    }
    return 0;
}
