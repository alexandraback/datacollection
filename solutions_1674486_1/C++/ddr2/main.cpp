#include <algorithm>
#include <cstdio>
#include <cstdlib>

int mgraphe[1000] ;
int graphe[1000][10] ;
bool marked[1000] ;

bool mark(int i) {
    //printf("%d (%d) ", i, mgraphe[i - 1]) ;
    
    for (int j = 0 ; j < mgraphe[i - 1] ; j++) {
        if (marked[graphe[i - 1][j] - 1])
            return true ;
        else {
            marked[graphe[i - 1][j] - 1] = true ;
            if (mark(graphe[i - 1][j]))
                return true ;
        }
    }
    
    return false ;
}

int main() {
    int nbTests ;
    scanf("%d", &nbTests) ;

    for (int i = 0 ; i < nbTests ; i++) {
        int nbNoeuds ;
        scanf("%d", &nbNoeuds) ;
        
        for (int j = 0 ; j < nbNoeuds ; j++) {
            scanf("%d", &mgraphe[j]) ;
            for (int k = 0 ; k < mgraphe[j] ; k++) {
                scanf("%d", &graphe[j][k]) ;
            }
        }
        
        printf("Case #%d: ", i+1) ;
        bool trouve = false ;
        for (int j = 0 ; j < nbNoeuds & !trouve; j++) {
            for (int k = 0 ; k < nbNoeuds ; k++) {
                marked[k] = false ;
            }
            
            if (mark(j+1)) {
                trouve = true ;
            }
        }
        
        if (trouve)
            printf("Yes\n") ;
        else
            printf("No\n") ;
        
    }
}