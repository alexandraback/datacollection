#include <stdio.h>

const int N = 101;
char A[][N] = {"our language is impossible to understand", 
    "there are twenty six factorial possibilities",
    "so it is okay if you want to just give up"};
char B[][N] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
    "de kr kd eoya kw aej tysr re ujdr lkgc jv"};

char mp[26];
char tgb[26];

int main() {
    mp['q'-'a'] = 'z';
    tgb['z'-'a'] = 1;
    for (int i = 0;i < 3;i++) {
        for (int j = 0;A[i][j];j++) {
            mp[B[i][j]-'a'] = A[i][j];
            tgb[A[i][j]-'a'] = 1;
        }
    }
    int lefta = 0;
    int leftb = 0;
    for (int i = 0;i < 26;i++) {
        if (mp[i] == 0) lefta = i;
        if (tgb[i] == 0) leftb = i;
    }
    mp[lefta] = 'a' + leftb;
    int cas;
    scanf("%d", &cas);
    getchar();
    for (int ic = 1;ic <= cas;ic++) {
        char line[N];
        gets(line);
        for (int i = 0;line[i];i++) {
            if (line[i] >= 'a' && line[i] <= 'z') line[i] = mp[line[i]-'a'];
        }
        printf("Case #%d: %s\n", ic, line);
    }
    return 0;
}
