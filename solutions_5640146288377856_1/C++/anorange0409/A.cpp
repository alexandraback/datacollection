#include <iostream>
#include <cstdio>
using namespace std;
int N,M,K;
int main() {
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T;
    cin >> T;
    int ans;
    for (int o = 1; o <= T; o++) {
        cin >> N >> M >> K;
        if (M % K == 0) {
            ans = M / K + K - 1;
        } else {
            ans = M / K + K;
        }
        ans += (N - 1) * (M / K);
        printf("Case #%d: %d\n", o, ans);
    }
}
