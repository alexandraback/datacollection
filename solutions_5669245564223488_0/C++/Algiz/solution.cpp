#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<set>
#include<cassert>
#include<algorithm>
#include<ctime>
#include<deque>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define sz(a) (int(a.size()))
#define step(i) ((i+1)&-(i+1))
#define maxn int(1e5)+15
#define all(c)  (c).begin(),(c).end()

using namespace std;
typedef long long ll;
typedef long double ld;
const int mod=1e9+7;

ll next(){
    char d;
    ll x=0;
    while(1){
        d=getchar();
        if(isdigit(d)){x=d-'0';break;}
    }
    while(1){
        d=getchar();
        if(!isdigit(d)){break;}
        x=x*10ll+d-'0';
    }
    return x;
}
bool was[27];
ll ans;
int n;
bool u[27];
bool is[11][27];
string s[11];
bool can[11];
vector<int> v;
//int g=0;
void go(char l,int sz){
    //cout<<l<<endl;
    //cout<<n<<endl;
    if(sz==n){ans++;/*for(int i=0;i<n;++i)cout<<v[i]<<' ';cout<<endl;*/}
    for(int i=1;i<=n;++i){//cout<<i<<endl;
        if(!u[i] && can[i]){
                    //cout<<i<<' '<<u[i]<<endl;
                //memset(was,0,sizeof was);
                    bool t1=1,t2=1;
                    char e;
                    for(int j=0;j<='z'-'a';++j){
                        if(was[j] && is[i][j]){
                            if(t1){
                                e=j+'a';
                                t1=0;
                            }
                            else
                                t2=0;
                        }
                    }
                    bool pwas[27];
                    for(int j=0;j<='z'-'a';++j){
                        pwas[j]=was[j];
                        was[j]|=is[i][j];
                    }
                    if(t2&&(t1||(e==l && e==s[i][0]))){/*ans++;v.pb(i);/*for(int i=0;i<sz(v);++i)cout<<v[i]<<' ';cout<<endl;*/int t=1-u[i];u[i]=1;go(s[i][sz(s[i])-1],sz+t);u[i]=0;}
                    for(int j=0;j<='z'-'a';++j){
                        was[j]=pwas[j];
                    }

        }
    }
}


void solve(){

    int p[11];

    //int n;
    cin>>n;
    for(int i=1;i<=n;++i)can[i]=1;
    for(int i=1;i<=n;++i){
        cin>>s[i];
        p[i]=i;
        int last[27];
        for(int j=0;j<='z'-'a';++j)is[i][j]=0,last[j]=-1;
        for(int j=0;j<sz(s[i]);++j){
            if(last[s[i][j]-'a']!=-1){
                if(last[s[i][j]-'a']!=j-1){can[i]=0;}
            }
            last[s[i][j]-'a']=j;
            is[i][s[i][j]-'a']=1;
        }
        //cout<<i<<' '<<can[i]<<endl;
    }
    ans=0;
    for(int j=0;j<='z'-'a';++j)was[j]=0;
    for(int i=1;i<=n;++i)u[i]=0;
    go('-',0);
    cout<<ans;
}

int main(){
    freopen("in.txt","r",stdin);
    //freopen("seq1.out","w",stdout);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;++i){
        cout<<"Case #"<<i<<": ";solve();cout<<endl;
    }


    return 0;
}
