#include <cstdio>

const int MAXN = 5000;
const int MID = 2500;
const int INF = 999999999;

int table[MAXN][MAXN];
int px, py;
bool flipx, flipy;

void doset(int y, int x, int r){
    //printf("do set %d %d %d\n", y, x, r);
    if(y + r < MAXN and table[y + r][x] > table[y][x] + 1){
        //printf("to %d %d\n", y + r, x);
        table[y + r][x] = table[y][x] + 1;
    }
    if(y - r >= 0 and table[y - r][x] > table[y][x] + 1){
        //printf("to %d %d\n", y - r, x);
        table[y - r][x] = table[y][x] + 1;
    }
    if(x + r < MAXN and table[y][x + r] > table[y][x] + 1){
        //printf("to %d %d\n", y, x + r);
        table[y][x + r] = table[y][x] + 1;
    }
    if(x - r >= 0 and table[y][x - r] > table[y][x] + 1){
        //printf("to %d %d\n", y, x - r);
        table[y][x - r] = table[y][x] + 1;
    }
}

void print(int y, int x){
    if(y == MID and x == MID) return;
    int r = table[y][x];
    //printf("%d %d %d\n", y, x, r);
    if(y + r < MAXN and table[y + r][x] == table[y][x] - 1){
        print(y + r, x);
        if(flipy) printf("N");
        else printf("S");
    }else if(y - r >= 0 and table[y - r][x] == table[y][x] - 1){
        print(y - r, x);
        if(flipy) printf("S");
        else printf("N");
    }else if(x + r < MAXN and table[y][x + r] == table[y][x] - 1){
        print(y, x + r);
        if(flipx) printf("E");
        else printf("W");
    }else if(x - r >= 0 and table[y][x - r] == table[y][x] - 1){
        print(y, x - r);
        if(flipx) printf("W");
        else printf("E");
    }else{
        printf("something wrong\n");
    }
}

int calc(){
    for(int i = 0; i < MAXN; ++i){
        for(int j = 0; j < MAXN; ++j){
            table[i][j] = INF;
        }
    }
    flipx = false;
    flipy = false;
    scanf("%d %d", &px, &py);
    if(px < 0){
        px = -px;
        flipx = true;
    }
    if(py < 0){
        py = -py;
        flipy = true;
    }
    px += MID;
    py += MID;
    table[MID][MID] = 0;
    bool found = false;
    //printf("dest = %d %d\n", py, px);
    for(int r = 1; r <= 500; r++){
        for(int i = 0; i < MAXN; ++i){
            for(int j = 0; j < MAXN; ++j){
                if(table[i][j] == r - 1){
                    doset(i, j, r);
                    if(table[py][px] != INF){
                        found = true;
                        break;
                    }
                }
            }
            if(found) break;
        }
        if(found) break;
    }
    //printf("%d\n", table[py][px]);
    if(table[py][px] == INF){
        printf("sth wrong");
    }else{
        print(py, px);
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i){
        printf("Case #%d: ", i);
        calc();
    }
    return 0;
}
