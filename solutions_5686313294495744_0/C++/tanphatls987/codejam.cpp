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
const int N=20;

map <string,int> ma[2];
ii a[N];
int n,h[2][N];
string s1,s2;
struct graph{
    vector <int> v[N];
    int match[N],re[N],s[N],h[N],deg[N];
    void reset(){
        memset(match,0,sizeof(match));
        memset(re,0,sizeof(re));
        memset(deg,0,sizeof(deg));
        REP(i,0,N) v[i].clear();
    }
    bool DFS(int x){
        for(auto y:v[x]) if (!h[y]){
            h[y]=1;
            bool ok=!match[y];
            if (!ok) ok=DFS(match[y]);
            if (ok){
//                cout<<x<<"->"<<y<<'\n';
                match[y]=x;
                return 1;
            }
        }
        return 0;
    }
    int answer(){
        FOR(i,1,n){
            v[a[i].X].push_back(a[i].Y);
            deg[a[i].Y]++;
        }
        int n1=int(ma[0].size());
        int ans=n;
        FOR(i,1,n1){
            if (v[i].size()==1){
                match[v[i][0]]=n1+1;
                re[i]=1;
                ans--;
            }
            for(auto j:v[i]) if (deg[j]==1&&!match[j]){
                match[j]=n1+1;
                re[i]=1;
                ans--;
            }
        }
        FOR(i,1,n1) s[i]=i;
        FORD(i,n1,1) if (re[s[i]])
            swap(s[i],s[n1--]);
//        cout<<n1<<" "<<ans<<" "<<n<<'\n';
//        FOR(i,1,n1) cout<<s[i]<<" ";ENDL;
        while (1){
            int ln1=n1;
            memset(h,0,sizeof(h));
            FORD(i,n1,1) if (DFS(s[i])){
                re[s[i]]=1;
                swap(s[i],s[n1--]);
                ans--;
            }
            if (n1==ln1) break;
        }
        return ans;
    }
}mygr;
void prepare(){
    cin>>n;
    int n1=0,n2=0;
    ma[0].clear();
    ma[1].clear();
    FOR(i,1,n){
        cin>>s1>>s2;
        if (!ma[0][s1]) ma[0][s1]=++n1;
        if (!ma[1][s2]) ma[1][s2]=++n2;
        a[i]=ii(ma[0][s1],ma[1][s2]);
    }
}
int solve(){
    int ans=0;
    REP(i,0,1<<n){
        memset(h,0,sizeof(h));
        REP(j,0,n) if (i&(1<<j)) {
            h[0][a[j+1].X]=1;
            h[1][a[j+1].Y]=1;
        }
        int cur=n-__builtin_popcount(i);
        REP(j,0,n) if (!(i&(1<<j))){
            if (!h[0][a[j+1].X]) cur=0;
            if (!h[1][a[j+1].Y]) cur=0;
        }
        ans=max(ans,cur);
    }
    return ans;
}
int main(){
    freopen("input.inp","r",stdin);
    OUTPUT;
    int test;
    cin>>test;
    FOR(te,1,test){
        prepare();
        printf("Case #%d: %d\n",te,solve());
    }
}
