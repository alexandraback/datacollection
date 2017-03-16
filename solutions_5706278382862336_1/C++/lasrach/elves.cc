#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

long long int gcd(long long int a, long long int b) { return (a>b)?gcd(b,a):(a?gcd(b%a,a):b); }

int main() {
    int T = 0;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);

        long long int p, q;
        scanf(" %lld/%lld", &p, &q);
        long long int g;
        g = gcd(p,q);
        p/=g;
        q/=g;


        int i=0;
        while(p<q && q%2==0) {
            q/=2;
            i++;
        }

        int bits = 0;
        for (int i=0; i<60; i++) {
            if (q & (1LL<<i)) bits++;
        }
        if (p>=q && bits==1 && i<=40) {
            printf("%d\n", i);
        } else {
            printf("impossible\n");
        }
    }
}

// vim: set ff=unix ai tw=80 ts=4 sts=4 sw=4 et:
