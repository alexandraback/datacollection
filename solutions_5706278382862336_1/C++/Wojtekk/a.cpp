#include<cstdio>
#include<algorithm>
using namespace std;


long long gcd(long long a, long long b) {
    if(b == 0) return a;
    else return gcd(b, a%b);
}

void solve() {
    long long p, q;
    char znak;
    scanf("%lld%c%lld", &p, &znak, &q);
 //   printf("%lld %lld", p, q);
    long long nwd = gcd (p, q);
    p/=nwd;
    q/=nwd;
    int bitq =  __builtin_popcountll(q);
  //  printf(%d", bitq);
    if(bitq != 1) {
        printf("impossible");
        return ;
    }
    long long mn =1LL;
    int licz = 0;
    long double ul = (long double)p / (long double) q;
    while(ul < 1.0 ) {
        ul = ul * 2.0;
        licz++;
    }
    printf("%d", licz);
}

int main() {
    int testy;
    scanf("%d", &testy);
    for(int i=1; i<=testy; ++i) {
        printf("Case #%d: ", i);
        solve();
        printf("\n");
    }

    return 0;
}
