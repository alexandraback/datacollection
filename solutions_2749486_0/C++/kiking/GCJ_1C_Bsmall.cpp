#include<cstdio>
int T, X, Y;
int main(){
    freopen("GCJ_1C_Bsmall.in","r",stdin);
    freopen("GCJ_1C_Bsmall.out","w",stdout);
    scanf("%d",&T);
    for (int i = 0; i < T; i++){
        scanf("%d%d",&X,&Y);
        printf("Case #%d: ",i+1);
        if (Y < 0)
           for (int j = 0; j > Y; j--)printf("NS");
        else
           for (int j = 0; j < Y; j++)printf("SN");
        if (X < 0)
           for (int j = 0; j > X; j--)printf("EW");
        else
           for (int j = 0; j < X; j++)printf("WE");
        printf("\n");
    }
    scanf("\n");
    return 0;
}
