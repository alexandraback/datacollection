#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int N,M,K;
bool f[1000];
int a[1000];
int C,D,V;
void add(int w) {
    for (int j = V; j >= w; j--)
        if (f[j-w]) f[j] = true;
}

int main() {
    freopen("C-small-attempt0.in","r",stdin);
    freopen("Csmall.out","w",stdout);
    int T;
    cin >> T;
    int ans;
    for (int o = 1; o <= T; o++) {
        cin >> C >> D >> V;
        for (int i = 1; i <= D; i++)
            cin >> a[i];
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (int i = 1; i <= D; i++)
            add(a[i]);
        int ans = 0;
        for (int i =1 ; i<=V;i++)
            if (!f[i]) {
                add(i);
                ans++;
            }
        printf("Case #%d: %d\n", o, ans);
    }
}
