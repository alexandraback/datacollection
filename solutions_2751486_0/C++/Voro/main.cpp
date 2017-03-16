#include <cstdio>

const int kMaxN = 1000005;

char s[kMaxN];

int L;

inline bool isLetter(char ch) {
    return ('a' <= ch && ch <= 'z');
}

inline bool isVowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch =='u');
}

inline bool isConsonant(char ch) {
    return (!isVowel(ch));
}

long long solve() {
    long long res = 0;
    int ans = 0, last = -1;

    for (int i = 0; isLetter(s[i]); ++i) {
        if (isConsonant(s[i]))
            ++ans;
        else
            ans = 0;

        if (ans >= L)
            last = i - L + 1;

        if (last != -1)
            res += last + 1;
    }

    return res;
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int T;
    scanf("%d\n", &T);

    for (int i = 1; i <= T; ++i) {
        scanf("%s%d", s, &L);

        printf("Case #%d: %lld\n", i, solve());
    }

    return 0;
}
