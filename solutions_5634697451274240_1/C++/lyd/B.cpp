#include <stdio.h>
#include <string.h>

char s[1010];

int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        int cnt = 0;
        int len=strlen(s);
        for(int j=0;j<len-1;j++)
        {
            if( s[j] != s[j+1] ) cnt++;
        }
        if( s[len-1] == '-' ) cnt++;
        printf("Case #%d: %d\n",i,cnt);
    }
    return 0;
}

