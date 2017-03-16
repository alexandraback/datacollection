#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pr;

const int maxn = 100005;

void solve(){
    int K,C,S;
    scanf("%d%d%d",&K,&C,&S);
    for (int i=1;i<S;i++){
        printf("%d ",i);
    }
    printf("%d\n",S);
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
