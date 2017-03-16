#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<fstream>
#define N 105
#define mod 1000000007
using namespace std;
int n,vis[N],v[N],num[N],ans;
char str[N][N];
int map[N][27],s[N],t[N];
bool judge(){
    memset(v,0,sizeof(v));
    int temp,tmp;
    temp=s[num[0]];
    v[s[num[0]]]=1;
    for(int i=0;i<n;i++){
        tmp=s[num[i]];
        if(tmp!=temp){
            if(v[tmp])
            return false;
            temp=tmp;
            v[tmp]=1;
        }
        tmp=t[num[i]];
        if(tmp!=temp){
            if(v[tmp])
            return false;
            temp=tmp;
            v[tmp]=1;
        }
    }
    return true;
}
int power(int x){
    if(x==0)
    return 1;
    long long ret=1;
    while(x--){
        ret>>=1;
        ret=ret%mod;
    }
    return ret;
}
void dfs(int x){
    if(x==n){
        if(judge())
        ans++;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i]=1;
            num[x]=i;
            dfs(x+1);
            vis[i]=0;

        }
    }
}
int main()
{
    int ics=0,T,flag,tmp,temp,l,r,L;
    //freopen("B-small-attempt2.in","r",stdin);
  //  freopen("B-small-attempt2.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        ans=0;
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        memset(map,0,sizeof(map));
        flag=1;
        for(int i=0;i<n;i++){
            scanf("%s",str[i]);
            L=strlen(str[i]);
            s[i]=str[i][0]-'a';
            for(l=1;l<L;l++)
            if(str[i][l]-'a'!=s[i])
            break;

            t[i]=str[i][L-1]-'a';
            for(r=L-2;r>=0;r--)
            if(str[i][r]-'a'!=t[i])
            break;
            temp=-1;
            vis[s[i]]=1;
            vis[t[i]]=1;
            for(int j=l;j<=r;j++){
                tmp=str[i][j]-'a';
                if(tmp==temp)
                continue;
                if(vis[tmp]){
                    flag=0;
                    break;
                }
                temp=tmp;
                vis[tmp]=1;
            }
        }

        printf("Case #%d: ",++ics);
        if(!flag){
            printf("0\n");
            continue;
        }
        memset(vis,0,sizeof(vis));
        dfs(0);
        printf("%d\n",ans);
        /*
        memset(vis,-1,sizeof(vis));
        sum=n;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j&&vis[j]==-1){
                    if(t[i]==s[j]&&vis[i]!=j){
                        vis[j]=i;
                        s[j]=-1;
                        sum--;
                        break;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<s[i]<<' '<<t[i]<<' ';
            for(int j=0;j<26;j++)
            cout<<map[i][j];
            cout<<endl;
        }
        flag=1;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            if(s[i]!=-1){
                if(vis[s[i]]){
                    flag=0;
                    break;
                }else {
                    vis[s[i]]=1;
                }
            }
            for(int j=0;j<26;j++){
                if(map[i][j]){
                    if(!vis[j])
                    vis[j]=1;
                    else {
                        flag=0;
                        break;
                    }
                }
            }
            if(!flag)
            break;
        }
        cout<<flag<<' '<<sum<<endl;
        if(flag){
            printf("%d\n",power(sum-1));
        }else {
            printf("0\n");
        }*/
    }

    return 0;
}
