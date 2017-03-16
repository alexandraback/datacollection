#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#define ll long long
#define db double
using namespace std;

int t,n,m,k;

char s[100];
char c[100];
int cnt[30];
char p[10];
int res,ma,ans;

void dfs(int x){
    if(x>=k){
        int ret=0;
        int pi=0,pj=0,pp=0;
        while(pp<k&&pi<k){
            if(p[pi]==c[pj]){
                if(pj==m-1){
                    pi=++pp;
                    pj=0;
                    ret++;
                }
                else{
                    pi++;
                    pj++;
                }
            }
            else{
                pi=++pp;
                pj=0;
            }
        }
        ma=max(ma,ret);
        ans+=ret*res;
        return;
    }
    for(int i=0;i<26;i++){
        if(cnt[i]){
            p[x]=char(i+'A');
            res*=cnt[i];
            dfs(x+1);
            res/=cnt[i];
        }
    }
}

int main()
{
#ifdef Haha
    freopen("B-small-attempt3.in", "r", stdin);
    freopen("A-small-attempt0.out","w",stdout);
#endif // Haha
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++){
        memset(cnt,0,sizeof(cnt));
        scanf("%d%d%d",&n,&m,&k);
        scanf("%s",s);
        scanf("%s",c);
        for(int i=0;i<n;i++) cnt[s[i]-'A']++;
        int flag=0;
        for(int i=0;i<m;i++){
            if(cnt[c[i]-'A']==0){
                flag=1;
                break;
            }
        }
        if(flag){
            printf("Case #%d: 0\n",cas);
            continue;
        }
        res=1,ma=0,ans=0;
        dfs(0);
        int q=1;
        for(int i=0;i<k;i++) q*=n;
        printf("Case #%d: %.10f\n",cas,ma*1.0-ans*1.0/q);
    }
    return 0;
}
