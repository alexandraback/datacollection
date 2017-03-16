#include<bits/stdc++.h>
using namespace std;
int a[1024*1024];
int p[1024*1024];
int rev(int k) {
    int res = 0;
    while(k) {
        res = res * 10 + k % 10;
        k /= 10;
    }
    return res;
}
long long solve(int n) {
    int N = n;
    memset(a, 0, sizeof(a));
    a[n] = 1;
    while(--n) {
        a[n] = a[n+1] + 1;
        p[n] = n+1;
        int r = rev(n);
        if(r <= N && r > n && a[r]+1 < a[n]) {
            a[n] = a[r] + 1;
            p[n] = r;
        }
    }
    return a[1];
}
int solveR(long long n) {
    int r = rev(n);
    return 0;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    long long n;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> n;
        printf("Case #%d: %lld\n", t, solve(n));
        //for(int v = 1; v < n; v = p[v])
        //    printf("%d ", v);
        //printf("%d\n", n);
    }
}
