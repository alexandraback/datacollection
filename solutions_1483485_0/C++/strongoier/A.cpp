#include <cstdio>

char s[] = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
    int t;
    scanf("%d%*c", &t);
    for (int k = 1; k <= t; ++ k)
    {
        printf("Case #%d: ", k);
        char c;
        while ((c = getchar()) != '\n')
            putchar(c == ' ' ? ' ' : s[c - 'a']);
        putchar('\n');
    }
    return 0;
}
