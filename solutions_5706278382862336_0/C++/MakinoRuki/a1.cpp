#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
int T;
ll P,Q;
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>T;
    for(int cas=1;cas<=T;++cas){
            scanf("%I64d/%I64d",&P,&Q);
            printf("Case #%d: ",cas);
            ll QQ = Q;
            while(QQ%2LL==0){
                QQ/=2LL;
            }
            if(QQ>1){
                printf("impossible\n");
                continue;     
            }
            //ll ans = (ll)ceil(log((double)Q/(double)P));
            ll ans;
            for(ans=1LL;ans<=40;++ans){
                 if(P*2LL >= Q)
                          break;
                 P*=2LL;
            }
            if(ans>40)
                      printf("impossible\n");
            else printf("%I64d\n",ans);
    }
    return 0;
}
