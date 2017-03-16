#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main() {
    freopen("B-large.in.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testcases;
    scanf("%d", &testcases);
    for (int id = 1; id<= testcases; id++) {
        char s[200];
        scanf("%s", s);
        int dpos = -1;
        int lens = strlen(s);
        for (int i = lens - 1; i >= 0; i--) {
            if (s[i] == '-') {
                dpos = i;
                break;
            }
        }
        int ans = 0;
        if (dpos != -1) {
            ans = 1;
        }
        for (int i = dpos - 1; i >= 0; i--) {
            if (s[i] != s[i + 1]) {
                ans++;
            }
        }
        printf("Case #%d: %d\n", id, ans);
    }
    return 0;
}