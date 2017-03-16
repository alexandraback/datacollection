#include<stdio.h>
#include<cstring>
int R,C;
int cntMine;
char mineMap[30][30];
bool visited[30][30];

int dx[8] = {0,1,0,-1,-1,-1,1,1};
int dy[8] = {1,0,-1,0,-1,1,-1,1};
void dfs(int x, int y){
    if(visited[x][y])
        return;
    visited[x][y] = true;
    for(int di = 0 ; di < 8;di++){
        int nx = x + dx[di];
        int ny = y + dy[di];
        if(mineMap[nx][ny] == '*'){
            return;
        }
    }
    for(int di = 0 ; di < 8;di++){
        int nx = x + dx[di];
        int ny = y + dy[di];
        if(nx >=0 && nx <R && ny>=0 &&ny <C)
            dfs(nx,ny);
    }
}
bool clickMine(int x,int y){
    if(mineMap[x][y] == '*') return false;

    memset(visited, 0 , sizeof(visited));
    dfs(x,y);
    int cnt = 0;
    for(int i = 0 ; i < R;i++)
    for(int j = 0 ; j < C;j++)
        if(visited[i][j])
            cnt++;
    if(cnt +cntMine == R*C){
        mineMap[x][y] = 'c';
        return true;
    }
    else
        return false;
}
bool generateMap(int x,int y,int putMine){
    if(putMine < 0) return false;

    if(x == R){
        if(putMine > 0) return false;
        for(int i =0 ; i< R; i++)
            for(int j = 0; j < C; j++)
                if(clickMine(i,j))
                    return true;
        return false;
    }
    int nx =x, ny = y;
    if(y == C-1){
        nx++;
        ny = 0;
    }else{
        ny++;
    }
    mineMap[x][y] = '.';
    bool ret = generateMap(nx, ny,putMine);
    if(ret){
        return ret;
    }
    mineMap[x][y] = '*';
    return generateMap(nx, ny,putMine-1);
}
int main(){
    int T;
    scanf("%d",&T);
    for(int _ = 0 ; _<T; _++){
        memset(mineMap,0,sizeof(mineMap));
        scanf("%d%d%d",&R,&C,&cntMine);
        bool ans = generateMap(0,0,cntMine);
        printf("Case #%d:\n",_+1);
        if(ans){
            for(int i = 0 ; i < R; i++){
                for(int j = 0 ; j< C; j++){
                    printf("%c",mineMap[i][j]);
                }
                puts("");
            }
        }else{
            puts("Impossible");
        }
    }
    return 0;
}
