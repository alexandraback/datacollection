
#include <cstdio>
#include <cstring>
#include <cmath>

int K, L, S ;
char kstr[11], lstr[11] ;

char sle[11] ;

int check(){ // check sle banana
    int rtn = 0 ;
    for(int i = 0 ; i <= S-L ; i++){
        if(!strncmp(sle+i, lstr, L))
            rtn++ ;
    }
    return rtn ;
}

int perm(int now){
    if(now == S){
        return check() ;
    }
    int rtn = 0 ;
    for(int i = 0 ; i != K ; i++){
        sle[now] = kstr[i] ;
        rtn += perm(now+1) ;
    }
    return rtn ; 
}

int main()
{
    int T ;
    scanf("%d", &T) ;
    for(int time = 1 ; time <= T ; time++){
        printf("Case #%d: ", time) ;
        scanf("%d%d%d", &K, &L, &S) ;
        scanf("%s%s", kstr, lstr) ;
        //printf("%d\n", perm(0)) ;
        char app[33] = {0} ;
        int banana = -1 ;
        for(int i = 0 ; i != K ; i++)
            app[kstr[i]-'A'] = true ;
        for(int i = 0 ; i != L ; i++)
            if(!app[lstr[i]-'A']){
                banana = 0 ;
                break ;
            }
        if(!banana){
            printf("0.0\n") ;
            continue ;
        }
        int lap = 0 ;
        for(int i = 1 ; i != L ; i++){
            if(!strncmp(lstr+i, lstr, L-i)){
                lap = L-i ;
                break ;
            }
        }
        banana = (S-L)/(L-lap) + 1 ; 
        //printf("banana = %d\n", banana) ;
        printf("%lf\n", (double)banana - ((double)perm(0)/pow((double)K, (double)S))) ;
    }
}


