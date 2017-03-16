
#include <cstdio>
#include <cstring>
#include <cstdlib>

int nowk[21], N ;

int keyt[21], keycnt[21], keys[21][41], want[21], give[21] ;
int gen[21][21] ;

int vis[21], ans[21] ;

bool puted ;

void dfs(int now){
    if(now == N){
        for(int i = 0 ; i != N ; i++)
            printf(" %d", ans[i]) ;
        putchar('\n') ;
        puted = true ;
        return ;
    }
    for(int i = 0 ; i != N ; i++){
        if(vis[i] || nowk[keyt[i]] == 0)    continue ;
        nowk[keyt[i]]-- ;
        want[keyt[i]]-- ;
        vis[i] = true ;
        for(int j = 0 ; j != keycnt[i] ; j++)
            nowk[keys[i][j]]++ ;
        ans[now] = i+1 ;
        bool next = true ;
        if(nowk[keyt[i]] == 0 && want[keyt[i]] != 0){
            next = false ;
            for(int f = 0 ; f != N ; f++){
                if(keyt[f] == keyt[i])  continue ;
                if(gen[f][keyt[i]]){
                    next = true ;
                    break ;
                }
            }
        }
        if(next)    dfs(now+1) ;
        if(puted)   return ;
        for(int j = 0 ; j != keycnt[i] ; j++)
            nowk[keys[i][j]]-- ;
        vis[i] = false ;
        nowk[keyt[i]]++ ;
        want[keyt[i]]++ ;
    }
}

int main()
{
    int T ;
    scanf("%d", &T) ;
    for(int time = 1 ; time <= T ; time++){
        int K ;
        scanf("%d%d", &K, &N) ;
        int tmp ;
        memset(nowk, 0, sizeof(nowk)) ;
        memset(want, 0, sizeof(want)) ;
        memset(give, 0, sizeof(give)) ;
        memset(gen, 0, sizeof(gen)) ;
        for(int i = 0 ; i != K ; i++){
            scanf("%d", &tmp) ;
            nowk[tmp]++ ;
            give[tmp]++ ;
        }
        for(int i = 0 ; i != N ; i++){
            scanf("%d%d", &keyt[i], &keycnt[i]) ;
            want[keyt[i]]++ ;
            for(int j = 0 ; j != keycnt[i] ; j++){
                scanf("%d", keys[i]+j) ;
                give[keys[i][j]]++ ;
                gen[i][keys[i][j]] = true ;
            }
        }
        printf("Case #%d:", time) ;
        bool imp = false ;
        for(int i = 0 ; i != N ; i++)
            if(want[i] > give[i])
                imp = true ;
        memset(vis, 0, sizeof(vis)) ;
        puted = false ;
        if(!imp)    dfs(0) ;
        if(!puted)
            puts(" IMPOSSIBLE") ;
        //if(!imp) puts("run") ;
    }
    return 0 ;
}
