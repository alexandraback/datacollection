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
const int N=2e3+10,alp=26;
string number[10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
string mask[10]={"ZERO", "ONE", "TWO", "THRE", "FOUR", "FIVE", "SIX", "SEVN", "EIGHT", "NIE"};

vector <int> v[alp];
int deg[alp],p[alp],n1;
int h[alp],t[alp],ans[alp];
queue <int> q;
string s;
void prepare(){
    FOR(i,0,9)
        for(auto j:mask[i]) v[j-'A'].push_back(i);
    REP(i,0,alp) {
        deg[i]=v[i].size();
        if (deg[i]==1) q.push(i);
    }
//    REP(i,0,alp) cout<<deg[i]<<" \n"[i==alp-1];
    while (!q.empty()){
        int x=q.front();q.pop();
        if (deg[x]==0) continue;
        p[++n1]=x;
        for(auto y:v[x]) if (!h[y]) t[x]=y;
        h[t[x]]=1;
        for(auto j:mask[t[x]]){
            deg[j-'A']--;
            if (deg[j-'A']==1) q.push(j-'A');
        }
    }
//    FOR(i,1,n1) cout<<char('A'+p[i])<<" \n"[i==n1];
//    REP(i,0,alp) cout<<t[i]<<" ";ENDL;
}
void solve(){
    memset(h,0,sizeof(h));
    for(auto ch:s) h[ch-'A']++;
//    REP(i,0,alp) cout<<t[i]<<" ";ENDL;
    FOR(i,1,n1){
        int x=p[i],use=t[x];
        int sub=0;
        for(auto ch:number[use]) if (ch-'A'==x) sub++;
//        cout<<char('A'+x)<<" "<<use<<" "<<h[x]<<" "<<sub<<'\n';
        ans[use]=h[x]/sub;
        for(auto ch:number[use]) h[ch-'A']-=ans[use];
    }
    FOR(i,0,9)
        FOR(j,1,ans[i]) printf("%d",i);ENDL;
}
int main(){
    freopen("input.inp","r",stdin);
    OUTPUT;
    prepare();
    int test;
    cin>>test;
    FOR(te,1,test){
        cin>>s;
        printf("Case #%d: ",te);
        solve();
    }
}
