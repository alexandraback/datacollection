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

#define mx 120

vector< pair< char , int> > form( st &str){
    char now=' ';
    vector< pair< char , int > > ret;
    int cnt=0;
    rep(i,sz(str)){
        if( now == str[i] ) cnt++;
        else{
            if(now!=' ') ret.pb( mp( now , cnt ) );
            now=str[i];
            cnt=1;
        }
    }
    if( cnt>0 ) ret.pb( mp(now,cnt) );
    return ret;
}

vector< pair< char , int> > A[mx];

int call( vector< pair< char , int> > &a, vector< pair< char , int> > &b){
    if(sz(a)!=sz(b)) return inf;
    int ret=0;
    rep(i,sz(a)){
        if(a[i].xx!=b[i].xx) return inf;
        ret+=abs( a[i].yy - b[i].yy );
    }
    return ret;
}

int main(){
    time_t start=clock();
    read("in.txt");
    rite("out.txt");

    ios_base::sync_with_stdio(0);

    int TEST, KAS=0;
    cin>>TEST;
    while( TEST-- ){
        int n;
        cin>>n;
        rep(i,n){
            st temp;
            cin>>temp;
            A[i]=form(temp);
        }
        i64 ans=inf;
        rep(i,n){
            i64 temp=0;
            rep(j,n){
                temp+=call(A[i],A[j]);
            }
            ans=min(ans,temp);
        }
        cout<<"Case #"<<++KAS<<": ";
        if(ans>=inf) cout<<"Fegla Won"<<endl;
        else{
            ans=0;
            for(int j=0; j<sz(A[0]); j++){
                //cout<<A[0][j].xx<<"--->"<<endl;
                int temp=inf;
                for(int amount=1; amount<=100; amount++){
                    int now=0;
                    rep(i,n){
                        now+=abs( amount - A[i][j].yy );
                    }
                    temp=min(temp,now);
                }
                ans+=temp;
            }
            cout<<ans<<endl;
        }
    }

    cerr << " Program has run "<< ( clock()-start ) / 1000 << " s " << endl;
    return 0;
}
