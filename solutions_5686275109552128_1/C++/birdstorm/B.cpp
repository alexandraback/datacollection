#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
int cnt[MAXN];
int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int t; cin>>t;
    for(int cs=1; cs<=t; cs++){
        int n, x; cin>>n;
        memset(cnt,0,sizeof cnt);
        for(int i=0; i<n; i++){
            scanf("%d",&x);
            cnt[x]++;
        }
        int ans=0x3f3f3f3f;
        for(int i=1; i<MAXN; i++){
            int ret=0;
            for(int j=i+1; j<MAXN; j++) if(cnt[j]){
                ret+=(j-1)/i*cnt[j];
            }
            ans=min(ans,i+ret);
        }
        printf("Case #%d: %d\n",cs,ans);
    }
    return 0;
}

