#include <bits/stdc++.h>
using namespace std;

const int MAX = 123;
bool s[MAX], tmp[MAX];
int S, flips;

void dump() {
    for (int j = 0; j < S; j++)
        printf("%c", s[j] ? '+' : '-');
    puts("");
}

void flip(int i) {
    flips++;
    for (int j = 0; j <= i; j++)
        tmp[j] = s[j];
    for (int j = 0; j <= i; j++)
        s[j] = !tmp[i - j];
}

int main() {
    int cases;
    scanf("%d", &cases);
    for (int cs = 1; cs <= cases; cs++) {
        char stack[MAX];
        scanf("%s", stack);
        S = int(strlen(stack));
        for (int i = 0; i < S; i++)
            s[i] = stack[i] == '+';

        flips = 0;
        for (int p = S-1; p >= 0; p--)
            if (!s[p]) {
                int start = 0;
                while (s[start])
                    start++;
                if (start)
                    flip(start-1);
                flip(p);
            }

        printf("Case #%d: %d\n", cs, flips);
    }
}
