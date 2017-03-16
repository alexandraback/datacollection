#include <cstdio>

int n;
int a[1024] , b[1024] , u[1024];

void read() {
    int i;
    
    scanf ( "%d", &n );
    for (i = 1; i <= n; i++) {
        u[i] = 0;
        scanf ( "%d%d", &a[i] , &b[i] );
    }
}

void solve() {
    int i , j;
    int ans = 0;
    int lvl = 0;
    
    while ( 1 ) {
        int move = 1;
        
        while ( move ) {
            move = 0;
            
            for (j = 1; j <= n; j++) {
       //         printf ( "%d  %d   %d\n", j , u[j] , lvl );
                if ( u[j] == 0 && b[j] <= lvl ) {
                    lvl += 2;
                    u[j] = 2;
                    ++ ans;
                    move = 1;
                }
                
                if ( u[j] == 1 && b[j] <= lvl ) {
                    lvl ++;
                    u[j] = 2;
                    ++ ans;
                    move = 1;
                }
            }
        }
        
        int idx = -1;
        
        for (j = 1; j <= n; j++) {
            if ( u[j] == 0 && a[j] <= lvl ) {
                if ( idx == -1 || b[idx] < b[j] ) {
                    idx = j;
                }
            }
        }
        
        if ( idx == -1 ) break;
        u[idx] = 1;
        ++ lvl;
        ++ ans;
    }
    
    for (i = 1; i <= n; i++) {
        if ( u[i] != 2 ) {
            printf ( "Too Bad\n");
            return ;
        }
    }
    
    printf ( "%d\n", ans );
}

int main() {
    int i , cases;
    
    scanf ( "%d", &cases );
    for (i = 1; i <= cases; i++) {
        read();
        printf ( "Case #%d: " , i );
        solve();
    }
    
    return 0;
}
