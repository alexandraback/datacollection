#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pr;

void solve(){
    int K,C,S;
    scanf("%d%d%d",&K,&C,&S);
    if (S*C<K){
        printf("IMPOSSIBLE\n");
        return ;
    }
    vector<ll>ans; int t=0;
    for (int i=0;i<S;i++){
        ll num=0;
        for (int j=0;j<C;j++){
            num*=K;
            num+=t;
            t=(t+1)%K;
        }
        ans.push_back(num);
    }
    for (int i=0;i<S-1;i++){
        cout<<ans[i]+1ll<<" ";
    }
    cout<<ans[S-1]+1ll<<endl;
}

int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int T;
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++){
        printf("Case #%d: ",kase);
        solve();
    }
    return 0;
}
