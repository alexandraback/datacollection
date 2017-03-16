
#include<stdio.h>

int matrix[51][51];

int solve(int R,int C,int M);

void init_matrix(){
    int i,j;
    for(i=0;i<51;i++)
        for(j=0;j<51;j++)
            matrix[i][j]=0;
}

int main(){
    int i,j,k,T;
    int R,C,M;
    FILE *f=fopen("input","r");
    FILE *g=fopen("output","w");
    fscanf(f,"%d",&T);
    for(i=0;i<T;i++){
        fscanf(f,"%d %d %d",&R,&C,&M);
        fprintf(g,"Case #%d:\n",i+1);
        if(solve(R,C,M)==0)
            fprintf(g,"Impossible\n");
        else{
            matrix[1][1]=2;
            for(k=1;k<=R;k++){
                for(j=1;j<=C;j++){
                    if(matrix[k][j]==1)
                        fprintf(g,".");
                    else
                        if(matrix[k][j]==2)
                            fprintf(g,"c");
                        else
                            fprintf(g,"*");
                }
                fprintf(g,"\n");
            }
        }
    }
    fclose(f);
    fclose(g);
}



int solve(int R,int C,int M){
        int i,j,min,L;
        min = R>C ? C : R;
        L=R*C-M;
        init_matrix();
        if(L==1)
            return 1;
        if(R==1){
            for(j=1;j<=L;j++)
                matrix[1][j]=1;
            return 1;
        }
        if(C==1){
            for(i=1;i<=L;i++)
                matrix[i][1]=1;
            return 1;
        }
        if(min==2)
            if(L%2==1 || L==2)
                return 0;
            else
                if(R==2){
                    for(j=1;j<=L/2;j++){
                        matrix[1][j]=1;
                        matrix[2][j]=1;
                    }
                    return 1;
                }
                else{
                    for(i=1;i<=L/2;i++){
                        matrix[i][1]=1;
                        matrix[i][2]=1;
                    }
                    return 1;
                }
        if(L<=2*C){
            if(L%2==0 && L!=2){
                for(j=1;j<=L/2;j++){
                    matrix[1][j]=1;
                    matrix[2][j]=1;
                }
                return 1;
            }
            if(L%2==1 && L>=9){
                for(j=1;j<=(L-3)/2;j++){
                    matrix[1][j]=1;
                    matrix[2][j]=1;
                }
                matrix[3][1]=1;
                matrix[3][2]=1;
                matrix[3][3]=1;
                return 1;
            }
            return 0;
        }
        if(L%C!=1){
            int cont=0;
            for(i=1;i<=R;i++)
                for(j=1;j<=C;j++){
                    matrix[i][j]=1;
                    cont++;
                    if(cont==L)
                        return 1;
                }
        }          
        if(L>=9){
            int cont=0;
            for(i=1;i<=R;i++)
                for(j=1;j<=C;j++){
                    matrix[i][j]=1;
                    cont++;
                    if(cont==L){
                        if(i>3){
                            matrix[i-1][C]=0;
                            matrix[i][2]=1;
                        }
                        else{
                            matrix[i-1][C]=0;
                            matrix[i-2][C]=0;
                            matrix[i][2]=1;
                            matrix[i][3]=1;
                        }
                        return 1;
                    }
                }
        }
        return 0;
}
