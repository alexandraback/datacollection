#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca)
    {
        char line[200];
        scanf("%s", line);
        int len = strlen(line);
        line[len] = '+';
        line[++len] = 0; // For protection
        int ans = 0;
        for(int i = 1; i < len; ++i)
        {
            if(line[i] != line[i-1])
                ++ans;
        }
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}
