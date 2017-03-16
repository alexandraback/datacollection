

#include <cstdio>

typedef long long ll ;

int T ;

int main()
{
    scanf("%d", &T) ;
    for(int time = 1 ; time <= T ; time++){
        ll r, t ;
        scanf("%lld%lld", &r, &t) ;
        ll ans = 0 ;
        ll i = 0 ;
        while(t > 0){
            t -= (2*r)+(i+1)*(i+1)-i*i ;
            if(t < 0)   break ;
            i += 2 ;
            ans++ ;
        }
        printf("Case #%d: ", time) ;
        printf("%lld\n", ans) ;
    }
    return 0 ;
}



