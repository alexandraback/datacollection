#include <stdio.h>
#include <string.h>

    int test;
int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    scanf("%d", &test);
    char s[100];
    gets(s);
    for (int t = 1; t <= test; t++) {
        printf("Case #%d: ", t);
        gets(s);
        int ans = 0, rev_time = 0;
        for (int i = 0; i < strlen(s); i++) {
            if (((s[strlen(s) - 1- i] == '-') && ((rev_time & 1) == 0)) ||
                ((s[strlen(s) - 1- i] == '+') && ((rev_time & 1) == 1))) { ans++; rev_time++; }
        }
        printf("%d\n", ans);
    }
    return 0;
}
