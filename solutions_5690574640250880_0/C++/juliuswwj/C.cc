#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;

#define SIZE 55
char mm[SIZE][SIZE];
int R, C, M;

int run(){
    int e=R*C-M;
    if(e == 0)return 0;
    if(M == 0){
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++)
                mm[i][j]='.';
        mm[0][0]='c';
        return 1;
    }
    if(e == 1){
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++)
                mm[i][j]='*';
        mm[0][0]='c';
        return 1;
    }
    if(C == 1){
        mm[0][0]='c';
        for(int i=1; i<R; i++){
            if(i<e)mm[i][0]='.'; else mm[i][0]='*';
        }
        return 1;
    }
    if(C == 2){
        if(e%2 != 0 || e<4)return 0;
        for(int i=0; i<R; i++){
            if(i<e/2)mm[i][0]='.'; else mm[i][0]='*';
            if(i<e/2)mm[i][1]='.'; else mm[i][1]='*';
        }
        mm[0][0]='c';
        return 1;
    }
    if(e<=2*C && e%2==0 && e>=4){
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(i<2 && j<e/2)mm[i][j]='.'; else mm[i][j]='*';
            }
        }
        mm[0][0]='c';
        return 1;
    }
    if(e<=2*C+1 && e%2==1 && e>=9){
        e -= 3;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(i<2 && j<e/2)mm[i][j]='.'; else mm[i][j]='*';
            }
        }
        mm[0][0]='c';
        mm[2][0]='.';
        mm[2][1]='.';
        mm[2][2]='.';
        return 1;
    }
    if(e>=2*C+2){
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(e>0)mm[i][j]='.'; else mm[i][j]='*';
                e--;
            }
        }
        if( (M+1)%C == 0){
            e = R*C-M;
            mm[e / C][1] = '.';
            mm[e / C-1][C-1] = '*';
        }
        mm[0][0]='c';
        return 1;
    }
    

    return 0;
}


int main()
{
    CASET {
        cout << "Case #" << case_n++ << ": " << endl;
        
        
        RI(R);
        RI(C);
        RI(M);
        
        //printf("%d %d %d\n", R, C, M);
        
        MS0(mm);
        
        bool r = R<C;
        if(r){
            int t = C;
            C = R;
            R = t;
        }
        
        if(run()){
            if(r){
                for(int j=0; j<C; j++){
                    for(int i=0; i<R; i++){
                        putchar(mm[i][j]);
                    }
                    putchar('\n');
                }
            } else {
                for(int i=0; i<R; i++){
                    for(int j=0; j<C; j++){
                        putchar(mm[i][j]);
                    }
                    putchar('\n');
                }
            }
        } else {
            printf("Impossible\n");
        }
    }
    return 0;
}
