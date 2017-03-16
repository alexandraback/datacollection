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
int a[10009];
int f[100][100];
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    for (int t=1;t<=T;t++){
        int e,r,n;
        cin>>e>>r>>n;
        for (int i=0;i<n;i++) cin>>a[i];
        memset(f,-1,sizeof f);
        f[0][e]=0;
        for (int i=0;i<n-1;i++){
            for (int j=0;j<=e;j++){
                if (f[i][j]==-1) continue;
               // cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
                for (int k=0;k<=j;k++){
                    int tmp=a[i]*k;
                    f[i+1][min(e,j-k+r)]=max(f[i+1][min(e,j-k+r)],f[i][j]+tmp);
                }
            }
        }
        int ans=-1;
        for (int i=0;i<=e;i++)
            if (f[n-1][i]!=-1)
            ans=max(ans,f[n-1][i]+i*a[n-1]);
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
}
