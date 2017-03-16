#include <bits/stdc++.h>
using namespace std;
int vis[2505];
int main() {
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,cas=1,n,a;
    cin>>t;
    while(t--){
        cin>>n;
        memset(vis,0,sizeof vis);
        for(int i=0;i<n*2-1;i++)
            for(int j=0;j<n;j++){
                cin>>a;
                vis[a]++;
            }
        printf("Case #%d:",cas++);
        for(int i=1;i<=2500;i++)
            if(vis[i]&1)
                printf(" %d",i);
        puts("");
    }
	return 0;
}
