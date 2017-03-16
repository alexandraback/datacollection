#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int s[26];

void deal(int n, string t[], int s[], int num[], char c) {
    num[n] = s[c - 'A'];
    for (int i = 0; i < num[n]; i++) {
        for (int j = 0; j < t[n].length(); j++) {
            s[t[n][j] - 'A']--;
        }
    }
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int test;
    scanf("%d", &test);
    string table[10];
    table[0] = "ZERO";
    table[1] = "ONE";
    table[2] = "TWO";
    table[3] = "THREE";
    table[4] = "FOUR";
    table[5] = "FIVE";
    table[6] = "SIX";
    table[7] = "SEVEN";
    table[8] = "EIGHT";
    table[9] = "NINE";
    for (int t = 1; t <= test; t++) {
        char str[3000];
        int num[10];
        scanf("%s", str);
        memset(s, 0, sizeof(s));
        memset(num, 0, sizeof(num));
        for (int i = 0; i < strlen(str); i++) {
            s[str[i] - 'A']++;
        }
        deal(0, table, s, num, 'Z');
        deal(8, table, s, num, 'G');
        deal(4, table, s, num, 'U');
        deal(2, table, s, num, 'W');
        deal(6, table, s, num, 'X');
        deal(1, table, s, num, 'O');
        deal(3, table, s, num, 'R');
        deal(5, table, s, num, 'F');
        deal(7, table, s, num, 'S');
        deal(9, table, s, num, 'I');
        printf("Case #%d: ", t);
        for (int i = 0; i < 10; i++) for (int j = 0; j < num[i]; j++) { printf("%d", i); }
        printf("\n");
    }
    return 0;
}
