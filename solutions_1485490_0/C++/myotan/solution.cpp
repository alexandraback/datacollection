#include <stdio.h>

unsigned long long board[1000][1000];
unsigned long long inA[1000][2],inB[1000][2];

int main(){
    unsigned long long test,t,na,nb,i,Tx,Ty,j;
    scanf("%llu",&test);
    for(t=1;t<=test;t++){
        scanf("%llu %llu",&na,&nb);
        for(i=0;i<na;i++){
            scanf("%llu %llu",&Tx,&Ty);
            /*if(i>0&&inA[i-1][1]==Ty){
                i--;inA[i][0]+=Tx;na--;
            }else*/{
                inA[i][0]=Tx;inA[i][1]=Ty;
            }
        }
        for(i=0;i<nb;i++){
            scanf("%llu %llu",&Tx,&Ty);
            /*if(i>0&&inB[i-1][1]==Ty){
                i--;inB[i][0]+=Tx;nb--;
            }else*/{
                inB[i][0]=Tx;inB[i][1]=Ty;
            }
        }
        for(i=0;i<nb;i++){
            for(j=0;j<na;j++){
                if(inB[i][1]==inA[j][1]){
                    Tx=inB[i][0]>inA[j][0]?inA[j][0]:inB[i][0];
                    inB[i][0]-=Tx;
                    inA[j][0]-=Tx;
                    board[i][j]=Tx;
                }else
                    board[i][j]=0;
                Ty=i>0?board[i-1][j]:0;
                Tx=j>0?board[i][j-1]:0;
                board[i][j]+=Tx>Ty?Tx:Ty;
                //printf("%llu ",board[i][j]);
            }//putchar(10);
        }
        printf("Case #%llu: %llu\n",t,board[nb-1][na-1]);
    }
    return 0;
}
