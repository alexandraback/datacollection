#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve (ll idx) {
    ll i, j, k, l, cur, val[77];
    for(i=1,j=0;i<=idx;i*=2,j++) {
        val[j] = !!(idx&i);
    }
    for(i=0;i<j;i++) val[j+i] = val[i];
    for(i=2*j;i--;) {
        printf("%lld",val[i]);
    }
    for(i=2;i<=10;i++) {
        cur = 0;
        for(k=1,l=0;l<j;k*=i,l++) {
            cur += val[l]*k;
        }
        printf(" %lld",cur);
    }
    puts("");
}

int main()
{
    freopen("output.txt","w",stdout);
    ll i=129,j;
    puts("Case #1:");
    for(j=0;j<100;j+=2) solve(i+j);
}
