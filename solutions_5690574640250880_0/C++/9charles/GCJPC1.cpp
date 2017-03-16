#include<cstdio>  
#include<cstring>  
#include<cctype>  
#include<cmath>  
#include<cstdlib>  
#include<ctime>  
#include<iostream>  
#include<iomanip>  
#include<sstream>  
#include<vector>  
#include<string>  
#include<queue>  
#include<stack>  
#include<utility>  
#include<algorithm>  
#include<map>  
#include<set>  
#include<bitset>  
#include<sstream>
#define MAX 100
using namespace std;
typedef long long int ll;

char resp[MAX][MAX];

void inverte(char r[100][100],int R, int C);

int main(){
    int T,R,C,M;
    scanf("%d",&T);
    for(int caso=1;caso<=T;caso++){
        scanf("%d%d%d",&R,&C,&M);
        int falta=R*C-M;
        printf("Case #%d:\n",caso);
        bool impossivel=false;
        bool inverta=false;
        for(int i=0;i<70;i++)for(int j=0;j<70;j++){resp[i][j]='*';}
        if(falta==1){
            resp[0][0]='c';
            for(int i=0;i<R;i++)resp[i][C]='\0';
            for(int i=0;i<R;i++){printf("%s\n",resp[i]);}
            continue;
        }
        //resp eh preenchida supondo que R<=C
        if(R==1&&C==1){
            resp[0][0]='c'; resp[0][1]='\0';
        }
        else if(R==1||C==1){
            if(R>C){inverta = true;}
            resp[0][0]='c';
            for(int i=1;i<falta;i++){resp[0][i]='.';}
            for(int i=falta;i<R*C;i++){resp[0][i]='*';}
            resp[0][R*C]='\0';
        }
        else if(R==2||C==2){
            if(R>C){inverta = true;}
            if(!(falta%2==0&&falta>=4)){impossivel=true;}
            else{
                resp[0][0]='c';
                for(int i=1;i<falta/2;i++){resp[0][i]='.';}
                for(int i=falta/2;i<(R*C)/2;i++){resp[0][i]='*';}
                resp[0][(R*C)/2]='\0';
                resp[1][0]='.';
                for(int i=1;i<falta/2;i++){resp[1][i]='.';}
                for(int i=falta/2;i<(R*C)/2;i++){resp[1][i]='*';}
                resp[1][(R*C)/2]='\0';
            }
        }
        else{ //R>=3 && C>=3
            for(int i=0;i<R;i++){resp[i][C]='\0';}
            if(falta==2||falta==3||falta==5||falta==7){impossivel=true;}
            else if(falta%2==0){
                int resta=falta;
                resp[0][0]='c'; resp[0][1]='.'; resp[1][0]='.'; resp[1][1]='.';
                resta-=4;
                int col=2;
                while(col<C&&resta>0){
                    resp[0][col]='.'; resp[1][col]='.';
                    resta-=2;
                    col++;
                }
                int lin=2;
                while(lin<R&&resta>0){
                    col=0;
                    while(col+1<C&&resta>0){
                        resp[lin][col]='.'; resp[lin][col+1]='.';
                        resta-=2;
                        col+=2;
                    }
                    lin++;
                }
                //acho que se C eh par não entra nos loops seguintes
                lin=2;
                while(lin+1<R&&resta>0){
                    resp[lin][C-1]='.'; resp[lin+1][C-1]='.';
                    resta-=2;
                    lin+=2;
                }                   
            }
            else{ //falta eh IMPAR e >=9
                int resta=falta;
                resp[0][0]='c'; resp[0][1]='.'; resp[0][2]='.';
                resp[1][0]='.'; resp[1][1]='.'; resp[1][2]='.';
                resp[2][0]='.'; resp[2][1]='.'; resp[2][2]='.';
                resta-=9;
                int lin,col;
                if((R%2==0)&&(C%2==0)){
                    col=3;
                    while(col<C&&resta>0){
                        resp[0][col]='.'; resp[1][col]='.';
                        resta-=2;
                        col++;
                    }
                    lin=3;
                    while(lin<R&&resta>0){
                        resp[lin][0]='.'; resp[lin][1]='.';
                        resta-=2;
                        lin++;
                    }
                    if(resta>0){
                        resp[2][3]='.'; resp[3][2]='.';
                        resta-=2;
                    }
                    col=4;
                    while(col+1<C&&resta>0){
                        resp[2][col]='.'; resp[2][col+1]='.';
                        resta-=2;
                        col+=2;
                    }
                    lin=4;
                    while(lin+1<R&&resta>0){
                        resp[lin][2]='.'; resp[lin+1][2]='.';
                        resta-=2;
                        lin+=2;
                    }
                    lin=3;
                    while(lin+1<R&&resta>0){
                        col=3;
                        while(col<C&&resta>0){
                            resp[lin][col]='.'; resp[lin+1][col]='.';
                            resta-=2;
                            col++;
                        }
                        lin+=2;
                    }
                    col=3;
                    while(col+1<C&&resta>0){
                        resp[R-1][col]='.'; resp[R-1][col+1]='.';
                        resta-=2;
                        col+=2;
                    }
                }
                else{
                    if(C%2){
                        col=3;
                        while(col<C&&resta>0){
                            resp[0][col]='.'; resp[1][col]='.';
                            resta-=2;
                            col++;
                        }
                        col=3;
                        while(col+1<C&&resta>0){
                            resp[2][col]='.'; resp[2][col+1]='.';
                            resta-=2;
                            col+=2;
                        }
                        lin=3;
                        while(lin<R&&resta>0){
                            col=0;
                            while(col+1<C&&resta>0){
                                resp[lin][col]='.'; resp[lin][col+1]='.';
                                resta-=2;
                                col+=2;
                            }
                            lin++;
                        }
                        lin=3;
                        while(lin+1<R&&resta>0){
                            resp[lin][C-1]='.'; resp[lin+1][C-1]='.';
                            resta-=2;
                            lin+=2;
                        }
                    }
                    else{
                        lin=3;
                        while(lin<R&&resta>0){
                            resp[lin][0]='.'; resp[lin][1]='.';
                            resta-=2;
                            lin++;
                        }
                        lin=3;
                        while(lin+1<R&&resta>0){
                            resp[lin][2]='.'; resp[lin+1][2]='.';
                            resta-=2;
                            lin+=2;
                        }
                        col=3;
                        while(col<C&&resta>0){
                            lin=0;
                            while(lin+1<R&&resta>0){
                                resp[lin][col]='.'; resp[lin+1][col]='.';
                                resta-=2;
                                lin+=2;
                            }
                            col++;
                        }
                        col=3;
                        while(col+1<C&&resta>0){
                            resp[R-1][col]='.'; resp[R-1][col+1]='.';
                            resta-=2;
                            col+=2;
                        }
                    }    
                }
            }
        }
        if(impossivel){printf("Impossible\n");}
        else if(inverta){
            inverte(resp,R,C);
            for(int i=0;i<R;i++){printf("%s\n",resp[i]);}
        }
        else{
            for(int i=0;i<R;i++){printf("%s\n",resp[i]);}
        }
    }
    return 0;
}

void inverte(char r[100][100],int R, int C){
    char nr[100][100];
    for(int i=0;i<R;i++)for(int j=0;j<C;j++){nr[i][j]=r[j][i];}
    for(int i=0;i<R;i++)nr[i][C]='\0';
    for(int i=0;i<R;i++)for(int j=0;j<=C;j++){r[i][j]=nr[i][j];}
}
