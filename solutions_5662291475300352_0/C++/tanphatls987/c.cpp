#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C-small-1-attempt0.in","r",stdin)
#define OUTPUT freopen("c.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=10;

int test,n,st,m1,x;
ii a[N];
int main(){
    INPUT;OUTPUT;
    scanf("%d",&test);
    FOR(T,1,test){
        scanf("%d",&n);
        int m=0;
        FOR(i,1,n){
            scanf("%d%d%d",&st,&m1,&x);
            FOR(j,1,m1) a[++m]=ii(x+j-1,st);
        }
        printf("Case #%d: ",T);
        if (m==1) printf("0\n");
        if (m==2){
            sort(a+1,a+m+1);
            printf("%d\n",1LL*(720-a[1].Y)*a[1].X<=1LL*(360-a[2].Y)*a[2].X);
        }
    }
}
