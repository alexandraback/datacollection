#include <stdio.h>
#include <stdlib.h>
#include<string.h>

 long calculate(char x[101],int N)
 {
     int i,j,k;
     int cnt = N,l;
     l = strlen(x);
     long int gc = 0;
     for(i=0;i<l;i++)
     {
         for(j=i;j<l;j++)
         {

             if(j-i+1>=N)
             {
                 cnt = N;
                 for(k=i;k<=j;k++)
                 {

                     if(x[k]!='a' && x[k]!='e' && x[k]!='i' && x[k]!='o' && x[k]!='u')
                     {
                        cnt--;
                     }
                     else
                        cnt = N;
                    if(cnt==0)
                    {
                     gc++;
                     break;
                    }
                 }
             }
         }
     }
     return gc;
 }

void clear(char x[101])
{
    int i;
    for(i=0;i<101;i++)
    x[i]='\0';
}


void solve(int T,FILE *fp1)
{
    char S[101];
    int i;
    int N;
    FILE *fp2;
    fp2 = fopen("p.out","w");
    //int S = 0,N = 0;

    for(i=0;i<T;i++)
    {
        clear (S);
        fscanf(fp1,"%s %d ",S,&N);
        fprintf(fp2,"Case #%d: ",i+1);
        fprintf(fp2,"%ld\n",calculate(S,N));
        //printf("H = %d, W = %d\n",H,W);
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

