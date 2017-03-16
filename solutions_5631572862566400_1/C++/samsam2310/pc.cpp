#include <bits/stdc++.h>
#define F(n) Fi(i,n)
#define Fi(i,n) Fl(i,0,n)
#define Fl(i,l,n) for(int i=l;i<n;i++)
using namespace std;
const int N = 1001;
bool wed[N], in[N];
int Fa[N],ans,sum,DR[N],JZMX[N];
void DFS(int now, int dr = 1){
    // cout<<"DD "<<now<<' '<<dr<<endl;
    DR[now] = dr;
    wed[now] = 1;
    if(Fa[Fa[now]] == now){
        JZMX[now] = max(JZMX[now],dr);
        wed[now] = 0;
        return;
    }
    if(wed[Fa[now]])ans = max(ans, dr-DR[Fa[now]]+1);
    else DFS(Fa[now],dr+1);
    wed[now] = 0;
}
main(){
    ios_base::sync_with_stdio(false);
    int t,n;
    cin>>t;
    Fl(_,1,t+1){
        cin>>n;
        ans = 0, sum = 0;
        memset(wed,0,sizeof(wed));
        memset(in,0,sizeof(in));
        memset(JZMX,0,sizeof(JZMX));
        F(n){
            cin>>Fa[i];
            Fa[i]--;
            // in[Fa[i]] = 1;
        }
        F(n)DFS(i);
        // F(n)if(!wed[i])DFS(i);
        // F(n)cout<<JZMX[i]<<' '<<endl;
        F(n)sum += JZMX[i];
        // cout<<"JIZ"<<' '<<ans<<' '<<sum<<endl;
        cout<<"Case #"<<_<<": "<<max(ans,sum)<<endl;
    }
}