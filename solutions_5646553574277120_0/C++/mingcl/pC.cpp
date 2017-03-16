
#include <cstdio>
#include <cstring>

int dolls[111] ;
bool sle[11] ;
int exist[333333] ;
int C, D, V ;

void check(){
    int sum = 0 ;
    for(int i = 0 ; i != D ; i++)
        if(sle[i])
            sum += dolls[i] ;
    exist[sum] = true ;
}

void perm(int now){
    if(now == D){
        check() ;
        return ;
    }
    sle[now] = 0 ;
    perm(now+1) ;
    sle[now] = 1 ;
    perm(now+1) ;
}

int main()
{
    int T ;
    scanf("%d", &T) ;
    for(int time = 1 ; time <= T ; time++){
        printf("Case #%d: ", time) ;
        scanf("%d%d%d", &C, &D, &V) ;
        for(int i = 0 ; i != D ; i++)
            scanf("%d", dolls+i) ;
        memset(exist, 0, sizeof(exist)) ;
        perm(0) ;
        int ans = 0 ;
        bool cont ;
        do{
            cont = false ;
            memset(exist, 0, sizeof(exist)) ;
            perm(0) ;
            for(int i = 1 ; i <= V ; i++)
                if(!exist[i]){
                    dolls[D++] = i ;
                    ans++ ;
                    cont = true ;
                    break ;
                }
        }while(cont) ;
        printf("%d\n", ans) ;
    }
    return 0 ;
}
