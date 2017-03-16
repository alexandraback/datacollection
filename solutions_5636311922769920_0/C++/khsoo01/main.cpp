#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll tc,k,c,s;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll i,j,x,q,cur;
    scanf("%lld",&tc);
    for(q=1;q<=tc;q++) {
        scanf("%lld%lld%lld",&k,&c,&s);
        printf("Case #%lld: ",q);
        if(s<(k+c-1)/c) {
            puts("IMPOSSIBLE");
            continue;
        }
        for(i=0;i<k;i+=c) {
            cur = 0;
            for(j=1,x=0;x<c;j*=k,x++) {
                cur += min((i+x),k-1)*j;
            }
            printf("%lld ",cur+1);
        }
        puts("");
    }
}
