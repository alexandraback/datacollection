#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdint.h>
#include <algorithm>

using namespace std;
const int N = 1000010;

char str[N];
char pat[N];
int fr[N], bk[N], top;

inline bool vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int nxt[N];

void kmp(int slen, int plen) {
    top = 0;
    int j = 0;
    for (int i = 0; i < slen; i++) {
        if (str[i] == '0') {
            j = 0;
        } else {
            j++;
            if (j >= plen) {
                fr[top] = i - plen + 1;
                bk[top] = i;
                top++;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        printf("Case #%d: ", cas);
        int n;
        scanf("%s %d", str, &n);
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            if (vowel(str[i])) str[i] = '0';
            else str[i] = '1';
        }
        memset(pat, '1', n);
        pat[n] = 0;
        kmp(len, n);
        uint64_t ans = 0;
        for (int i = 0; i < top; i++) {
            if (i == 0) {
                ans += uint64_t(fr[0] + 1) * (len - bk[0]);
                continue;
            }
            ans += uint64_t(fr[i]-fr[i-1]) * (len - bk[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
