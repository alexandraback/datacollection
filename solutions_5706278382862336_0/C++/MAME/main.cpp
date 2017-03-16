#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

typedef long long ll;

ll gcd(ll x, ll y)
{
    if(y == 0)
    {
        return x;
    }
        else
    {
        return gcd(y, x%y);
    }
}

int main(void){

    int T;
    scanf("%d",&T);

    for(int r = 0;r < T;++r){
        bool solved = false;
        int ans = 0;
        ll p,q;
        scanf("%lld/%lld\n",&p,&q);
        ll g = gcd(p,q);
        q = q/g;
        if((q&(q-1))==0){
            ll f = 1;
            while(p>1){
                f <<= 1;
                p >>= 1;
            }
            q /= f;
            while(q>1){
                q>>=1;
                ++ans;
            }
            solved = true;
        }
ANS:
        printf("Case #%d: ",r+1);
        if(solved){
            printf("%d",ans);
        }else{
            printf("impossible");
        }
        printf("\n");
    }

}
