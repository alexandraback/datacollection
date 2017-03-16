#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define maxn 100000005
int num[32], cnt, n, j, flag, res[15], prim[10000000], np;
bool fg[maxn] = {0};

void init() {
    np = 0;
    for(int i = 2;i < maxn;i++) {
        if(fg[i]) continue;
        prim[np++] = i;
        for (int j = i+i;j < maxn;j+=i) fg[j] = true;
    }
    //cout<<np<<endl;
}

bool ok2(long long a, int id) {
    for(int i = 0;i < np && 1ll * prim[i] * prim[i] <= a;i++){
        if(a % prim[i] == 0) {
            res[id] = prim[i];
            return 1;
        }
    }
    return 0;
}

bool ok() {
    int i, k;
    long long a, b;
    for(i = 2;i <= 10;i++) {
        a = 1;
        b = 1;
        for(k = 1;k < n;k++) {
            b = b * i;
            if(num[k] == 1) a = a + b;
        }
        //cout<<"**"<<a<<endl;
        if(!ok2(a, i)) return 0;
    }
    return 1;
}

void print() {
    int i;
    for(i = n-1;i >= 0;i--)
        printf("%d", num[i]);
    for(i = 2;i <= 10;i++)
        printf(" %d", res[i]);
    printf("\n");
}

void dfs(int dep) {
    if(flag) return;
    if(dep == n-1) {
        if(ok()) {
            print();
            cnt++;
        }
        if(cnt == j) flag = 1;
        return;
    }
    num[dep] = 0;
    dfs(dep + 1);
    num[dep] = 1;
    dfs(dep + 1);
    return;
}

int main() {
    freopen("C-small-attempt2.in", "r", stdin);
    freopen("1.out", "w", stdout);
    init();
    int t, cas = 1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &j);
        memset(num, 0, sizeof(num));
        num[0] = num[n-1] = 1;
        cnt = flag = 0;
        printf("Case #%d:\n", cas++);
        dfs(1);
    }
    return 0;
}
