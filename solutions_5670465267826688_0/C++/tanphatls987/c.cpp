#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C-small-attempt0.in","r",stdin)
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
const int N=1e4+10;
const int g[5][5]={{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};

int mul(int x,int y){
    return ((x*y>0)?1:-1)*g[abs(x)][abs(y)];
}
char s[N];
int test,n,fre[N],suf[N],all[5],a[20],mark[N][10];
ll m;
int main(){
    INPUT;OUTPUT;
    scanf("%d",&test);
    FOR(T,1,test){
        scanf("%d%lld\n",&n,&m);
        scanf("%s",s);
        //printf("%d %lld %s\n",n,m,s);
        fre[0]=1;
        memset(mark,sizeof(mark),0);
        memset(a,0,sizeof(a));
        mark[0][5]=1;
        FOR(i,1,n) {
            fre[i]=mul(fre[i-1],s[i-1]-'i'+2);
            FOR(j,0,10) mark[i][j]=mark[i-1][j]||(fre[i]+4==j);
            //cout<<fre[i]<<" \n"[i==n];
        }
        //printf("tick\n");
        suf[n+1]=1;
        bool ok=false;
        a[5]=1;
        FORD(i,n,1) {
            suf[i]=mul(s[i-1]-'i'+2,suf[i+1]);
            //cout<<suf[i]<<" \n"[i==1];
            a[suf[i]+4]=1;

        }
        all[0]=1;
        //FOR(i,0,n) cout<<fre[i]<<" \n"[i==n];
        //FOR(i,1,n+1) cout<<suf[i]<<" \n"[i==n];
        FOR(i,1,3) all[i]=mul(all[i-1],fre[n]);
        if (all[m%4]==-1){
            FOR(i1,0,3)
                FOR(i2,0,3) if (i1+i2<=m-1&&(i1+i2+1)%4==m%4)
                    FORD(i3,n+1,2) if (mul(suf[i3],all[i2])==4)
                        FOR(i4,-4,4) if (mark[i3-2][i4+4]&&mul(all[i1],i4)==2) ok=true;
            FOR(i1,0,3)
                FOR(i2,0,3) if (i1+i2<=m-2&&(i1+i2+2)%4==m%4)
                    FOR(i3,-4,4) if (mark[n][i3+4]&&mul(all[i1],i3)==2)
                        FOR(i4,-4,4) if (a[i4+4]&&mul(i4,all[i2])==4) ok=true;
        }
        printf("Case #%d: ",T);
        if (ok) printf("YES\n");
        else printf("NO\n");
    }
}
