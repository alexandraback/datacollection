#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 210

int T;
int H,N,M;
int F[MAX][MAX];
int C[MAX][MAX];
int visited[MAX][MAX];
int dist[MAX][MAX];
int v2[MAX][MAX];
pair<int,int> visitedList[10010];
int vCnt;


pair<int,int> que[10010];
int d[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool canPass(int i1, int j1, int i2, int j2, int height);
void explore(int i, int j, int height, int visited[][MAX], bool add = true);


int main(){
    scanf("%d",&T);
    for (int tt = 1; tt <= T; tt++){
        scanf("%d%d%d",&H,&N, &M);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                scanf("%d",&C[i][j]);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                scanf("%d",&F[i][j]);
        memset(visited, -1, sizeof visited);
        vCnt = 0;
        
        explore(0,0,H,visited);
        int t;
        for (t = 0; t <= H; t++){
            //iterate through all previously visited states
            int exCnt = vCnt;
            for (int i = 0; i < exCnt; i++){
                int curI = visitedList[i].first, curJ = visitedList[i].second;
                if (visited[curI][curJ] > t) continue;
                //printf("cur t: %d i:%d,j:%d vis: %d\n",t,curI,curJ,visited[curI][curJ]);
                for (int k = 0; k < 4; k++){
                    int newI = curI + d[k][0];
                    int newJ = curJ + d[k][1];
                    if (newI < 0 || newI >= N) continue;
                    if (newJ < 0 || newJ >= M) continue;
                    if (canPass(curI,curJ,newI,newJ,H-t)){
                        //printf("here t:%d\n",t);
                        if (visited[newI][newJ] == -1){
                            visitedList[vCnt++] = make_pair(newI,newJ);
                            if (H-t-F[curI][curJ] >= 20)
                                visited[newI][newJ] = t + 10;
                            else visited[newI][newJ] = t + 100;
                        }else {
                            if (H-t-F[curI][curJ] >= 20)
                                visited[newI][newJ] = min(visited[newI][newJ],t + 10);
                            else visited[newI][newJ] = min(visited[newI][newJ],t + 100);
                        }
                    }
                }
            }
            //if (visited[N-1][M-1] != -1) break;
        }
        int res = (int)1e9;
        //printf("end: %d\n",visited[N-1][M-1]);
        //if (visited[N-1][M-1] == -1){
            for (int i = 0; i < vCnt; i++){
                memset(v2, -1, sizeof v2);
                int ii  = visitedList[i].first, jj = visitedList[i].second;
                //printf("explore from %d,%d visited:%d\n",ii,jj,visited[ii][jj]);
                explore( ii, jj, 0, v2, false);
                if (v2[N-1][M-1] != -1) res = min(res, max(t,visited[ii][jj])+dist[N-1][M-1]);
            }
        //}else{
            //printf("here\n");
            if (visited[N-1][M-1] != -1) res = min(res,visited[N-1][M-1]);
        //}
        printf("Case #%d: %.1f\n",tt,(double)res/10.0);
    }
    return 0;
}

void explore(int i, int j, int height, int visited[][MAX], bool add){
    int p = 0, q = 0;
    for (int ii = 0; ii < N; ii++) for (int jj =0; jj< M; jj++) dist[ii][jj] = 1000000000;
    que[q++] = make_pair(i,j);
    dist[i][j] = 0;
    visited[i][j] = 0;
    if (add) visitedList[ vCnt++ ] = make_pair(i,j);
    while (p < q){
        int curI = que[p].first, curJ = que[p].second;p++;
        for (int k = 0; k < 4; k++){
            int newI = curI + d[k][0];
            int newJ = curJ + d[k][1];
            if (newI < 0 || newI >= N) continue;
            if (newJ < 0 || newJ >= M) continue;
            if (visited[newI][newJ] == -1 && canPass(curI,curJ,newI,newJ,height)){
                que[q++] = make_pair(newI,newJ);
                visited[newI][newJ] = 0;
                if (add) visitedList[ vCnt++ ] = make_pair(newI,newJ);
                dist[newI][newJ] = min(dist[newI][newJ],dist[curI][curJ]+100);
            }
        }
    }
}

bool canPass(int i1, int j1, int i2, int j2, int height){
    if (height + 50 > C[i2][j2]) return false;
    if (F[i1][j1] + 50 > C[i2][j2]) return false;
    if (F[i2][j2] + 50 > C[i2][j2]) return false;
    if (F[i2][j2] + 50 > C[i1][j1]) return false;
    return true;
}