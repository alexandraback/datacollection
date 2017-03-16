#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<fstream>
#define LL long long
using namespace std;
LL gcd(LL x,LL y){
    if(x%y==0)
    return y;
    return gcd(y,x%y);
}
int main()
{
    LL ics=0,cnt,flag;
    //freopen("A-large.in","r",stdin);
  // freopen("A-large.out","w",stdout);
    LL T,x,y,g;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld/%lld",&x,&y);
        g=gcd(x,y);
        x/=g;
        y/=g;
        cnt=0;
        while(x<y){
            cnt++;
            if(y%2==0)
            y>>=1;
            else
            x<<=1;
            if(cnt>40)
            break;
        }
        flag=1;
        while(y>1){
            if(y&1){
                flag=0;
                break;
            }
            y>>=1;
        }
        printf("Case #%lld: ",++ics);
        if(!flag||cnt>40){
            printf("impossible\n");
        }else {
            printf("%lld\n",cnt);
        }
    }

    return 0;
}
