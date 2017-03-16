#include <stdio.h>

char our[3][2][128] = {
    {"ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand"},
    {"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities"},
    {"de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up"},
};

int main()
{
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-small-attempt1.out", "w", stdout);
    char map[128] = { 0 }, str[128] = { 0 };
    int i = 0, j = 0, c = 0, o = 0;
    bool u[128] = { 0 };
    
    map['q'] = 'z';
    map['z'] = 'q';

    for (i = 0; i < 3; i ++) {
        for (j = 0; our[i][0][j]; j ++) {
            map[our[i][0][j]] = our[i][1][j];
        }
    }

    /*
    for (i = 'a'; i <= 'z'; i ++) {
        if (map[i]) {
            u[map[i]] = true;
            printf("%c %c\n", i, map[i]);
        }
        else {
            for (j = 'a'; j <= 'z'; j ++) {
                if (!u[j]) {
                    break;
                }
            }
            if (j <= 'z') {
                u[j] = true;
                map[i] = j;
                printf("%c %c\n", i, map[i]);
            }
            else {
                printf("##########\n");
            }
        }
    }
    */
    
    
    scanf("%d", &c);
    gets(str);
    for (o = 1; o <= c; o ++) {
        gets(str);
        for (i = 0; str[i]; i ++) {
            str[i] = map[str[i]];
        }
        printf("Case #%d: %s\n", o, str);
    }

    return 0;
}

