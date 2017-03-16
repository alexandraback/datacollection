#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    int t, cases = 1;
    scanf ("%d", &t);


    while (t--){
        long long k, c, s;
        scanf ("%lld %lld %lld", &k, &c, &s);
        printf ("Case #%d:", cases++);
        ll group = 1;
        while (--c > 0)
            group *= k;

        ll ans = 1;
        while (k--)
            printf (" %lld", ans), ans += group;
        printf ("\n");
    }
}
