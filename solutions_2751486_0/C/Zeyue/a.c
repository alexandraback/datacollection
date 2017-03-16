/* prob-a */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int T, N;
char str[110];

int isLegal(int st, int ed)
{
    
    int i, maxLen = 0;
    for (i=st; i<=ed; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            maxLen = 0;
        } else {
            maxLen++;
        }
        if (maxLen >= N) {
            /* printf("\n"); */
            /* printf("%d %d\n", st, ed); */
            return 1;
        }
    }
    /* printf("\n"); */
    return 0;
}
    

int cal()
{
    int i, j, count = 0;
    for (i=0; i<=strlen(str)-N; i++) {
        for (j=N; i+j<=strlen(str); j++) {
            if (isLegal(i, i+j-1) == 1) {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    int t, ret;
    scanf("%d", &T);
    for (t=0; t<T; t++) {
        scanf("%s %d", str, &N);
        ret = cal();
        printf("Case #%d: %d\n", t+1, ret);
    }
    return 0;
}

