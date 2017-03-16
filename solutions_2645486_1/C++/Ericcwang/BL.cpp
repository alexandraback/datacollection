#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
typedef long long LL;
const int inf=1000000000;//1e9
const int N = 10009;
int a[N];
int main(){
    int T;
    freopen("B-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for (int t=1;t<=T;t++){
        LL e,r,n;
        cin>>e>>r>>n;
        for (int i=0;i<n;i++) cin>>a[i];
        if (r>=e){
            LL ans=0;
            for (int i=0;i<n;i++) ans+=1LL*e*a[i];
            cout<<"Case #"<<t<<": "<<ans<<endl;
            continue;
        }
        vector< pair<int,int> > g;
        for (int i=0;i<n;i++)
            g.push_back(make_pair(a[i],i));
        sort(g.begin(),g.end());
        reverse(g.begin(),g.end());
        LL before[N],after[N],v[N];
        memset(before,-1,sizeof before);
        memset(after,-1,sizeof after);
        memset(v,0,sizeof v);
        LL ans=0;
        for (int i=0;i<n;i++){
            int x=g[i].second;
            int j;
            for (j=x-1;j>=0;j--) if (after[j]!=-1) break;
            if (j>=0){
                before[x]=min(e,after[j]+(x-j)*r);
            }else before[x]=e;
            for (j=x+1;j<n;j++) if (before[j]!=-1) break;
            if (j<n){
                after[x]=max(0LL,before[j]-(j-x)*r);
            }else after[x]=0;
            v[x]=(before[x]-after[x])*a[x];

            ans+=v[x];
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
}
