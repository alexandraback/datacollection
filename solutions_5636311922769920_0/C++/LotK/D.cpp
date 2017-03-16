#include <cstdio>

long long kpower[200];
void sol(int k, int c, int s) {
    kpower[0] = 1;
    for (int i=1 ; i<c ; i++) {
        kpower[i] = kpower[i-1]*k;
    }

    // calculate 0-based position
    int count = 0;
    while (count < k) {
        long long sum = 0;
        if (count+c <= k) {
            for (int i=1 ; i<=c ; i++) {
                sum += (count+i-1)*kpower[c-i];
            }
            count += c;
        }
        else {
            for (int i=1 ; count+i<=k ; i++) {
                sum += (count+i-1)*kpower[c-i];
            }
            count = k;
        }
        printf(" %lld", sum+1);
    }
}

int main() {
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("D-small-attempt0.out", "w", stdout);

    int tt;
    scanf("%d", &tt);
    for (int t=0 ; t<tt ; t++) {
        int k, c, s;
        scanf("%d%d%d", &k, &c, &s);

        if (c*s < k) {
            printf("Case #%d: IMPOSSIBLE\n", t+1);
        }
        else {
            printf("Case #%d:", t+1);
            sol(k, c, s);
            printf("\n");
        }
    }
}
