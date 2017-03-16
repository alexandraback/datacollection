#include <iostream>
#include <cstdio>
using namespace std;

int a[1000005];
int N = 1000000;
int re(int x) {
    int y = 0;
    while (x) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return y;
}
int main() {
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small.out","w",stdout);
    a[1] = 1;
    for (int i = 2; i <= N; i++)
        a[i] = i;
    for (int i = 1; i <= N; i++) {
        a[i+1]=min(a[i+1],a[i]+1);
        int k = re(i);
        if (k <= N)
        a[k]=min(a[k],a[i]+1);
    }
    int T; cin >> T;
    for (int o = 1; o <= T; o++) {
        int n;
        cin >> n;
        printf("Case #%d: %d\n",o,a[n]);
    }
}
