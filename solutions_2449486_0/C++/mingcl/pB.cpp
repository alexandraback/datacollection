
#include <cstdio>
#include <cstring>

int map[110][110] ;

int maxr[110], maxc[110] ;

int maxv(int i1, int i2){
    return i1 > i2 ? i1 : i2 ;
}

int main()
{
    int T ;
    scanf("%d", &T) ;
    for(int time = 1 ; time <= T ; time++){
        int N, M ;
        scanf("%d%d", &N, &M) ;
        for(int i = 0 ; i != N ; i++)
            for(int j = 0 ; j != M ; j++)
                scanf("%d", &map[i][j]) ;
        memset(maxr, -1, sizeof(maxr)) ;
        memset(maxc, -1, sizeof(maxc)) ;
        for(int i = 0 ; i != N ; i++)
            for(int j = 0 ; j != M ; j++)
                maxr[i] = maxv(maxr[i], map[i][j]) ;
        for(int j = 0 ; j != M ; j++)
            for(int i = 0 ; i != N ; i++)
                maxc[j] = maxv(maxc[j], map[i][j]) ;
        bool ans = true ;
        for(int i = 0 ; i != N ; i++)
            for(int j = 0 ; j != M ; j++)
                if(map[i][j] != maxr[i] && map[i][j] != maxc[j])
                    ans = false ;
        printf("Case #%d: ", time) ;
        puts(ans ? "YES" : "NO") ;
    }
}

