#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

int T;
ll P, Q;
string S;

ll gcd (ll a, ll b) {
    return (a == 0) ? b : gcd (b % a, a);
}


int main() {
    scanf("%d\n", &T);
    for (int xxx = 1; xxx <= T; xxx++) {
        printf("Case #%d: ", xxx);
        cin >> S;
        int poss = S.find('/');
        P = Q = 0;
        for (int i = 0; i < poss; i++)
            P = (ll) 10 * P + (ll) (S[i] - '0');
        for (int i = poss+ 1; i < S.size(); i++)
            Q = (ll) 10 *Q + (ll) (S[i] - '0');
        
        ll G = gcd (P, Q);
        P /= G; Q /= G;
    
        bool ok = true;
        int power = 0;
        while (Q > 1 && Q % 2 == 0) {
            power++;
            Q /= 2;
        }
        if (Q != 1) printf("impossible\n");
        else {
            for (int i = 0; i < power; i++)
                Q *= 2;
            int ANS = 1;
            ll t = 2;
            while (P < Q/t) {
                t *= (ll) 2;
                ANS ++;
            }
            printf ("%d\n", ANS);
        }
    }


    return 0;
}
