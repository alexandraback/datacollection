#include <cstdio>
using namespace std;
typedef unsigned long long ll;

int A,B,K;

int memo[100][100][2][2];
ll ways (int x,int diff,int ok1,int ok2) {
    if (memo[x][diff][ok1][ok2]!=-1) {
        return memo[x][diff][ok1][ok2];
    }
    if (x>diff) {
        if (K&(1<<x)) {
            if (!ok1 && !(A&(1<<x)) || !ok2 && !(B&(1<<x))) return 0;
            return memo[x][diff][ok1][ok2]=ways(x-1,diff,ok1,ok2);
        }
        else {
            int nok1=ok1,nok2=ok2;
            if (A&(1<<x)) nok1=1;
            if (B&(1<<x)) nok2=1;
            ll tot = ways(x-1,diff,nok1,nok2);
            if (ok1 || (A&(1<<x))) {
                nok2=ok2;
                if (B&(1<<x)) nok2=1;
                tot += ways(x-1,diff,ok1,nok2);
            }
            if (ok2 || (B&(1<<x))) {
                nok1=ok1;
                if (A&(1<<x)) nok1=1;
                tot += ways(x-1,diff,nok1,ok2);
            }
            return memo[x][diff][ok1][ok2]=tot;
        }
    }
    if (!(K&(1<<x))) return 0;
    ll w1 = (((1<<x)-1)&A);
    ll w2 = (((1<<x)-1)&B);
    if (ok1 || (A&(1<<x))) w1=(1<<x);
    if (ok2 || (B&(1<<x))) w2=(1<<x);
    ll tot = w1*w2;
    if (ok1 || (A&(1<<x))) {
        ll w3 = (((1<<x)-1)&A);
        if (ok1) w3=(1<<x);
        tot += w3*w2;
    }
    if (ok2 || (B&(1<<x))) {
        ll w3 = (((1<<x)-1)&B);
        if (ok2) w3=(1<<x);
        tot += w3*w1;
    }
    return memo[x][diff][ok1][ok2]= tot;
}

int T;
int main () {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&T);
    for (int z=1;z<=T;++z) {
    scanf("%d %d %d",&A,&B,&K);
    ll sum=0;
    for (int i=0;i<100;++i) for (int j=0;j<100;++j) for (int k=0;k<2;++k) for (int l=0;l<2;++l) memo[i][j][k][l]=-1;
    for (int i=0;i<=30;++i) {
        ll t;
        sum += (t=ways(30,i,0,0));
    }
    printf("Case #%d: %llu\n",z,sum);
}
    return 0;
}
