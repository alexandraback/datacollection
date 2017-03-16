#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;

ll solve(ll p, ll q)
{
    ll gc = __gcd(p, q);
    p /= gc;
    q /= gc;
    
    //cerr << "a " << p << " " << q << endl;
    if ((q & (q-1)) != 0ll)return -1;
    ll ans = 0;
    while (q>1) {
        ans++;
        q /= 2;
    }
    while (p>1)
    {
        ans--;
        p /= 2;
    }
    
    
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++)
    {
        ll p, q;
        scanf("%lld/%lld", &p, &q);
        ll r = solve(p, q);
        //cout << "r " << r << endl;
        printf("Case #%d: ", i);
        if (r < 0) printf("impossible\n");
        else printf("%lld\n", r);
    }
}
