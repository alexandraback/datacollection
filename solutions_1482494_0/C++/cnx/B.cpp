#include<set>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mp make_pair
using namespace std;

int n,a[1001],b[1001];
set< pair<pair<int,int>,int> > one,two,noway;

int main(){
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int _,cas=0;
    for(scanf("%d",&_);_--;){
        scanf("%d",&n);
        one.clear();
        two.clear();
        noway.clear();
        for(int i=1;i<=n;++i){
            scanf("%d%d",a+i,b+i);
            one.insert(mp(mp(a[i],-b[i]),i));
            two.insert(mp(mp(b[i],a[i]),i));
        }
        int tot=0,ans=0;
        for(;one.size()||two.size()||noway.size();){
            bool ok=0;
            for(;;){
                if(!two.size())break;
                pair<pair<int,int>,int> now=*two.begin();
                if(tot>=now.first.first){
                    tot+=2;ok=1;++ans;
                    two.erase(two.begin());
                    one.erase(mp(mp(now.first.second,-now.first.first),now.second));
                }
                break;
            }
            if(ok)continue;
            for(;;){
                if(!noway.size())break;
                pair<pair<int,int>,int> now=*noway.begin();
                if(tot>=now.first.first){
                    tot+=1;ok=1;++ans;
                    noway.erase(noway.begin());
                }
                break;
            }
            if(ok)continue;
            for(;;){
                if(!one.size())break;
                pair<pair<int,int>,int> now=*one.begin();
                if(tot>=now.first.first){
                    tot+=1;ok=1;++ans;
                    noway.insert(mp(mp(-now.first.second,now.first.first),now.second));
                    one.erase(one.begin());
                    two.erase(mp(mp(-now.first.second,now.first.first),now.second));
                }
                break;
            }
            if(!ok)break;
        }
        if(one.size()||two.size()||noway.size())
            printf("Case #%d: Too Bad\n",++cas);
        else
            printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
