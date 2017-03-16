#include <stdio.h>
#include <string.h>

int answers[2][101];

int dp(int sign, int len) {
    if (len == 1) {
        // if sign == 0 ('+') we're done, otherwise we need 1 flip.
        return sign;
    } else if (answers[sign][len] != -1) {
        return answers[sign][len];
    }

    if (len % 2 == 1) {
        // If odd number - i.e. +-+ or -+-,
        // We can either flip an odd prefix, which will give us other sign
        // and len - 1 or we can flip the whole thing which gives other sign
        // and len.
        int a = 1 + dp(1 - sign, len - 1);
        int b = 2 + dp(sign, len - 1);

        answers[sign][len] = a < b ? a : b;
    } else {
        answers[sign][len] = 1 + dp(1 - sign, len - 1);
    }
    return answers[sign][len];
}

int count(char *str) {
    int len = strlen(str);
    int ans = 1;
    for (int i = 1; i < len; ++i) {
        if (str[i] != str[i - 1]) {
            ++ans;
        }
    }
    return ans;
}

int solve() {
    memset(answers, -1, sizeof(answers));
    char input[101];
    scanf("%s", input);

    return dp(input[0] == '+' ? 0 : 1, count(input));
}

int main(void) {
    int nC;
    scanf("%d", &nC);

    for (int cC = 1; cC <= nC; ++cC) {
        printf("Case #%d: %d\n", cC, solve());
    }
}