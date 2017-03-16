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

int T,x,n,g[3000];

int main(){
//freopen("B.in","r",stdin);
//freopen("B.out","w",stdout);
    cin>>T;
    rep(ca,1,T){
        cin>>n;
        For(i,2600) g[i]=0;
        For(i,(2*n-1)*n){
            cin>>x;
            g[x]=1-g[x];
        }
        cout<<"Case #"<<ca<<":";
        For(i,2600) if (g[i]) cout<<" "<<i;
        cout<<endl;
    }
}