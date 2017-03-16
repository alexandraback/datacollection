#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int T;
int R,C,M;

void caseone()
{
    if (R==1){
        printf("c");
        for (int i = 1 ; i < R*C-M ; i ++ ) printf(".");
        for (int i = 1 ; i <= M ; i++ ) printf("*");
        printf("\n");return;
    }
    if (C==1){
        printf("c\n");
        for (int i = 1 ; i < R*C-M ; i ++ ) printf(".\n");
        for (int i = 1 ; i <= M ;i ++ ) printf("*\n");
        return;
    }
    if (R*C-M == 1) {
        printf("c");
        for (int i = 1 ; i <= C-1 ; i ++ ) printf("*");printf("\n");
        for (int i = 2 ; i <= R ; i ++ ){
            for (int j = 1 ; j <= C ; j ++ ) printf("*");
            printf("\n");
        }
        return;
    }    
}

void casetwo(int x , int y)
{
    char mat[R+1][C+1];
    for (int i = 1 ; i <= R ; i ++ ) 
        for (int j = 1 ; j <= C ; j ++ ) mat[i][j]='*';
    int ret = R*C - M - 2*x - 2*y + 4;
    for (int i = 1 ; i <= x ; i ++ ) mat[i][1]='.',mat[i][2]='.';
    for (int i = 1 ; i <= y ; i ++ ) mat[1][i]='.',mat[2][i]='.';
    for (int i = 1 ; i <= x ; i ++ ) 
        for (int j = 1 ; j <= y ; j ++ ) 
            if (mat[i][j]=='*' && ret>0) {
                ret -- ; mat[i][j]='.';
            }
    mat[1][1]='c';
    for (int i = 1 ; i <= R ; i ++ ){
        for (int j = 1 ; j <= C ; j ++ ) printf("%c",mat[i][j]);
        printf("\n");
    }
}

void check()
{
    if ((R==1) || (C==1) || (R*C-M==1)) {caseone();return;}
    for (int i = 2 ; i <= R ; i++ ) 
        for (int j = 2 ; j <= C ; j++) 
            if ((R*C-M<=i*j)&&(R*C-M-2*i-2*j+4>=0)){
                casetwo(i,j);return;
            }
    printf("Impossible\n");
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    for (int i = 1 ; i <= T ; i++ ) {
        cin>>R>>C>>M;
        cout<<"Case #"<<i<<":"<<endl;
        check();
    }
    //while(1){};
    return 0 ;
}
    
    
    
    
    
    
    
