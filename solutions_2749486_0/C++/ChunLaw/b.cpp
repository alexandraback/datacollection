#include <cstdio>
#include <cstring>

int main() {
    char s[555];
    int x, y, t;
    scanf("%d", &t);
    for (int k = 1; k <= t; k++) {
        scanf("%d%d", &x, &y);
        memset(s, 0, sizeof s);
        for (int i = 0; i < x; i++) strcat(s, "WE");
        for (int i = 0; i < -x; i++) strcat(s, "EW");
        for (int i = 0; i < y; i++) strcat(s, "SN");
        for (int i = 0; i < -y; i++) strcat(s, "NS");
        printf("Case #%d: %s\n", k, s);
    }
    return 0;
}
