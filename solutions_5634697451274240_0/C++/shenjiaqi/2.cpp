#include <cstdio>
#include <iostream>
using namespace std;

const int N = 107;
int ans[N];
int dfsAns(int len) {
    if (len == 0)
        return 0;
    if (len == 1)
        return 1;
    if (len == 2)
        return 2;
    if (ans[len] == 0) {
        ans[len] = 1 + dfsAns(len - 1);
    }
    return ans[len];
}

int main() {
    int t;
    scanf("%d", &t);
    char s[N];
    for (int i = 1; i <= t; ++i) {
        scanf("%s", s);
        int l = strlen(s) - 1;
        while (l >= 0 && s[l] == '+') {
            --l;
        }
        if (l < 0) {
            printf("Case #%d: 0", i);
        } else {
            int len = 0;
            while (l >= 0) {
                for (char c = s[l]; l >= 0 && c == s[l]; --l)
                ;
                ++len;
            }
            printf("Case #%d: %d", i, dfsAns(len));
        }
        if (i + 1 <= t)
            printf("\n");
    }
    return 0;
}
