
#include <cstdio>
#include <cstring>

int cnt[10] ;

int R, N, M, K ;

void mk(int t){
    for(int i = M ; i >= 2 ; i--){
        if(t == 1)  return ;
        while(t % i == 0){
            t /= i ;
            cnt[i]++ ;
        }
    }
}

int main()
{
    scanf("%*d") ;
    puts("Case #1:") ;
    scanf("%d%d%d%d", &R, &N, &M, &K) ;
    for(int i = 0 ; i != R ; i++){
        memset(cnt, 0, sizeof(cnt)) ;
        for(int j = 0 ; j != K ; j++){
            int t ;
            scanf("%d", &t) ;
            mk(t) ;
        }
        int ans = N ;
        for(int j = M ; j >= 0 ; j--){
            if(cnt[j]){
                putchar('0'+j) ;
                cnt[j]-- ;
                ans-- ;
            }
        }
        while(ans--){
            int maxv = 2, v = -1 ;
            for(int j = M ; j >= 2 ; j--){
                if(cnt[j] > v){
                    v = cnt[j] ;
                    maxv = j ;
                }
            }
            cnt[maxv]-- ;
            putchar('0'+maxv) ;
        }
        puts("") ;
    }
    return 0 ;
}


