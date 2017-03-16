#include <cstdio>
#include <cstring>

using namespace std;

int main(void){
    
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int cas, c=0, a, b;
    char board[4][6];
    
    scanf("%d", &cas);
    while( cas-- ){
        
        for(int i=0; i<4; ++i)
            scanf("%s", board[i]);
        a = b = 0;
        
        int lo=0, lx=0, ro=0, rx=0, empty=0;
        for(int i=0; i<4; ++i){
            int vo=0, vx=0, ho=0, hx=0;
            for(int j=0; j<4; ++j){
                // vertical
                if( board[i][j]=='O' )      ++vo;
                else if( board[i][j]!='.' ){
                    ++vx;
                    if( board[i][j]=='T' )  ++vo;
                }
                else    ++empty;
                // horizontal
                if( board[j][i]=='O' )      ++ho;
                else if( board[j][i]!='.' ){
                    ++hx;
                    if( board[j][i]=='T' )  ++ho;
                }
                else    ++empty;
            }
            if( vo==4 || ho==4 )    ++a;
            if( vx==4 || hx==4 )    ++b;
            
            // left diagnal
            if( board[i][i]=='O' )      ++lo;
            else if( board[i][i]!='.' ){
                ++lx;
                if( board[i][i]=='T' )  ++lo;
            }
            else    ++empty;
            // right diagnal
            if( board[i][3-i]=='O' )      ++ro;
            else if( board[i][3-i]!='.' ){
                ++rx;
                if( board[i][3-i]=='T' )  ++ro;
            }
            else    ++empty;
        }
        if( lo==4 || ro==4 )    ++a;
        if( lx==4 || rx==4 )    ++b;
        
        printf("Case #%d: ", ++c);
        if( a )             puts("O won");
        else if( b )        puts("X won");
        else if( empty )    puts("Game has not completed");
        else                puts("Draw");
    }
    
    return 0;
}
