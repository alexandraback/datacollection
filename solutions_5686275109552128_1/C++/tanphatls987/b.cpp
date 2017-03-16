#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B-large.in","r",stdin)
#define OUTPUT freopen("b.out","w",stdout)
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
const int N=1e3+10;

int test,n,a[N];
int main(){
    INPUT;OUTPUT;
    scanf("%d",&test);
    FOR(T,1,test){
        scanf("%d",&n);
        FOR(i,1,n) scanf("%d",a+i);
        int ans=2000;
        FOR(lim,1,1000){
            int cur=lim;
            FOR(i,1,n) cur+=(a[i]+lim-1)/lim-1;
            ans=min(ans,cur);
        }
        printf("Case #%d: %d\n",T,ans);
    }
}
