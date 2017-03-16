#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dt[1000005],tc;
bool chk[11];

bool correct () {
    for(int i=0;i<10;i++) if(!chk[i]) return true;
    return false;
}

void check (ll num) {
    while(num>0) {
        chk[num%10] = true;
        num /= 10;
    }
}

void solve(ll idx) {
    ll cur = 0,i;
    for(i=0;i<10;i++) chk[i] = false;
    while(correct()) {
        cur += idx;
        check(cur);
    }
    dt[idx] = cur;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll i,x;
    for(i=1;i<=1000000;i++) solve(i);
    scanf("%lld",&tc);
    for(i=1;i<=tc;i++) {
        scanf("%lld",&x);
        printf("Case #%lld: ",i);
        if(x==0) puts("INSOMNIA");
        else printf("%lld\n",dt[x]);
    }
}
