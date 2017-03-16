#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<cmath>
#include<bitset>
#define rep(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define per(i,a,b) for(int i=a,_b=b;i>=_b;i--)
#define For(i,b) for(int i=0,_b=b;i<_b;i++)
#define upmax(a,b) if ((a)<(b)) (a)=(b)
#define upmin(a,b) if ((a)>(b)) (a)=(b)
using namespace std;
typedef long long ll;

int T,n,f[1000];
ll m,mx[1000];

int main(){
//freopen("B.in","r",stdin);
//freopen("B.out","w",stdout);
    mx[1]=1; mx[2]=1;
    rep(i,3,50) rep(j,1,i-1) mx[i]+=mx[j];
    cin>>T;
    rep(ca,1,T){
        cin>>n>>m;
        cout<<"Case #"<<ca<<": ";
        if (m>mx[n]){
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        cout<<"POSSIBLE"<<endl;
        rep(i,1,n) f[i]=0;
        per(i,n-1,1) if (mx[i]<=m){
            m-=mx[i];
            f[i]=1;
        }
        rep(i,1,n-1){
            rep(j,1,i)cout<<0;
            rep(j,i+1,n-1)cout<<1;
            cout<<f[i]<<endl;
        }
        rep(i,1,n) cout<<0;cout<<endl;
    }
}