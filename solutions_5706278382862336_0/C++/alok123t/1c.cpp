#include<bits/stdc++.h>
using namespace std;
bool f(long long int x)
{
    while(x > 1) {
        if(x%2 == 0) {
            x /= 2;
        }
        else return true;
    }
    return false;
}
long long int gcd(long long int u, long long int v) {
  long long int t;
  while (v) {
    t = u;
    u = v;
    v = t % v;
  }
  return u < 0 ? -u : u;
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    long long int p , q;
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
        int co = 0;
        scanf("%lld/%lld",&p,&q);
        long long int g = gcd(p,q);
        if(g != 1) {
            p/=g;
            q/=g;
        }
        printf("Case #%d: ",i);
        if(f(q)) {
            printf("impossible\n");
            continue;
        }
        while(true) {
            if(p>=q) break;
            p*=2;
            co++;
        }
        printf("%d\n",co);
    }
    return 0;
}
