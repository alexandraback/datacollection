#include <stdlib.h>
#include <stdio.h>

inline int min(int a, int b){

    if(a<b)
        return a;
    else
        return b;
}

inline int max(int a, int b){

    if(a>b)
        return a;
    else
        return b;
}

void exchange(int * a, int * b){

    int t = *a;

    *a = *b;

    *b = t;
}

#define BOMB -1
#define CLICK -5

int board[52][52];

void printTable(int R, int C){

    int i,j;
    for(i=1; i<=R; i++){
        for(j=1; j<=C; j++){
            if(board[i][j]>=0)
                printf(".");
            else if(board[i][j] == BOMB)
                printf("*");
            else if(board[i][j] == CLICK)
                printf("c");
        }
        printf("\n");
    }

}

void SetClick(int R, int C){

    board[R][C] = CLICK; //c

}

//Limpia el area indicada
void Clean(int i1, int j1, int i2, int j2){

    int i,j;
    for(i=i1; i<=i2; i++){
        for(j=j1; j<=j2; j++){
            board[i][j] = 0;
        }
    }

}

//Planta de minas desde la casilla (i,j) hasta la (i2, j2);
void SetBombs(int i1, int j1, int i2, int j2){

    int i,j;
    for(i=i1; i<=i2; i++){
        for(j=j1; j<=j2; j++){
            board[i][j] = BOMB;
        }
    }

}

//Transpone la matriz
void transposeMatrix(int R, int C){

    int i,j;
    for(i=1; i<=50; i++){
        for(j=i; j<=50; j++){
            if(i != j)
                exchange(&board[i][j], &board[j][i]);
        }
    }
}

int main(){

    int T; //Number of test cases (1-140)
    scanf("%d", &T);

    int R; //Number of rows (1-50)

    int C; //Number of columns (1-50)

    int M; //Number of mines (M < R*C => max = 2499)

    int t;
    for(t=1; t<=T; t++){

        scanf("%d", &R);
        scanf("%d", &C);
        scanf("%d", &M);

        printf("Case #%d:\n", t);


        if(M==0){//Esto siempre es posible
            Clean(1,1,  R,C);
            SetClick(1,1);
        }


        else if(R == C){ //Matriz cuadrada

            if(R==2){//2x2
                if(M==3){
                    SetBombs(1,1,  2,2);
                    SetClick(1,1);
                }else{
                    printf("Impossible\n");
                    continue;
                }

            }else if(R==3){//3x3

                Clean(1,1,  3,3);

                if(M==1){
                    SetBombs(3,3,  3,3);
                    SetClick(1,1);

                }else if(M==3){
                    SetBombs(3,1,  3,3);
                    SetClick(1,2);

                }else if(M==5){
                    SetBombs(3,1,  3,3);
                    SetBombs(1,3,  3,3);
                    SetClick(1,1);

                }else if(M==8){
                    SetBombs(2,1,  3,3);
                    SetBombs(1,2,  1,3);
                    SetClick(1,1);

                }else{
                    printf("Impossible\n");
                    continue;
                }

            }else if(R==4){//4x4

                Clean(1,1,  4,4);

                if(M==3){
                    SetBombs(4,3,  4,4);
                    SetBombs(3,4,  3,4);
                    SetClick(1,1);

                }else if(M==15){
                    SetBombs(2,1,  4,4);
                    SetBombs(1,2,  1,4);
                    SetClick(1,1);

                }else if(M==7){
                    SetBombs(4,1,  4,4);
                    SetBombs(1,4,  4,4);
                    SetClick(1,1);

                }else if(M<=8){ //M=1, M=2, M=4, M=5, M=6, M=8
                    SetBombs(5-(M-1)/C, 1,   4,4);
                    SetBombs(4-(M-1)/C, C-(M-1)%C,   4-(M-1)/C,4);
                    SetClick(1,1);

                }else if(M==10){
                    SetBombs(3,1,  4,4);
                    SetBombs(1,4,  2,4);
                    SetClick(1,1);

                }else if(M==12){
                    SetBombs(3,1,  4,4);
                    SetBombs(1,3,  2,4);
                    SetClick(1,1);

                }else{ //M=9, M=11, M=13, M=14
                    printf("Impossible\n");
                    continue;
                }


            }else if(R>=5){//5x5

                Clean(1,1,  R,R);

                if(M==4){
                    SetBombs(R-1,R-1,  R,R);
                    SetClick(1,1);

                }else if(M==9){
                    SetBombs(R-2,R-2,  5,5);
                    SetClick(1,1);

                }else if(M==R*R-11){
                    SetBombs(R,1,  R,R);
                    SetBombs(1,R-2,  1,R);
                    SetBombs(1,R-1,  R,R);
                    SetClick(1,1);

                }else if(M==R-1){
                    SetBombs(2,1,  R,R);
                    SetBombs(1,2,  1,R);
                    SetClick(1,1);

                }else if(M<=(R-2)*C){
                    SetBombs(R+1-(M-1)/C, 1,   R,R);
                    SetBombs(R-(M-1)/C, C-(M-1)%C,   R-(M-1)/C,R);
                    SetClick(1,1);

                }else if(M==(R-1)*(R-1)){
                    SetBombs(1,1,  R,R);
                    Clean(2,2,  R-1,R-1);
                    SetClick(3,3);

                }else if(M==R*R-8){
                    SetBombs(3,1,  R,R);
                    SetBombs(1,R,  2,R);
                    SetClick(1,1);

                }else if(M==R*R-6){
                    SetBombs(3,1,  R,R);
                    SetBombs(1,R-1,  2,R);
                    SetClick(1,1);

                }else if(M==R*R-4){
                    SetBombs(3,1,  R,R);
                    SetBombs(1,3,  2,R);
                    SetClick(1,1);

                }else if(M==R*R-7 || M==R*R-5 || M>=R*R-3){
                    printf("Impossible\n");
                    continue;

                }

            }

        }else{ //Different

            if(min(R,C)==1 &&  M < (max(R,C)) ){ //1x3 , 1x4 , 1x5

                Clean(1,1,  1,max(R,C));
                SetBombs(1,max(R,C)-M+1,  1,max(R,C));
                SetClick(1,1);

            }else if(min(R,C)==2 &&  M%2==0 && M < (max(R,C)*2-2) ){ //2x3 , 2x4 , 2x5

                Clean(1,1,  2,max(R,C));
                SetBombs(1,max(R,C)-M/2+1,  2,max(R,C));
                SetClick(1,1);

            }else if(min(R,C)==2 &&  M == R*C-1 ){

                SetBombs(1,1,  2,max(R,C));
                SetClick(1,1);

            }else if(min(R,C)==3){ //3x4, 3x5

                Clean(1,1,  3,max(R,C));

                if(M == R*C-1){
                    SetBombs(1,1,  3,max(R,C));
                    SetClick(1,1);

                }else if(M == 3){
                    SetBombs(1,max(R,C),  3,max(R,C));
                    SetClick(1,1);

                }else if(M == 4 && max(R,C)==5){
                    SetBombs(1,5,  3,5);
                    SetBombs(3,4,  3,5);
                    SetClick(1,1);

                }else if(M == 7 && max(R,C)==5){
                    SetBombs(1,4,  3,5);
                    SetBombs(3,3,  3,5);
                    SetClick(1,1);

                }else if(M == max(R,C)-1){
                    printf("Impossible\n");
                    continue;

                }else if(M <= max(R,C)){
                    SetBombs(3, max(R,C)-M+1,   3,max(R,C));
                    SetClick(1,1);

                }else if(M == R*C-9){
                    SetBombs(1,4 ,  3,max(R,C));
                    SetClick(1,1);

                }else if(M == R*C-6){
                    SetBombs(1,3 ,  3,max(R,C));
                    SetClick(1,1);

                }else if(M == R*C-4){
                    SetBombs(1,3 ,  3,max(R,C));
                    SetBombs(3,1 ,  3,max(R,C));
                    SetClick(1,1);

                }else{
                    printf("Impossible\n");
                    continue;
                }

            }else if(min(R,C)>=4){ //4x5

                Clean(1,1,  min(R,C),max(R,C));

                if(M == R*C-1){
                    SetBombs(1,1,  min(R,C),max(R,C));
                    SetClick(1,1);

                }else if(M==4){
                    SetBombs(3,max(R,C)-1,  min(R,C),max(R,C));
                    SetClick(1,1);

                }else if(M==9){ //M=4, M=9
                    SetBombs(4,1,  4,max(R,C));
                    SetBombs(1,max(R,C),  4,max(R,C));
                    SetBombs(3,max(R,C)-1,  3,max(R,C));
                    SetClick(1,1);

                }else if(M <= max(R,C)*2){ //M=1, M=2, M=3, M=5, M=6, M=7, M=8, M=10

                    SetBombs(min(R,C)+1-(M-1)/max(R,C), 1,   min(R,C),max(R,C));
                    SetBombs(min(R,C)-(M-1)/max(R,C), max(R,C)-(M-1)%max(R,C),   min(R,C)-(M-1)/max(R,C),max(R,C));
                    SetClick(1,1);

                }else if(M==R*C-9){
                    SetBombs(1,1,  min(R,C),max(R,C));
                    Clean(2,2,  min(R,C),min(R,C));
                    SetClick(3,3);

                }else if(M==12){
                    SetBombs(3,1,  min(R,C),max(R,C));
                    SetBombs(1,max(R,C),  2,max(R,C));
                    SetClick(1,1);

                }else if(M==14){
                    SetBombs(3,1,  min(R,C),max(R,C));
                    SetBombs(1,max(R,C)-1,  2,max(R,C));
                    SetClick(1,1);

                }else if(M==16){
                    SetBombs(3,1,  min(R,C),max(R,C));
                    SetBombs(1,max(R,C)-2,  2,max(R,C));
                    SetClick(1,1);

                }else{
                    printf("Impossible\n");
                    continue;
                }

            }else{
                printf("Impossible\n");
                continue;
            }


            if(R>C){
                transposeMatrix(R, C);
            }

        }

        printTable(R, C);
    }

    return 0;
}
