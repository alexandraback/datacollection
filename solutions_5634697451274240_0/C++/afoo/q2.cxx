#include <stdio.h>
#include <string.h>

int main()
{
    int T;
    
    scanf("%d", &T);
    char line[200];
    for (int Ti=1;Ti<=T;Ti++) {
        printf("Case #%d: ", Ti);
        scanf("%s\n",line);
        int ans =0;
        int len = strlen(line); 
        char c = '+';
        for (int i=len-1;i>=0;i--) {
            if (line[i]!=c) {
                c = line[i];
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}


