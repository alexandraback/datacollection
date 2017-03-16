#include <cstdio>
#include <cstring>
int mp_char[] = {24, 7, 4, 18, 14, 2, 21, 23, 3, 20, 8, 6, 11, 1, 10, 17, 25, 19, 13, 22, 9, 15, 5, 12, 0, 16};

int main() {
    freopen("in4", "r", stdin);
    freopen("out4", "w", stdout);
    int T;
    scanf("%d", &T);
    getchar();
    int cas=1;
    char str[150] = {0};
    while (T--) {
        gets(str);
        for (int i = 0, l = strlen(str); i < l; i++) {
            if (str[i] != ' ')
                str[i] = mp_char[str[i] - 'a'] + 'a';
        }
        printf("Case #%d: ",cas++);
        puts(str);
    }

}