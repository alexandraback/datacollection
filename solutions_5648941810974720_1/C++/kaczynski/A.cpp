#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

int T, cnt[30], ans[30], a[] = {0, 2, 6, 8, 3, 4, 5, 7, 1, 9};
char str[5000], c[] = {'Z', 'W', 'X', 'G', 'H', 'R', 'F', 'S', 'O', 'I'};
string s[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%s", str);
        int n = strlen(str);
        for (int i = 0; i < 26; i++) {
            cnt[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            cnt[str[i] - 'A']++;
        }
        for (int i = 0; i < 10; i++) {
            char l = c[i];
            ans[a[i]] = cnt[l - 'A'];
            for (int j = 0; j < s[a[i]].size(); j++) {
                int p = s[a[i]][j] - 'A';
                assert(cnt[p] >= ans[a[i]]);
                cnt[p] -= ans[a[i]];
            }
        }
        printf("Case #%d: ", t);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < ans[i]; j++) {
                printf("%c", (char) ('0' + i));
            }
        }
        puts("");
    }

    return 0;

}
