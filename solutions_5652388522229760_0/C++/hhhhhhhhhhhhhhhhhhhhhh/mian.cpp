#include<bits/stdc++.h>
using namespace std;

const int N=1001000;
long long ans[N];
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    ans[0]=-1;
    for(int i=1;i<=1000000;i++){
        bool vis[10];
        memset(vis,0,sizeof(vis));
        int cc=0;
        for(long long j=i;;j+=i){
            long long tmp=j;
            while(tmp){
                if(!vis[tmp%10])cc++;
                vis[tmp%10]=true;
                tmp/=10;
            }
            ans[i]++;
            if(10==cc)break;
        }
    }
    int test;
    scanf("%d",&test);
    for(int _=1;_<=test;_++){
        int x;
        scanf("%d",&x);
        printf("Case #%d: ",_);
        if(-1==ans[x])puts("INSOMNIA");
        else printf("%d\n",1LL*ans[x]*x);
    }
}
