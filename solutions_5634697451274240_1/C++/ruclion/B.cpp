#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100 + 10;

char s[maxn];
int n;
int ans;

void solve(int l, int r, int flag) {
    if(l > r) {
        return;
    }
    if((flag == 0 && s[r] == '+') || (flag == 1 && s[r] == '-')) {
        solve(l, r - 1, flag);
    }
    else {
        ans++;
        solve(l, r - 1, 1 - flag);
    }
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("Bout.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        scanf("%s", s);
        int len = strlen(s);
        ans = 0;
        solve(0, len - 1, 0);
        printf("%d\n", ans);
    }
    return 0;
}
