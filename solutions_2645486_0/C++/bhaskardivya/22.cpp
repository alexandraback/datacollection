#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
int main() {
    int t,e,r,n;
    int ans[11][5],v[10];
    cin>>t;
    for(int i=0; i<5; i++) {
        ans[0][i]= 0;
    }
    for (int i = 1; i <= t; i++) {
        cin>>e>>r>>n;
        for(int j=1; j<=n; j++) {
            cin>>v[j-1];
            for(int k=0; k<=e-r; k++) {
                ans[j][k]=0;
                int l=0;
                if(k>r)
                    l=k-r;
                for(; l<=e-r; l++) {
                    if(ans[j-1][l]+v[j-1]*(l+r-k)>ans[j][k])
                        ans[j][k]=ans[j-1][l]+v[j-1]*(l+r-k);
                }
            }
        }

        cout<<"Case #"<<i<<": "<<ans[n][0]<<endl;
    }
    return 0;
}
