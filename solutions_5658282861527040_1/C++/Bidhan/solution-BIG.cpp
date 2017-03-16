/*
 * Bidhan Roy
 * University of Dhaka
 */

using namespace std;
#include <bits/stdc++.h>

#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define sgn(x,y) ((x)+eps<(y)?-1:((x)>eps+(y)?1:0))
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define rite(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define clr clear()
#define inf (1<<30)
#define ins insert
#define xx first
#define yy second
#define eps 1e-9

typedef long long i64;
typedef unsigned long long ui64;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int,int> mii;
typedef map<st,int> msi;
typedef set<int> si;
typedef set<st> ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define mx 50

bool chk(i64 a,int bit){
    return bool(a&(1ll<<bit));
}

i64 a,b,k;

i64 dp[mx][2][2][2];

i64 call(int pos,bool sa,bool sb,bool sc){
    if(pos==-1) return (sa && sb && sc);
    i64 &ret=dp[pos][sa][sb][sc];
    if(ret!=-1) return ret;
    int tilla=sa?1:chk(a,pos);
    int tillb=sb?1:chk(b,pos);
    int tillc=sc?1:chk(k,pos);
    ret=0;
    rep(i,tilla+1) rep(j,tillb+1) {
        int bit=bool(i&j);
        //cout<<i<<"---
        if(bit>tillc) continue;
        ret+=call(pos-1, sa | (i<tilla) , sb | (j<tillb) , sc | (bit<tillc) );
    }
    //cout<<i<<" "<<sa<<" "<<sb<<" "<<sc<<"="<<ret<<endl;
    return ret;
}

int main(){
    //cout<<chk(1<<1,3)<<endl;
    time_t start=clock();
    read("inBIG.txt");
    rite("outBIG.txt");

    ios_base::sync_with_stdio(0);

    int TEST, KAS=0;
    cin>>TEST;
    while( TEST-- ){
        cin>>a>>b>>k;
        cout<<"Case #"<<++KAS<<": ";
        mem(dp,-1);
        cout<<call(35,0,0,0)<<endl;
    }

    cerr << " Program has run "<< ( clock()-start ) / 1000 << " s " << endl;
    return 0;
}
