#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define maxn 100700
#define eps 1e-7
using namespace std;

#ifdef __int64
    typedef __int64 LL;
#else
    typedef long long LL;
#endif

int main(){
    freopen("A-large (2).in","r",stdin);
    freopen("output.txt","w",stdout);
    int _,cas=1;
    scanf("%d",&_);
    LL p,q;
    while(_--){
        scanf("%lld/%lld",&p,&q);
        LL tmp = __gcd(p,q);
        p/=tmp;
        q/=tmp;
        LL qq=q;
        bool ok=true;
        int cnt=0;
        while(q!=1){
            if(q&1){ok=false;break;}
            q>>=1;
        }
        printf("Case #%d: ",cas++);
        q=qq;
        while(q!=1){
            if(p*2>=q)break;
            q>>=1;
            cnt++;
        }
        cnt++;
        if(!ok||cnt>40){
            puts("impossible");
        }else{
            printf("%d\n",cnt);
        }

    }
    return 0;
}
