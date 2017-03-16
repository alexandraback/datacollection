#include<stdio.h>
#include<queue>
#include<cstring>
int distance[51][51];
int mineDis[51][51];
int R,C;
int cntMine;
char mineMap[51][51];

int dx[8] = {0,1,0,-1,-1,-1,1,1};
int dy[8] = {1,0,-1,0,-1,1,-1,1};

bool visited[51][51];
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

    if(cnt+cntMine == R*C){
        mineMap[x][y] = 'c';
        return true;
    }
    else
        return false;
}

int mark[51][51];
int markMap(int x,int y,bool fillChar){
    int ret = 0;
    for(int di = 0; di<8;di++){
        int nx = x+ dx[di];
        int ny = y+ dy[di];
        if(nx>=0 && nx<R &&ny>=0 && ny <C){
            if(mineMap[nx][ny] != '.' && mineMap[nx][ny] !='*'){
                mineMap[nx][ny] = fillChar? '.' : 0;
                ret++;
            }
        }
    }
    return ret;
}
bool markAnMine(){
    int minDis = 100000;
    int minX,minY;
    for(int i = 0 ;i < R;i++)
        for(int j = 0 ; j < C;j++)
            if(mineMap[i][j] == 0 && minDis > mineDis[i][j]){
                minDis = mineDis[i][j];
                minX = i;
                minY = j;
            }
    if(minDis == 100000) return false;
    mineMap[minX][minY] = '*';
    return true;
}

void generateDistance(int sx,int sy){
    std::queue< std::pair<int,int> > distanceQueue;
    distanceQueue.push(std::make_pair(sx,sy));
    memset(distance,-1,sizeof(distance));

    distance[sx][sy] = 0;

    while(distanceQueue.empty() == false){
        std::pair<int,int> node = distanceQueue.front();
        for(int i = 0 ; i< 4 ;i++){
            int nx = node.first+ dx[i];
            int ny = node.second + dy[i];

            if(nx>=0 && nx < R &&
               ny>=0 && ny < C &&
               distance[nx][ny] == -1){

                distance[nx][ny] = distance[node.first][node.second] + 1;
                distanceQueue.push(std::make_pair(nx,ny));
            }
        }
        distanceQueue.pop();
    }
}

int main(){
    int T;
    scanf("%d",&T);
    for(int _ = 0 ; _<T; _++){
        memset(mineMap,0,sizeof(mineMap));
        scanf("%d%d%d",&R,&C,&cntMine);
        printf("Case #%d:\n",_+1);
        generateDistance(R-1,C-1);

        for(int i = 0 ;i < R;i++)
        for(int j = 0 ;j < C;j++){
            mineDis[i][j] = distance[i][j];

        }

        generateDistance(0,0);
        int leftSafe = R*C-cntMine-1;
        mineMap[0][0] = '.';

        bool fail = false;

        int mineLeft = cntMine;
        while(leftSafe > 0){
            int minExpand = 10000;
            int minX,minY;
            for(int i = 0 ;i <R;i++)
            for(int j = 0 ;j <C;j++){
                if(mineMap[i][j] == '.'){
                    int cExpand = markMap(i,j,false);
                    if(cExpand >0 &&
                       ((cExpand < minExpand) ||
                        cExpand == minExpand && distance[i][j] < distance[minX][minY]
                        )
                       ){
                        minExpand = cExpand;
                        minX = i;
                        minY = j;
                    }
                }
            }
            //printf("x = %d y = %d cnt = %d\n",minX,minY, minExpand);
            leftSafe -= markMap(minX,minY,true);
            if(mineLeft >0){
                bool exist = markAnMine();
                if(exist == false){
                    fail = true;
                    break;
                }
                mineLeft--;
            }
        }

        int mineAdded = 0;

        for(int i = 0 ;i < R;i++)
        for(int j = 0 ;j < C;j++)
        if(mineMap[i][j] == 0 || mineMap[i][j] == '*'){
            mineMap[i][j] = '*';
            mineAdded++;
        }
        if(mineAdded < cntMine)
            fail = true;


        fail = (fail || !clickMine(0,0));

        if(fail){

            for(int row = 0 ;row <=R;row++){
                memset(mineMap,0,sizeof(mineMap));
                mineLeft = cntMine;
                for(int i = R-1; i> R-1-row ;i--){
                    if(mineLeft == 0 ) break;
                    for(int j = C-1;j>=0;j--){
                        mineMap[i][j] = '*';
                        mineLeft--;
                        if(mineLeft == 0 ) break;
                    }
                }
                //printf("%d\n",mineLeft);
                for(int j = C-1;j>=0 ;j--){
                    if(mineLeft == 0 ) break;
                    for(int i = R-1;i>=0;i--){
                        if(mineMap[i][j] == 0){
                            mineMap[i][j] = '*';
                            mineLeft--;
                            if(mineLeft == 0 ) break;
                        }
                    }
                }

                for(int i = 0; i < R; i++)//,puts(""))
                    for(int j = 0 ; j <C ;j++){

                        if(mineMap[i][j] == 0){
                            mineMap[i][j] = '.';
                        }
                        //printf("%c",mineMap[i][j]);
                    }

                //printf("------------\n");

                if(mineMap[0][0] == '*' || mineLeft > 0){
                    continue;
                }
                if(clickMine(0,0)){
                    fail = false;
                    break;
                }
            }
        }

        if(fail){
            puts("Impossible");
        }else{
            for(int i = 0 ; i < R; i++){
                for(int j = 0 ; j< C; j++){
                    printf("%c",mineMap[i][j]);
                }
                puts("");
            }
        }
    }
    return 0;
}
