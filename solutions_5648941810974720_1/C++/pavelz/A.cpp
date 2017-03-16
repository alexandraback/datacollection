// Description
// https://code.google.com/codejam/contest/11254486/dashboard

#include <bits/stdc++.h>
using namespace std;

#define FOR(c, m) for(int c=0;c<(int)(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)
#define LLI long long int
#define MOD 1000000007

int power(int a, int b) {
    int sq = a;
    int result = 1;
    while (b > 0) {
        if ((b & 1) == 1) result = result * (LLI)sq % MOD;
        sq = sq * (LLI)sq % MOD;
        b >>= 1;
    }
    return result;
}

int inv(int a) {
    return power(a, MOD - 2);
}

void fail() {
    *((char *)0) = 0;
}


#define MAX_S 3000
char data[MAX_S];
char counts[30];
int dc[10];
const char *words[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char result[MAX_S];

void sub(int w, int c) {
    int l = strlen(words[w]);
    FOR(i, l) counts[words[w][i] - 'A'] -= c;
}

void calc(int w, char c) {
    dc[w] = counts[c - 'A'];
    sub(w, dc[w]);
}

int main(void) {
    int cases;
    scanf("%d", &cases);
    for(int cc=1;cc<=cases;cc++) {
        scanf("%s", data);
        int l = strlen(data);
        FOR(i, 26) counts[i] = 0;
        FOR(i, l) counts[data[i] - 'A']++;
        calc(6, 'X');
        calc(0, 'Z');
        calc(2, 'W');
        calc(4, 'U');
        calc(5, 'F');
        calc(1, 'O');
        calc(3, 'R');
        calc(8, 'G');
        calc(7, 'S');
        calc(9, 'I');
        int resPos = 0;
        FOR(i, 10) {
            FOR(j, dc[i]) result[resPos++] = '0' + i;
        }
        result[resPos] = 0;

        printf("Case #%d: %s\n", cc, result);
    }
}
