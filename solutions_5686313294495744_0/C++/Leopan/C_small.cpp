#include<bits/stdc++.h>
using namespace std;
set<string>sa,sb;
string a[20],b[20];
int n,ans;
bool s[20];
bool check(){
    sa.clear(),sb.clear();
    bool f=1;
    for(int i=0;i<n;i++){
        if(s[i]==0){
            sa.insert(a[i]);
            sb.insert(b[i]);
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]==1&&(sa.count(a[i])==0||sb.count(b[i])==0))return 0;
    }
    return 1;
}
void dfs(int now,int cnt){
    if(now==n){
        if(check()&&cnt>ans)ans=cnt;
        return;
    }
    s[now]=1;
    dfs(now+1,cnt+1);

    s[now]=0;
    dfs(now+1,cnt);
}
int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int T,Case=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)cin>>a[i]>>b[i];
        ans=0;
        dfs(0,0);
        printf("Case #%d: %d\n",++Case,ans);
    }
    return 0;
}
