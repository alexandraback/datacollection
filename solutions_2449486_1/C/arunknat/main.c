#include <stdio.h>
#include <stdlib.h>

void inita(int a[100][100])
{
    int i,j;
    for(i=0;i<100;i++)
    for(j=0;j<100;j++)
    a[i][j] = 0;
}



int solveP(int H,int W,FILE *fp1)
{
    int arr[100][100];
    int i,j,i1,flr,flc;
    int t = 0;
    inita(arr);
    //initan(ans);

    for(i=0;i<H;i++)
    for(j=0;j<W;j++)
    {
        fscanf(fp1,"%d ",&arr[i][j]);
    }
    for(i=0;i<H;i++)
    {

        for(j=0;j<W;j++)
        {
            for(i1=0;i1<W;i1++)
            if(arr[i][i1]>arr[i][j])
            {
            flr = 1;
           // printf("\n** %d %d (%d,%d)",arr[i][i1],arr[i][j],i,j);
            }

            for(i1=0;i1<H;i1++)
            if(arr[i1][j]>arr[i][j])
            flc = 1;
            if(flr == 1 && flc == 1)
            {
             //   printf("\n$$ %d %d %d\n",i,j,arr[i][j]);
               // for(i1=0;i1<W;i1++)
                //printf("## %d ",arr[i][i1]);
                return 1;
            }
             flr = 0;
             flc = 0;

        }
        //printf("\n");
    }
    return 0;

}

void solve(int T,FILE *fp1)
{
    int i;
    FILE *fp2;
    fp2 = fopen("p.out","w");
    int H = 0,W = 0;
    for(i=0;i<T;i++)
    {
        fprintf(fp2,"Case #%d: ",i+1);
        fscanf(fp1,"%d %d ",&H,&W);
        //printf("H = %d, W = %d\n",H,W);
        if(solveP(H,W,fp1)==0)
        fprintf(fp2,"YES\n");
        else
        fprintf(fp2,"NO\n");
    }
}




int main()
{
    FILE *fp1;
    int T = 0;
    fp1 = fopen("A-small-practice.in","r");
    fscanf(fp1,"%d",&T);
    solve(T,fp1);
    printf("T = %d\n",T);
    return 0;
}

