#include<bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define eps (1e-9)
#define inf (1<<29)
#define i64 long long
#define u64 unsigned i64

vector<int> a,b,c;
i64 dp[200][2][2][2];
vector<int> getBin(int n){
    vector<int> ret;
    while(n){
        if(n & 1) ret.pb(1);
        else ret.pb(0);
        n/=2;
    }
    if(ret.size()==0) ret.pb(0);
  //  reverse(all(ret));
    return ret;
}
i64 solve(int pos,int asmall,int bsmall,int csmall){
    if(pos == a.size()) return 1;
    i64 &ret = dp[pos][asmall][bsmall][csmall];
    if(ret!=-1) return ret;
    ret = 0;
    int aup = a[pos],bup = b[pos],nam,nbm,ncm,i,j;
    if(asmall) aup = 1;
    if(bsmall) bup = 1;
    for(i = 0;i<=aup;i++){
        if(asmall==1 || i<a[pos]) nam = 1;
        else nam = 0;
        for(j = 0;j<=bup;j++){
            if(bsmall==1 || j<b[pos]) nbm = 1;
            else nbm = 0;
            int k = i & j;
            if(csmall == 0 && k>c[pos]) continue;
            if(csmall == 1 || k<c[pos]) ncm = 1;
            else ncm = 0;
            ret+=solve(pos+1,nam,nbm,ncm);
        }
    }
    return ret;
}
int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);

  int t,cs = 1,A,B,K;
    cin>>t;
    while(t--){
        cin>>A>>B>>K;
        A--, B--, K--;
        a = getBin(A);
        b = getBin(B);
        c = getBin(K);
        int mx = max(a.size(),max(b.size(),c.size()));
        while(a.size()<mx) a.push_back(0);
        while(b.size()<mx) b.push_back(0);
        while(c.size()<mx) c.push_back(0);
        reverse(all(a));
        reverse(all(b));
        reverse(all(c));
        SET(dp);
        printf("Case #%d: %lld\n",cs++,solve(0,0,0,0));
    }
	return 0;
}
