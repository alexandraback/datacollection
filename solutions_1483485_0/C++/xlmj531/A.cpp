#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 128;
const int m = 26;

const int trans[m] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
char s1[maxn], s2[maxn];
int cas;

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&cas);
    gets(s1);
    for (int run = 1; run<=cas; run++ )
    {
        gets(s1);
        printf("Case #%d: ",run);
        for (int i = 0; s1[i]; i++ )
            if (s1[i]!=' ') printf("%c",trans[s1[i]-'a']);
            else printf(" ");
        printf("\n");
    }
    return 0;
}
