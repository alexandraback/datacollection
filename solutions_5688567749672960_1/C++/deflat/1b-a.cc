#include<iostream>
#include<sstream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<functional>
#include<climits>
#include<utility>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;

#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define FORB(i,s,e,st) for (int i = int(s); i < int(e); i+=(int(st)))
#define FOR(i,s,e) FORB(i,s,e,1)
#define REP(i,x) FOR(i,0,x)
#define CLR(a) memset((a), 0 ,sizeof(a))

#define ctoi(c) (c-'0')

const int MOD = 1000000007;
const double PI  = acos(-1.0);


ll make_cnt(string out){
    int d=out.size();
    ll ret=0;
    if(d%2){
        ret+=(ctoi(out[(d-1)/2]));
        REP(i,(d-1)/2) ret*=10;
    }
    ll aa=0,bb=0;
    ll ind=1;
    REP(i,d/2){
        aa+=ctoi(out[i])*ind;
        bb+=ctoi(out[d-i-1])*ind;
        ind*=10;

    }
    if(d!=1&&ret==0&&aa==1&&bb==0) return -1;
    if(aa>1) ret++;
    
    return ret+aa+bb-(d==1?0:2);
}

int main(){

    int T;
    cin>>T;
    REP(t,T){
        cout<<"Case #"<<(t+1)<<": ";
        ll n;
        cin>>n;
        
        ostringstream oss;
        bool ck=false;
        if(n%10==0){
            ck=true;
            n--;
        }
        oss<<n;
        
        int d=oss.str().size();
        ll ret=-2;
        string st="";
        REP(i,d-1){
            st+="9";
            ret=ret+2+make_cnt(st);
        }
        cout<<ret+2+make_cnt(oss.str())+(ck?1:0)<<"\n";
    }
}
