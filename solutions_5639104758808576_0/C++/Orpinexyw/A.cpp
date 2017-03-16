#include <cstdio>
#include <algorithm>

void work() 
{
    int ret = 0, k;
    char aud[1000];
    scanf("%d %s", &k, aud);
    int stand = aud[0] - '0';
    for (int i = 1; i <= k; i++) {
        if (i <= stand) {
            stand += aud[i] - '0';
        } else {
            ret += i - stand;
            stand += i - stand;
            stand += aud[i] - '0';
        }
    }
    printf("%d\n", ret);
}
int main() 
{
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        work();
    }
    return 0;
}