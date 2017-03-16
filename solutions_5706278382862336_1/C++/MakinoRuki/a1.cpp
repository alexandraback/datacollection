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
ll gcd(ll X, ll Y){
   if(Y==0LL)return X;
   return gcd(Y, X%Y);
}
int main(){
    freopen("A-large.in","r",stdin);
  // freopen("A-small-attempt0.in","r",stdin);
    freopen("out2.txt","w",stdout);
    cin>>T;
    for(int cas=1;cas<=T;++cas){
            scanf("%I64d/%I64d",&P,&Q);
            printf("Case #%d: ",cas);
            ll d = gcd(P, Q);
            P/=d;
            Q/=d;
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
                 if(Q/2LL <= P)
                        break;
                 Q/=2LL;
            }
            if(ans>40)
                      printf("impossible\n");
            else printf("%I64d\n",ans);
    }
    return 0;
}
