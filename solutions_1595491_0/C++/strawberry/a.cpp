#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int cas;
    scanf("%d",&cas);
    int t,s,p,n,i;
    int ans,tmp,div,mod;
    for(int c=1;c<=cas;c++){
        scanf("%d%d%d",&t,&s,&p);
        ans=tmp=0;
        for(i=0;i<t;i++){
            scanf("%d",&n);
            div=n/3;
            if(div>=p){
                ans++;
                continue;
            }
            mod=n%3;
            if(mod==0&&div+1==p&&div-1>=0)
                tmp++;
            if(mod==1&&div+1==p)
                ans++;
            if(mod==2&&div+1==p)
                ans++;
            if(mod==2&&div+2==p)
                tmp++;
        }
        ans+=min(tmp,s);
        printf("Case #%d: %d\n",c,ans);
    }
    return 0;
}

