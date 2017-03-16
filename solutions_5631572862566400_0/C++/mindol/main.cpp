#include<cstdio>
#include<algorithm>
int n,f[11],ans,start;
bool check[11];
void bc(int cnt,int bef,bool fin) {
    if(cnt==0) {
        for(int i=1;i<=n;i++) {
            check[i]=true;
            start=i;
            bc(cnt+1,i,false);
            check[i]=false;
        }
    }
    else {
        if(fin || f[bef]==start) ans=std::max(ans,cnt);
        for(int i=1;i<=n;i++) {
            if(check[i]) continue;
            if(fin || f[bef]==i) {
                check[i]=true;
                bc(cnt+1,i,f[i]==bef);
                check[i]=false;
            }
        }
    }
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for(int mindol=1;mindol<=tc;mindol++) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&f[i]);
        ans=0;
        bc(0,-1,false);
        printf("Case #%d: %d\n",mindol,ans);
    }
    return 0;
}
