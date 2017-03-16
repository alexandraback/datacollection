#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    int t, cases = 1;
    scanf ("%d", &t);
    while (t--){
        ll k, c, s;
        scanf ("%lld %lld %lld", &k, &c, &s);
        printf ("Case #%d:", cases++);

        if (c==1){
            if (k != s){
                printf (" IMPOSSIBLE\n");
                continue;
            }
            for (ll i = 1; i <= k; i++)
                printf (" %lld", i);
            printf ("\n");
            continue;
        }

        if ((k + 1)/2 > s){
            printf (" IMPOSSIBLE\n");
            continue;
        }
        ll bucket = 1;
        while (--c > 0) bucket *= k;

        ll i = 1;
        while (i <= k){
            if (i%2==0)
                printf (" %lld", (i-2)*bucket + i);
            i++;
        }
        i--;
        if (k%2)
            printf (" %lld", (i-1)*bucket + 1);
        printf ("\n");

    }

    return 0;
}
