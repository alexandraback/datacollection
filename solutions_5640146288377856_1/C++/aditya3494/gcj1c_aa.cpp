#include<bits/stdc++.h>

using namespace std;
typedef long long lli;

lli gcd(lli a, lli b)
{
    if(a == 0) {
        return b;
    } else {
        return gcd(b%a, a);
    }
}

lli exp(lli b, lli n, lli MOD)
{
    lli ans = 1;
    while(n > 0) {
        if(n&1) ans = (ans * b) % MOD;
        n >>= 1;
        b = (b * b) % MOD;
    }
    return ans;
}

/*This was cool code */

int main()
{

        freopen("f11.in","r",stdin);
        freopen("f11out.txt","w",stdout);

        int t;
        cin>>t;
        lli R, C, W;
        for(int kase =1;kase <=t;kase++) {
            cin >> R >> C >> W;
            lli sol = 0;
            lli part = C/W;

            if(C%W == 0) {
                sol = W-1+part*R;
            } else {
                sol = W+part*R;
            }

            printf("Case #%d: %lld\n", kase, sol);
        }

        return 0;
}



