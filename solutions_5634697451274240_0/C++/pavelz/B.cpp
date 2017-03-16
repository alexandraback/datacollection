//
// https://code.google.com/codejam/contest/6254486/dashboard#s=p1

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

#define BLANK '-'
#define HAPPY '+'

int getBlank(char *data, int l) {
    for(int i=l-1;i>=0;i--) if (data[i] == BLANK) return i;
    return -1;
}

char other(char c) {
    return c == HAPPY ? BLANK : HAPPY;
}

void rev(char *data, int last) {
    int first = 0;
    while (first < last) {
        char temp = data[first];
        data[first] = other(data[last]);
        data[last] = other(temp);
        first++;
        last--;
    }
    if (first == last) data[first] = other(data[first]);
}


int main(void) {
    int cases;
    scanf("%d", &cases);
    for(int c=1;c<=cases;c++) {
        char s[200];
        scanf("%s", s);
        int l = strlen(s);
        int total = 0;
        int blankIndex;
        while ((blankIndex = getBlank(s, l)) >= 0) {
            int start = 0;
            while (s[start] == HAPPY) start++;
            if (start > 0) {
                total++;
                FOR(i, start) s[i] = BLANK;
            }
            rev(s, blankIndex);
            total++;
        }
        printf("Case #%d: %d\n", c, total);
    }
}
