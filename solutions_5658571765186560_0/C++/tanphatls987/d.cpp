#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D-small-attempt0.in","r",stdin)
#define OUTPUT freopen("d.out","w",stdout)
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
const int N=0;

int test,n,m,x;
bool solve(){
    if (x>=7) return true;
    if (n*m%x) return true;
    if (n<m) swap(n,m);
    if ((x+1)/2>m||x>n) return true;
    if (x==5&&m==3&&n==5) return true;
    if (x==6&&m==3) return true;
    if (x==4&&m==2) return true;
    return false;
    //x-=m;
}
int main(){
    INPUT;OUTPUT;
    scanf("%d",&test);
    FOR(T,1,test){
        scanf("%d%d%d",&x,&n,&m);
        printf("Case #%d: ",T);
        if (solve()) printf("RICHARD\n");
        else printf("GABRIEL\n");
    }
}
