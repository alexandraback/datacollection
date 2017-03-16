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

string S,T;

bool check(char c,int i){
    if(c=='?')return true;
    return c-'0'==i;
}
void update(int &mi,int &a,int &b,int i,int j){
    int d=abs(i-j);
    if(mi>d){
        mi=d;a=i;b=j;
    }
    else if(mi==d){
        if(a>i){
            a=i;
            b=j;
        }
        else if(a==i&&b>j){
            b=j;
        }
    }
}

void solve(int ca){
    cout<<"Case #"<<ca+1<<": ";
    cin>>S>>T;

    int mi=1001001001;
    int a,b;

    if(S.size()==1){
        rep(i,10)rep(j,10){
            if(!check(S[0],i)||!check(T[0],j))continue;
            update(mi,a,b,i,j);
        }
        printf("%lld %lld\n",a,b);
    }
    else if(S.size()==2){
        rep(i,10)rep(j,10)rep(k,10)rep(l,10){
            int x=i*10+j;int y=k*10+l;
            if(!check(S[0],i)||!check(T[0],k))continue;
            if(!check(S[1],j)||!check(T[1],l))continue;
            update(mi,a,b,x,y);
        }
        printf("%02lld %02lld\n",a,b);
    }
    else{
        rep(i,10)rep(j,10)rep(k,10)rep(l,10)rep(m,10)rep(n,10){
            int x=i*100+j*10+k;int y=l*100+m*10+n;
            if(!check(S[0],i)||!check(T[0],l))continue;
            if(!check(S[1],j)||!check(T[1],m))continue;
            if(!check(S[2],k)||!check(T[2],n))continue;
            update(mi,a,b,x,y);
        }
        printf("%03lld %03lld\n",a,b);
    }
}

signed main(){
    int T;cin>>T;
    rep(i,T)solve(i);
    return 0;
}
