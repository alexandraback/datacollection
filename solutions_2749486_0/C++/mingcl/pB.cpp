
#include <cstdio>
#include <cstdlib>

int main()
{
    int T ;
    scanf("%d", &T) ;
    for(int time = 1 ; time <= T ; time++){
        printf("Case #%d: ", time) ;
        int x, y ;
        scanf("%d%d", &x, &y) ;
        if(x < 0){
            x = -x ;
            for(int i = 0 ; i != x ; i++)
                printf("EW") ;
        }
        else{
            for(int i = 0 ; i != x ; i++)
                printf("WE") ;
        }
        if(y < 0){
            y = -y ;
            for(int i = 0 ; i != y ; i++)
                printf("NS") ; ;
        }
        else{
            for(int i = 0 ; i != y ; i++)
                printf("SN") ;
        }
        puts("") ;
    }
    return 0 ;
}





