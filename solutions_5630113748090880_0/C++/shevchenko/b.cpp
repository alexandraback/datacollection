#include<stdio.h>

int N;
int lines[100][50];
int order[50][2];
int c[100];
int board[50][50];

void process(){
    int i, j;
    for(i=0;i<N+N-1;i++) c[i]=0;
    for(i=0;i<N;i++){
        int maxend = 0;
        for(j=0;j<N+N-1;j++){
            if(c[j]) continue;
            if(lines[j][N-i-1] > maxend){
                maxend = lines[j][N-i-1];
            }
        }
        int cnt = 0;
        for(j=0;j<N+N-1;j++){
            if(c[j]) continue;
            if(lines[j][N-i-1] == maxend){
                if(cnt>=2){
                    printf("Huh?\n");
                }
                order[i][cnt++] = j;
                c[j] = 1;
            }
        }
        if(cnt == 1){
            order[i][1] = -1;
        }
    }

    int missing_idx, missing_rc;
    for(i=0;i<N;i++){
        int x = order[i][0], y = order[i][1], xpos[2] = {0,}, ypos[2] = {0,};

        for(j=N-i-1;j<N;j++) if(board[N-i-1][j] != lines[x][j] && board[N-i-1][j] > 0) break;
        if(j==N) xpos[0] = 1;
        for(j=N-i-1;j<N;j++) if(board[j][N-i-1] != lines[x][j] && board[j][N-i-1] > 0) break;
        if(j==N) xpos[1] = 1;

        if(y == -1){
            ypos[0] = 1; ypos[1] = 1;
        }
        else{
            for(j=N-i-1;j<N;j++) if(board[N-i-1][j] != lines[y][j] && board[N-i-1][j] > 0) break;
            if(j==N) ypos[0] = 1;
            for(j=N-i-1;j<N;j++) if(board[j][N-i-1] != lines[y][j] && board[j][N-i-1] > 0) break;
            if(j==N) ypos[1] = 1;
        }

        if(xpos[0] == 1 && ypos[1] == 1){
            for(j=0;j<N;j++) board[N-i-1][j] = lines[x][j];
            if(y == -1){
                missing_idx = N-i-1;
                missing_rc = 1;
            }
            else{
                for(j=0;j<N;j++) board[j][N-i-1] = lines[y][j];
            }
        }
        else{
            for(j=0;j<N;j++) board[j][N-i-1] = lines[x][j];
            if(y == -1){
                missing_idx = N-i-1;
                missing_rc = 0;
            }
            else{
                for(j=0;j<N;j++) board[N-i-1][j] = lines[y][j];
            }
        }

//        for(int i=0;i<N;i++){
//            for(int j=0;j<N;j++){
//                printf("%d ",board[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n");
    }

    if(missing_rc == 1){
        for(j=0;j<N;j++) printf("%d ",board[j][missing_idx]);
    }
    else{
        for(j=0;j<N;j++) printf("%d ",board[missing_idx][j]);
    }
    printf("\n");

    for(i=0;i<N;i++) for(j=0;j<N;j++) board[i][j]=0;
}

int main(){
    int t, T;
    int i, j;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d",&N);
        for(i=0;i<N+N-1;i++){
            for(j=0;j<N;j++){
                scanf("%d",&lines[i][j]);
            }
        }
        printf("Case #%d: ", t);
        process();
    }
    return 0;
}
