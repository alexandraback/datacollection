#include <cstdio>

using namespace std;

char M[4][5];

bool wins(char c){
    
    for(int i = 0;i < 4;++i){
        int cont = 0;
        for(int j = 0;j < 4;++j)
            cont += (M[i][j] == c || M[i][j] == 'T')? 1 : 0;
        if(cont == 4) return true;
    }
    
    for(int i = 0;i < 4;++i){
        int cont = 0;
        for(int j = 0;j < 4;++j)
            cont += (M[j][i] == c || M[j][i] == 'T')? 1 : 0;
        if(cont == 4) return true;
    }
    
    int d1 = 0,d2 = 0;
    
    for(int i = 0;i < 4;++i){
        d1 += (M[i][i] == c || M[i][i] == 'T')? 1 : 0;
        d2 += (M[i][3 - i] == c || M[i][3 - i] == 'T')? 1 : 0;
    }
    
    return (d1 == 4 || d2 == 4);
}

int main(){
    int T;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        printf("Case #%d: ",tc);
        
        int cont = 0;
        
        for(int i = 0;i < 4;++i){
            scanf("%s",M[i]);
            for(int j = 0;j < 4;++j)
                if(M[i][j] == '.') ++cont;
        }
        
        if(wins('X')) puts("X won");
        else if(wins('O')) puts("O won");
        else if(cont == 0) puts("Draw");
        else puts("Game has not completed");
    }
    
    return 0;
}
