#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n, m;
int a[20];

void calcu(ll n) {
    while(n) {
        a[n % 10] = 1;
        n /= 10;
    }
}
int check() {
    for(int i = 0; i <= 9; i++) {
        if(a[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void solve() {
    m = n;
    for(int i = 0; i <= 9; i++) {
        a[i] = 0;
    }
    while(1) {
        calcu(m);
        if(check()) {
            break;
        }
        m += n;
    }
    printf("%lld\n", m);
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("Aout.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        scanf("%lld", &n);
        if(n == 0) {
            printf("INSOMNIA\n");
        }
        else {
            solve();
        }
    }
    return 0;
}
