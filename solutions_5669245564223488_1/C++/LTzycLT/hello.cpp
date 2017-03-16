#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<string>
#include<set>
#include<queue>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define forn(i,n) for(int i=0;i<n;i++)
#define sqr(x) ((x)*(x))
#define MAX(a,b) if(a<b) a=b;
#define ll long long
using namespace std;

ll mod=1000000007;
ll l[300],r[300],all[300],in[300],x[300];
ll num[300];
bool vis[300];
int n;
char s[1000];

int main() {
    freopen("/home/zyc/Downloads/in","r",stdin);
    freopen("/home/zyc/Downloads/out","w",stdout);
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    int T,cas=0;
    x[0]=1;
    for(int i=1;i<=100;i++) x[i]=x[i-1]*i%mod;
    scanf("%d",&T);
    while(T--){
        bool flag=true;
        clr(l,0);
        clr(r,0);
        clr(in,0);
        clr(all,0);
        clr(vis,0);
        clr(num,0);
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",s);
            int len=strlen(s);
            for(int j=0;j<len;){
                int start=j;
                char ch=s[j++];
                while(j<len&&s[j]==ch) j++;
                int end=j-1;

                if(start==0&&end==len-1) all[ch]++;
                else if(start==0){
                    if(l[ch]!=0) flag=false;
                    else l[ch]=s[len-1];
                }else if(end==len-1){
                    if(r[ch]!=0) flag=false;
                    else r[ch]=s[0];
                }else{
                    in[ch]++;
                }
            }
        }
        for(int i='a';i<='z';i++){
            if(in[i]>1)
                flag=false;
            if(in[i]==1&&(l[i]||r[i]||all[i]))
                flag=false;
            num[i] = x[all[i]];
        }
        printf("Case #%d: ",++cas);
        int p=0;
        if(flag){
            for(int i='a';i<='z';i++){
                char ch = i;
                if(in[i]) continue;
                if(!l[i]&&!r[i]&&!all[i]) continue;
                if(vis[i]) continue;
                vis[ch]=1;
                while(ch){
                    ch=r[ch];
                    if(ch!=0 && vis[ch]){
                        flag=false;
                        break;
                    }
                    vis[ch]=1;
                }
                ch=i;
                while(ch){
                    ch=l[ch];
                    if(ch!=0 && vis[ch]){
                        flag=false;
                        break;
                    }
                    vis[ch]=1;
                }
                p++;
            }
        }
        if(flag){
            ll ans=1;
            for(int i=2;i<=p;i++) ans=ans*i%mod;
            for(int i='a';i<='z';i++) ans=ans*num[i]%mod;
            printf("%lld\n",ans);
        }else{
            puts("0");
        }
    }
    return 0;
}

