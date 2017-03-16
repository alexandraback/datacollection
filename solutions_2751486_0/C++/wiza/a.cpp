#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
const int N = 110;

char str[N];

inline bool vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool check(int a, int b, int k) {
    int cnt = 0, ret = 0;
    for (int i = a; i <= b; i++) {
        if (vowel(str[i])) cnt = 0;
        else ret = max(++cnt, ret);

        if (ret >= k) return true;
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        printf("Case #%d: ", cas);
        int n;
        scanf("%s %d", str, &n);
        int len = strlen(str);
        int ans = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                if (check(i, j, n)) ++ans;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
