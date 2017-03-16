#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll K[128];

ll f(ll s, ll d, ll k, ll c){
    if(d == c){
        return s;
    } else {
        return (s-1) * K[d] + f(min(s+1, k), d+1, k, c);
    }
}

void Solve(int t){
    printf("Case #%d: ", t);
    int k, c, s;
    scanf("%d%d%d", &k, &c, &s);
    if(c * s < k){
        printf("IMPOSSIBLE\n");
        return;
    }
    for(int i = c ; i >= 1 ; i--)
        if(i == c) K[i] = 1;
        else K[i] = K[i+1] * k;
    for(int i = 1 ; i <= k ; i += c)
        printf("%lld ", f(i, 1, k, c));
    printf("\n");

}

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 1 ; i <= t ; i++)
        Solve(i);
    return 0;
}
