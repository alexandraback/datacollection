#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

int ct, ans[1111111];
bool v[10];

bool numset(int x) {
    while (x) {
        int tmp = x % 10;
        if (!v[tmp]) ct--;
        v[tmp] = true;
        x /= 10;
    }
    return ct == 0;
}

int main() {
    for (int i = 1; i <= 1000000; ++i) {
        //printf("%d\n", i);
        memset(v, 0, sizeof(v));
        ct = 10;
        for (int j = 1; j <= 100; ++j) {
            ans[i] = i*j;
            if (numset(i*j)) break;
        }
    }
    for (int i = 0; i <= 1000000; ++i) {
        if (ans[i] == 0) {
            printf("%d\n", i);
        }
    }
    int TC;
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; ++tc) {
        cerr << tc << endl;
        int x;
        scanf("%d", &x);
        printf("Case #%d: ", tc);
        if (ans[x] == 0) printf("INSOMNIA\n");
        else printf("%d\n", ans[x]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
    