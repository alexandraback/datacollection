#include <iostream>
#include <string.h>
#include <stdio.h>
char str[26]= {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
using namespace std;
int main()
{
    char ans[1500];
    int n;
    scanf("%d\n",&n);
    for(int i=0; i<n; ++i)
    {
        gets(ans);
        for(int j=0; ans[j]; ++j)
        {
            if(ans[j] >= 'a' && ans[j] <= 'z')
                ans[j] = str[ans[j] - 'a'];
        }
        printf("Case #%d: %s\n", i+1, ans);
    }
    return 0;
}
