#include <bits/stdc++.h>
using namespace std;
vector<int>v[26];
char s[1010];
int vis[1010];
int ans[1010];
int main() {
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,cas=1;
    cin>>t;
    while(t--){
        printf("Case #%d: ",cas++);
        cin>>s;
        memset(vis,0,sizeof vis);
        for(int i=0;i<26;i++)
            v[i].clear();
        int n=strlen(s);
        for(int i=0;i<n;i++)
            v[s[i]-'A'].push_back(i);
        int cnt=0;
        int mn=n+1;
        int flag=1;
        for(int i=25;i>=0&&flag;i--){
            for(int j=v[i].size()-1;j>=0&&flag;j--){
                if(!v[i][j]){
                    flag=0;
                    break;
                }
                if(v[i][j]>mn)
                    continue;
                ans[cnt++]=v[i][j];
                mn=v[i][j];
                vis[v[i][j]]=1;
            }
        }
        for(int i=0;i<n;i++)
            if(!vis[i])
                ans[cnt++]=i;
        for(int i=0;i<n;i++)
            printf("%c",s[ans[i]]);
        puts("");
    }
	return 0;
}
