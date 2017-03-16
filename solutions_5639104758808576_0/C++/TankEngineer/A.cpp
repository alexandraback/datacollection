#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int L = 1005;

int n;

char s[L];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%s", &n, s);
        int ans = 0, cur = 0;
        for (int i = 0; i <= n; ++i) {
            int d = s[i] - '0';
            if (cur >= i) {
                cur += d;
            } else {
                ans += i - cur;
                cur = i;
                cur += d;
            }
        }
        static int id = 0;
        printf("Case #%d: %d\n", ++id, ans);
    }
    return 0;
}
