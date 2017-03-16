#include<set>
#include<cstdio>
using namespace std;
int n,m,l,a[11];
int len(int x){
    int cnt=0;
    while(x){
        ++cnt;
        x/=10;
    }
    return cnt;
}
int calc(int x){
    int xx=x;
    a[0]=0;
    while(x){
        a[++a[0]]=x%10;
        x/=10;
    }
    int ret=0;
    set<int> h;
    h.clear();
    for(int i=a[0];i;--i){
        int j=i,tmp=0;
        for(;;){
            tmp=tmp*10+a[j];
            --j;
            if(j==0)j=a[0];
            if(j==i)break;
        }
        if(tmp>xx&&tmp<=m&&h.find(tmp)==h.end()){++ret;h.insert(tmp);}
    }
    return ret;
}
int main(){
    freopen("3.in","r",stdin);
    freopen("3.out","w",stdout);
    int _,t=0;
    for(scanf("%d",&_);_--;){
        scanf("%d%d",&n,&m);
        l=len(n);
        int ans=0;
        for(int i=n;i<=m;++i)
            ans+=calc(i);
        printf("Case #%d: %d\n",++t,ans);
    }
    return 0;
}
