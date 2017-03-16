#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <set>

#define MAXN 100100
#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<int,int> pr;
typedef long long ll;

int t;

ll gcd(ll a , ll b) {
    return b == 0 ? a : gcd(b , a % b);
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("outputA.txt","w",stdout);


    scanf("%d",&t);
    for (int tc = 1; tc <= t; tc++) {
        ll a , b;
        int ans = 0;
        scanf("%lld/%lld",&a,&b);
        long long g = gcd(a , b);
        a /= g; b /= g;
        ll c = b;
        while (c != 1) {
            if (c % 2 == 1) {
                ans = -1;
                break;
            }
            c /= 2;
        }
        if (ans != -1) {
            double k = 1;
            for (int i = 1; i <= 40; i++) {
                double p = a / (b * 1.0);
                if (p >= k) break;
                ans++; k /= 2.0;
            }
        }
        if (ans == -1) printf("Case #%d: impossible\n",tc);
        else printf("Case #%d: %d\n" ,tc,ans);
    }

    return 0;
}
