#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

char s[1010];

int main()
{
    int T,ca=1;
    scanf("%d\n",&T);
    while(T--)
    {
        scanf("%s",s);
        printf("Case #%d: ",(ca++));
        int len = strlen(s);
        string s2 = "";
        s2 += s[0];
        for(int i=1;i<len;i++)
        {
            if( s[i] >= s2[0] )
                s2 = s[i] + s2;
            else
                s2 = s2 + s[i];
        }
        printf("%s\n",s2.c_str());
    }
    return 0;
}

