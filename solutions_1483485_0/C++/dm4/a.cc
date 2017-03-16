#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    char *t1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
    char *o1 = "our language is impossible to understand";
    char *t2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
    char *o2 = "there are twenty six factorial possibilities";
    char *t3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
    char *o3 = "so it is okay if you want to just give up";
    char table[26] = {0};
    table['q'-'a'] = 'z';
    table['z'-'a'] = 'q';
    for (int i = 0; i < strlen(t1); i++) {
        if (t1[i] == ' ')
            continue;
        else
            table[t1[i]-'a'] = o1[i];
    }
    for (int i = 0; i < strlen(t2); i++) {
        if (t2[i] == ' ')
            continue;
        else
            table[t2[i]-'a'] = o2[i];
    }
    for (int i = 0; i < strlen(t3); i++) {
        if (t3[i] == ' ')
            continue;
        else
            table[t3[i]-'a'] = o3[i];
    }
    for (int i = 0; i < 26; i++) {
        printf("%d: '%c'\n", i, table[i]);
    }
    int n;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) {
        printf("Case #%d: ", i);
        while (1) {
            char c = getchar();
            if (c == '\n')
                break;
            else if (c == ' ')
                putchar(' ');
            else
                putchar(table[c-'a']);
        }
        putchar('\n');
    }
    return 0;
}
