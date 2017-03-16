#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool vis[10];

bool ok() {
    for(int i = 0;i < 10;i++) {
        if(vis[i] != 1) return 0;
    }
    return 1;
}

void work(int num) {
    while(num >= 10) {
        vis[num % 10] = 1;
        num /= 10;
    }
    vis[num] = 1;
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int t, n, i, tmp, cas = 1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        if(n == 0) {
            printf("Case #%d: INSOMNIA\n", cas++);
            continue;
        }
        memset(vis, 0, sizeof(vis));
        for(i = 1;!ok();i++) {
            tmp = n * i;
            work(tmp);
        }
        printf("Case #%d: %d\n", cas++, tmp);
    }
    return 0;
}
