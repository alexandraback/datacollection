#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

bool isvowel[256];
std::string S;
int n;

int main() {
    memset(isvowel, 0, sizeof(isvowel));
    for (int i = 0; i < 5; i ++)
        isvowel["aeiou"[i]] = true;

    int T;
    std::cin >> T;
    for (int ct = 1; ct <= T; ct ++) {
        std::cin >> S >> n;
        int cnt = 0, limit = -1;
        long long ans = 0;
        for (int i = 0; i < S.size(); i ++) {
            if (!isvowel[S[i]]) cnt ++; else cnt = 0;
            if (cnt >= n) limit = i - n + 1;
            if (limit > -1) ans += (limit + 1);
        }
        printf("Case #%d: %lld\n", ct, ans);
    }
}
