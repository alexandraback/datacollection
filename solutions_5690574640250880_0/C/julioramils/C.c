#include <stdio.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define true 1
#define false 0

int main(){
    freopen ("C-small-attempt2.in","r",stdin);
    freopen ("C_out2","w",stdout);
    int T;
    int caso=0;
    int R;
    int C;
    int Rx, Cx;
    int M;
    int minl;
    int i, j, z;
    int sol;
    int s;
    char mat[50][50];
    scanf("%d", &T);

    while(T--){
        caso++;
        scanf("%d %d %d", &R, &C, &M);
        for(i=0;i<R;i++){
            for(j=0;j<C;j++){
                mat[i][j]='.';
            }
        }
        Rx=R;
        Cx=C;
        i=j=0;
        sol=true;
        s=false;
        printf("Case #%d:\n", caso, R, C, M);

        if(!M){
            mat[i][j]='c';
        }else{
            if(R==1||C==1){
                s=true;
            }
            while(M>=R||M>=C){
                if(R>C){
                    for(z=j;z<C+j;z++){
                        mat[i][z]='*';
                    }
                    i++;
                    R--;
                    M-=C;
                }else{
                    for(z=i;z<R+i;z++){
                        mat[z][j]='*';
                    }
                    j++;
                    C--;
                    M-=R;
                }
            }
            if(!M&&R==1&&C==1){
                mat[i][j]='c';
            }
            else{
                minl=MIN(R,C);
                if(minl==1){
                    if(s){
                        mat[Rx-1][Cx-1]='c';
                    }else{
                        sol=false;
                    }
                    //sol = true;//no deberia pasar
                }else if(minl==2&&(M==1||(R*C)<2)){
                    sol=false;
                }
                else if(R==3&&C==3&&M==2){
                    sol=false;
                }
                else{
                    //check one line
                    if(R>C){
                        for(z=i;z<R+i-2&&M;z++){
                            mat[z][j]='*';
                            M--;
                        }
                        if(M>0){
                           mat[i][j+1]='*';
                        }
                        mat[Rx-1][Cx-1]='c';
                    }
                    else{
                        for(z=j;z<C+j-2&&M;z++){
                            mat[i][z]='*';
                            M--;
                        }
                        if(M>0){
                           mat[i+1][j]='*';
                        }
                        mat[Rx-1][Cx-1]='c';
                    }
                }
            }
        }

        if(!sol){
            printf("Impossible\n");
        }else{
            for(i=0;i<Rx;i++){
                for(j=0;j<Cx;j++){
                    printf("%c",mat[i][j]);
                }
                printf("\n");
            }
        }


    }
    return 0;
}
