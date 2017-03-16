#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

int dp[1<<16];

int N;
string S[16],T[16];

void solve(int ca){
    cout<<"Case #"<<ca+1<<": ";
    cin>>N;
    rep(i,N)cin>>S[i]>>T[i];
    memset(dp,0,sizeof(dp));
    rep(i,1<<N){
        rep(j,N){
            if(i>>j&1)continue;
            bool ok1=false,ok2=false;
            rep(k,N){
                if(!(i>>k&1))continue;
                ok1|=S[j]==S[k];
                ok2|=T[j]==T[k];
            }
            chmax(dp[i|(1<<j)],dp[i]+(ok1&&ok2));
        }
    }
    cout<<dp[(1<<N)-1]<<endl;
}

signed main(){
    int T;cin>>T;
    rep(i,T)solve(i);
    return 0;
}
