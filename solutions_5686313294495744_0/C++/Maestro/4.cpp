#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define y0 qweasd
#define y1 qasdna
#define left leva
#define right prava
#define next sled
using namespace std;
const int N=3055;
const int inf=9e18;
int n,ans;
string x[N],y[N];
set<string> q,w;
main(){
   // cin.tie(0);
   // ios_base::sync_with_stdio(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
   int test;
   cin>>test;
   for(int z=1;z<=test;++z){
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>x[i]>>y[i];
        }
        ans=0;
        for(int mask=0;mask<(1<<(n));++mask){
               // cout<<mask<<endl;
            q.clear();w.clear();
            int ok=1;
            for(int i=1;i<=n;++i){
                if(!(1<<(i-1)&mask)){
                    q.insert(x[i]);
                    w.insert(y[i]);
                }
            }
        for(int i=1;i<=n;++i){
                if((1<<(i-1)&mask)){
                    if(!q.count(x[i])||!w.count(y[i]))ok=0;
                   // else {
                      //  cout<<i<<' '<<mask<<' '<<q.count(x[i])<<' '<<w.count(y[i])<<' '<<x[i]<<' '<<y[i]<<endl;
                   // }
                }
            }
    //    cout<<mask<<' '<<ok<<endl;
         if(ok)ans=max(ans,__builtin_popcount(mask));
        }
     cout<<"Case #"<<z<<": ";
        cout<<ans;

     cout<<endl;
   }



}

