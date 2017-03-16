#include<cstdio>
#include<algorithm>
using namespace std;

int n,s,p;

int main(){
    freopen("2.in","r",stdin);
    freopen("2.out","w",stdout);
    int _,t=0;
    for(scanf("%d",&_);_--;){
        scanf("%d%d%d",&n,&s,&p);
        int ans=0;
        for(int i=1;i<=n;++i){
            int x;
            scanf("%d",&x);
            if(p+p+p<=x)++ans;
            else if(p>=1&&p+p+p-2<=x)++ans;
            else if(p>=2&&p+p+p-4<=x&&s)++ans,--s;
        }
        printf("Case #%d: %d\n",++t,ans);
    }
    return 0;
}
