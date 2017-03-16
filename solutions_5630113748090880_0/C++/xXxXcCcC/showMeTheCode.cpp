#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pr;

int cnt[2501];

void solve(){
    int n,x;
    scanf("%d",&n);
    memset(cnt,0,sizeof(cnt));
    for (int i=1;i<=n*(n*2-1);i++){
        scanf("%d",&x);
        cnt[x]++;
    }
    vector<int>v;
    for (int i=1;i<=2500;i++){
        if (cnt[i]&1) v.push_back(i);
    }
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();i++){
        printf(" %d",v[i]);
    }
    printf("\n");
}

int main(){
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int T;
    scanf("%d",&T);
    for (int kase=1;kase<=T;kase++){
        printf("Case #%d:",kase);
        solve();
    }
    return 0;
}
