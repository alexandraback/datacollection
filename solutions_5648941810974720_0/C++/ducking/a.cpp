#include <stdio.h>

const int MAX = 2010;

char s[MAX];
int cnt[26];
int use[10][26];
char dig[][10] = {
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};
int res[10];
void minus(int n) {
    for (int i=0; dig[n][i]; i++)
        cnt[dig[n][i]-'A']--;
    res[n]++;
}
void add_res(int n, int by) {
    while (cnt[by]>0)
        minus(n);
}
int main() {
    int t;
    scanf("%d", &t);
    for (int c=1; c<=t; c++) {
        for (int i=0; i<10; i++)
            res[i] = 0;
        scanf("%s", s);
        for (int i=0; s[i]; i++)
            cnt[s[i]-'A']++;
        add_res(0, 'z'-'a');
        add_res(4, 'u'-'a');
        add_res(3, 'r'-'a');
        add_res(6, 'x'-'a');
        add_res(7, 's'-'a');
        add_res(2, 'w'-'a');
        add_res(1, 'o'-'a');
        add_res(5, 'v'-'a');
        add_res(8, 'T'-'A');
        add_res(9, 'I'-'A');
        printf("Case #%d: ", c);
        for (int i=0; i<10; i++)
            while (res[i]>0) {
                printf("%d", i);
                res[i]--;
            }
        puts("");
    }
}
