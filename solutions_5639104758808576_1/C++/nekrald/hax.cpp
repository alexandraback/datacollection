#include <bits/stdc++.h>
using namespace std;

const int SZ = 1111;

int T, len;
char s[SZ];

int main() {
    scanf("%d", &T);
    for (int _ = 1; _ <= T; ++_) {
        memset(s, 0, sizeof(s));
        printf("Case #%d: ", _);
        scanf("%d", &len);
        scanf("%s", s);
        int have = 0, need = 0;
        for (int i = 0; i <= len; ++i) {
            int posct = s[i] - '0';
            int shyness = i;
            if (have >= i) {
            } else {
                int diff = i - have;
                need += diff;
                have += diff;
            }
            have += posct;
        }
        printf("%d\n", need);
    }

    return 0;
}
