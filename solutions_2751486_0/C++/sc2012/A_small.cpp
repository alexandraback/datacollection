#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

char name[1001000];

int check(int i ,int j, int n){
    int pre = i-1, k;
    for (k = i; k <= j; ++k) {
        if (name[k] == 'a' || name[k] == 'o' || name[k] == 'i' || name[k] == 'u' || name[k] == 'e') {
            int t = k - pre - 1;
            if (t >= n)
                return 1;
            pre = k;
        }
    }
    if (k > pre) {
        int t = k - pre -1 ;
        if (t >= n) return 1;
    }
    return 0;
}

int main() {
    int T, c;
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    for (c = 1; c <= T; ++c) {
        int i, n;
        scanf("%s%d", name, &n);
        int l = strlen(name), pre = -1;
        long long ans = 0;
        for (i = 0; i < l; ++i) {
            for (int j = 0; j <= i; ++j)
            {
                ans += check(j,i, n);
            }
        }
        printf("Case #%d: %lld\n", c, ans);
    }
    return 0;
}

