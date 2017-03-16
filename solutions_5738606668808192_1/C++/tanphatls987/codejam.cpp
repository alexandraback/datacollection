#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("codejam.inp","r",stdin)
#define OUTPUT freopen("codejam.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=32;

int a[N];
bool checkbase(){

    FOR(pha,2,10){
        int mdiv=pha==6?7:3-pha%2;
        int cur=0;
        FORD(i,N-1,0) cur=(cur*pha+a[i])%mdiv;
        if (cur) {
            printf("=>%d %d %d",cur,pha,mdiv);
            return 0;
        }
    }
    return 1;
}
int main(){
//    freopen("input.inp","r",stdin);
    OUTPUT;
    printf("Case #1:\n");
    a[0]=a[N-1]=1;
    int need=500;
    for(int i1=2;i1<N;i1+=2)
        for(int i2=i1+2;i2<N;i2+=2)
            for(int j1=1;j1<N-1;j1+=2)
                for(int j2=j1+2;j2<N-1;j2+=2) if (need){
                    a[i1]=a[i2]=a[j1]=a[j2]=1;
                    FORD(i,N-1,0) printf("%d",a[i]);
                    assert(checkbase());
                    FOR(i,2,10) printf(" %d",i==6?7:3-(i%2));
                    ENDL;
                    a[i1]=a[i2]=a[j1]=a[j2]=0;
                    need--;
                }
}
