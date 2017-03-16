#include <cstdio>

char trans[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
int main() {

 //   freopen("A.in", "r", stdin);
    int case_num;
    static char str[1000];
    scanf("%d\n", &case_num);
    for (int i = 0; i < case_num; i++)
    {
        fgets(str, sizeof str, stdin);
        printf("Case #%d: ", i + 1);
        for (char *p = str; *p != '\n'; p++)
            if (*p == ' ') putchar(' ');
            else putchar(trans[*p - 'a']);
        puts("");
    }
}
