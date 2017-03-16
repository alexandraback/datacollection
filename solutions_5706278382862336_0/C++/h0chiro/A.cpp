#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int pop(ll x) {
  int n = 0;
  while(x != 0) {
    n++;
    x &= (x-1);
  }
  return n;
}

int solve(ll P, ll Q) {
    ll g = gcd(P, Q);
    P /= g, Q /= g;
    if (pop(Q) != 1) return -1;
    if (P == 1 && Q == 1) return 0;

    int ans = 1;
    while(P < Q/2) {
        ans++;
        P *= 2;
    }
    return ans;
}

int main() {
    int N;
    cin>>N;

    for (int i = 0; i < N; ++i) {
        ll P, Q;
        scanf("%lld/%lld", &P, &Q);

        cout<<"Case #"<<(i+1)<<": ";
        int ans = solve(P, Q);
        if (ans == -1) cout<<"impossible"<<endl;
        else cout<<ans<<endl;
    }
}
