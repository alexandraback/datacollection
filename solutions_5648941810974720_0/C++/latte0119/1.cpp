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

string S;
map<char,int>cnt;
int ans[10];

void f(string s,char c,int d){
    int tmp=cnt[c];
    ans[d]=tmp;
    for(auto e:s)cnt[e]-=tmp;
}

void solve(int hoge){
    cout<<"Case #"<<hoge+1<<": ";
    cin>>S;
    cnt.clear();
    memset(ans,0,sizeof(ans));
    for(auto c:S)cnt[c]++;
    f("ZERO",'Z',0);
    f("TWO",'W',2);
    f("SIX",'X',6);
    f("EIGHT",'G',8);
    f("THREE",'T',3);
    f("FOUR",'R',4);
    f("FIVE",'F',5);
    f("ONE",'O',1);
    f("SEVEN",'V',7);
    f("NINE",'I',9);

    rep(i,10)rep(j,ans[i])cout<<i;cout<<endl;
}

signed main(){
    int T;cin>>T;
    rep(i,T)solve(i);
    return 0;
}

//EGNTNOIONEEIEZRH
