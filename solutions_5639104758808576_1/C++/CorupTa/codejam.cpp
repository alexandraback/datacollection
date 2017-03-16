#include <bits/stdc++.h>
//#define int long long
#define FOR(a,b,c,d) for(int a=b;c;a+=d)
#define nwit(a,b) typeof(b) a=b
#define f0r(a,b) for(nwit(a,b.begin());a!=b.end();a++)
#define imn(a,b) (a==-1||(a>b&&b!=-1))
#define mn(a,b) (imn(a,b)?b:a)
#define smin(a,b) (a=mn(a,b))
#define smax(a,b) (a=max(a,b))
#define btw(a,b,c) (a<=b&&b<=c)
#define fil(a,b) memset(a,b,sizeof(a));
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define fff ff.ff
#define ffs ff.ss
#define ssf ss.ff
#define sss ss.ss
#define MAXN 1001
#define MAXLEN 131072
#define LET 26
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define dosya(a) freopen(a".gir","r",stdin);freopen(a".cik","w",stdout)
#define MOD 1000000007
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> pipii;
typedef pair<pii,int> ppiii;
typedef pair<pii,pii> ppiipii;
typedef pair<string,string> pss;
int v[MAXN],n,ans,tot;
void solve(){
    FOR(i,0,i<=n,1){
        if(tot<i)
            ans+=i-tot,tot=i;
        tot+=v[i];
    }
}
int main(){
    file("A-large");
    int t;
    string s;
    cin >> t;
    FOR(i,1,i<=t,1){
        memset(v,0,sizeof(v));
        ans=tot=0;
        cin >> n >> s;
        FOR(j,0,j<=n,1)v[j]=s[j]-'0';
        solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

}
