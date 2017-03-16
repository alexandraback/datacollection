#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

struct node{
    int c,id;
}a[1500],b[1500];
int na[1500],nb[1500];
int cmp(node a,node b){
    return a.c<b.c;
}
bool vis[1005][2];

int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int cas,c;
    int n,i,pa,pb;
    int ans,sco;
    scanf("%d",&cas);
    for(c=1;c<=cas;c++){
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%d",&a[i].c,&b[i].c);
            na[i]=a[i].c;
            nb[i]=b[i].c;
            a[i].id=b[i].id=i;
        }
        sort(a,a+n,cmp);
        sort(b,b+n,cmp);
        pa=pb=0;
        ans=sco=0;
        while(1){
            while(pb<n&&b[pb].c<=sco){
                if(vis[b[pb].id][0])
                    sco++;
                else
                    sco+=2;
                ans++;
                vis[b[pb].id][1]=1;
                pb++;
            }
            if(pb==n)
                break;
            int t=-1,tm=0;
            for(pa=0;pa<n;pa++){
                if(a[pa].c>sco)
                    continue;
                if(vis[a[pa].id][0]||vis[a[pa].id][1])
                    continue;
                if(nb[a[pa].id]>=tm){
                    tm=nb[a[pa].id];
                    t=pa;
                }
            }
            if(t==-1)
                break;
            sco++;
            ans++;
            vis[t][0]=1;
        }
        if(pb==n)
            printf("Case #%d: %d\n",c,ans);
        else
            printf("Case #%d: Too Bad\n",c);
    }
    return 0;
}
