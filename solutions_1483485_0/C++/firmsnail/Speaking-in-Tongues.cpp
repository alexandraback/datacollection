#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const char Tr[27] = 
{'y','h','e','s','o',
 'c','v','x','d','u',
 'i','g','l','b','k',
 'r','z','t','n','w',
 'j','p','f','m','a','q'};
char s[105];
int l; 
int main()
{
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-small-attempt1.out", "w", stdout);
    int cases;
    scanf("%d", &cases);
    gets(s);
    for (int i = 1; i <= cases; ++i)
    {
        gets(s);
        l = strlen(s);
        printf("Case #%d: ", i);
        for (int j = 0; j < l; ++j)
            if(s[j] == ' ') putchar(s[j]);
            else putchar(Tr[s[j]-'a']);
        printf("\n");
    }
    //while (1);
    return 0;
}
