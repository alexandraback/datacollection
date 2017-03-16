
#include <cstdio>
#include <cstring>

char map[6][6] ;

int main()
{
    int T ;
    scanf("%d", &T) ;
    for(int time = 1 ; time <= T ; time++){
        int now = 0 ;
        do{
            scanf("%s", map[now]) ;
            if(strlen(map[now]) < 3)    continue ;
            now++ ;
        }while(now !=4) ;
        int cntdot = 0 ;
        bool owin = false, xwin = false ;
        for(int i = 0 ; i != 4 ; i++){
            int cnto = 0, cntx = 0, cntt = 0 ;
            for(int j = 0 ; j != 4 ; j++){
                if(map[i][j] == 'O')
                    cnto++ ;
                else if(map[i][j] == 'X')
                    cntx++ ;
                else if(map[i][j] == 'T'){
                    cntt++ ;
                }
                else
                    cntdot++ ;
            }
            if(cnto == 4 || cnto == 3 && cntt == 1){
                owin = true ;
            }
            if(cntx == 4 || cntx == 3 && cntt == 1){
                xwin = true ;
            }
        }
        for(int j = 0 ; j != 4 ; j++){
            int cnto = 0, cntx = 0, cntt = 0 ;
            for(int i = 0 ; i != 4 ; i++){
                if(map[i][j] == 'O')
                    cnto++ ;
                else if(map[i][j] == 'X')
                    cntx++ ;
                else if(map[i][j] == 'T')
                    cntt++ ;
                else
                    cntdot++ ;
            }
            if(cnto == 4 || cnto == 3 && cntt == 1){
                owin = true ;
            }
            if(cntx == 4 || cntx == 3 && cntt == 1){
                xwin = true ;
            }
        }
        {
            int cntx = 0, cnto = 0, cntt = 0 ;
            for(int i = 0 ; i != 4 ; i++){
                if(map[i][i] == 'O')
                    cnto++ ;
                if(map[i][i] == 'X')
                    cntx++ ;
                if(map[i][i] == 'T')
                    cntt++ ;
            }
            if(cnto == 4 || cnto == 3 && cntt == 1)
                owin = true ;
            if(cntx == 4 || cntx == 3 && cntt == 1)
                xwin = true ;
        }
        {
            int cntx = 0, cnto = 0, cntt = 0 ;
            for(int i = 0 ; i != 4 ; i++){
                if(map[i][3-i] == 'O')
                    cnto++ ;
                if(map[i][3-i] == 'X')
                    cntx++ ;
                if(map[i][3-i] == 'T')
                    cntt++ ;
            }
            if(cnto == 4 || cnto == 3 && cntt == 1)
                owin = true ;
            if(cntx == 4 || cntx == 3 && cntt == 1)
                xwin = true ;
        }
        printf("Case #%d: ", time) ;
        if(owin)
            puts("O won") ;
        else if(xwin)
            puts("X won") ;
        else if(cntdot)
            puts("Game has not completed") ;
        else
            puts("Draw") ;
    }
    return 0 ;
}
