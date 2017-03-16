#include <bits/stdc++.h>
using namespace std;
int run(int n,char *s){
    int ans=0,cnt=0;
    for(int i=0;i<=n;++i){
        int k=s[i]^0x30;
        if(k){
            ans+=max(i-ans-cnt,0);
            cnt+=k;
        }
    }
    return ans;
}
int main(){
    freopen("E:\\in.txt","r",stdin);
    freopen("E:\\out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int T,n;
    static char s[11111];
    cin>>T;
    for(int cas=1;cas<=T;++cas){
        cout<<"Case #"<<cas<<": ";
        cin>>n>>s;
        cout<<run(n,s)<<endl;
    }
    return 0;
}

