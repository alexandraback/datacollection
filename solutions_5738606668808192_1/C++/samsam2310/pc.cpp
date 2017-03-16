#include <bits/stdc++.h>
#define F(n) Fi(i,n)
#define Fi(i,n) Fl(i,0,n)
#define Fl(i,l,n) for(int i=(l);i<(n);i++)
using namespace std;
const int N = (1<<16)+1;
typedef __int128 LL;
vector<int> P;
bool isP[N];
void initP(){
    F(N-2)isP[i+1] = true;
    for(int i=2;i<N;i++)if(isP[i]){
        P.push_back(i);
        for(int j=i*2;j<N;j+=i)isP[j] = false;
    }
}
int isPrime(long long x){
    if(x < N)assert(x>=0);
    if(x < N && isP[x])return 0;
    for(int p:P){
        if(p>=x)return 0;
        if(x%p==0)return p;
    }
    return 0;
}
LL base[11][33];
void initBase(){
    Fl(i,2,11){
        base[i][0] = 1;
        Fi(j,30)base[i][j+1] = base[i][j]*i;
    }
}
bool check(LL s, int l, vector<int>&dv){
    dv.clear();
    // cout<<"s: "<<s<<endl;
    Fl(b,2,11){
        LL now = 0;
        F(l)if(s&(1ll<<i))now += base[b][i];
        // cout<<"DD:    "<<now<<endl;
        int tmp = isPrime(now);
        if(tmp)dv.push_back(tmp);
        else{
            // cout<<"JIZZ: "<<now<<endl;
            return false;
        }
    }
    return true;
}
string base2S(LL x){
    string s;
    while(x)s+=(x&1)?'1':'0', x>>=1;
    reverse(s.begin(),s.end());
    return s;
}
void solve(int l,int all){
    vector<int> dv;
    Fi(h,1<<(l-2)){
        LL now = (h<<1) + (1ll<<(l-1)) + 1;
        // LL tmp = 0;
        // F(l)if(now&(1ll<<i))tmp += base[10][i];
        // cout<<tmp<<endl;
        if(check(now, l, dv)){
            cout<<base2S(now);
            F(9)cout<<' '<<dv[i];
            cout<<endl;
            all--;
        }
        // cout<<"ALL :"<<all<<endl;
        if(all == 0)break;
    }
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    initP();
    initBase();
    int n,j;
    cin>>n;
    cin>>n>>j;
    cout<<"Case #1:"<<endl;
    solve(n,j);
}