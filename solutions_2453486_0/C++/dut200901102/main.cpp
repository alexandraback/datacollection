#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

char str[4][5];

void init(){
    for(int i = 0; i < 4; ++i)
        scanf("%s", str[i]);
}
bool won(char tar){
    bool find;
    for(int r = 0; r < 4; ++r){
        find = false;
        for(int c = 0; c < 4; ++c)
            if(!(str[r][c] == 'T' || str[r][c] == tar))
                find = true;
        if(!find) return true;
    }
    for(int c = 0; c < 4; ++c){
        find = false;
        for(int r = 0; r < 4; ++r)
            if(!(str[r][c] == 'T' || str[r][c] == tar))
                find = true;
        if(!find) return true;
    }
    find =false;
    for(int i = 0; i < 4; ++i)
        if(!(str[i][i] == 'T' || str[i][i] == tar))
            find = true;
    if(!find) return true;
    
    find = false;
    for(int i = 0; i < 4; ++i)
        if(!(str[i][3 - i] == 'T' || str[i][3 - i] == tar))
            find = true;
    if(!find) return true;

    return false;
}
bool empty(){
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
            if(str[i][j] == '.') return true;
    return false;
}
void solve(){
    if(won('X')) puts("X won");
    else if(won('O')) puts("O won");
    else{
        puts(empty() ? "Game has not completed" : "Draw");
    }
}
int main(){
    int t, cas = 1;
    for(cin >> t; t--; ){
        printf("Case #%d: ", cas++);
        init();
        solve();
    }
    return 0;
}
