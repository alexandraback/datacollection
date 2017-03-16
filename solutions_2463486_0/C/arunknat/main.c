#include <stdio.h>
#include <stdlib.h>

/*void inita(int a[100][100])
{
    int i,j;
    for(i=0;i<100;i++)
    for(j=0;j<100;j++)
    a[i][j] = 0;
}



int solveP(int H,int W)
{


}*/

void solve(int T,FILE *fp1)
{
    int i,cnt = 0;;
    FILE *fp2;
    fp2 = fopen("p.out","w");
    //char H[101],W[101];
    int H,W;
    for(i=0;i<T;i++)
    {
        cnt = 0;
        fprintf(fp2,"Case #%d: ",i+1);
        fscanf(fp1,"%d %d ",&H,&W);
        if(H<=1 && W>=1) cnt++;
        if(H<=4 && W>=4) cnt++;
        if(H<=9 && W>=9) cnt++;
        if(H<=121 && W>=121) cnt++;
        if(H<=484 && W>=484) cnt++;
        //printf("H = %d, W = %d\n",H,W);
        fprintf(fp2,"%d\n",cnt);


    }
}




int main()
{
    FILE *fp1;
   // long long a;
    //long int g;
    //printf("a - %d",sizeof(g));
   // a = 100*10000000;
    //printf("\n a = %d",a);
    int T = 0;
    fp1 = fopen("A-small-practice.in","r");
    fscanf(fp1,"%d",&T);
    solve(T,fp1);
    printf("T = %d\n",T);
    return 0;
}

