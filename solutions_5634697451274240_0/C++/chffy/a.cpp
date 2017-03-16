#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;

char str[105];

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str + 1);
        int n = strlen(str + 1);
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int j = i;
            while (j + 1 <= n && str[j + 1] == str[i])
                ++j;
            ++ans;
            i = j;
        }
        if (str[n] == '+') --ans;
        static int ca = 0;
        printf("Case #%d: %d\n", ++ca, ans);
    }
}
