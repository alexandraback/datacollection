#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

FILE *x;
FILE *y;
int N,trovato=0;

/*typedef struct x
{
        int nodo;
        int vettore[1000];
} classe;*/

int V[1000][1000];
int ans[1000][1000];

void foo (int i,int j)
{
     int k,t,p,l;
     //printf("%d %d\n",i,j);
     
         for(k=0;k<N;k++)
         {                  
                         if(V[j][k]==1)
                         {
                                       
                                       ans[i][k]++;
                                       if(ans[i][k]==2)
                                       {
                                       trovato=1;
                                       return;
                                       }
                                                                     
                                       /*for(p=0;p<N;p++)
                                       {
                                       for(l=0;l<N;l++)
                                       printf("%d",ans[p][l]);
                                       printf("\n");
                                       }
                                       system("pause");*/
                                                                     
                                                                     
                                       foo(i,k);
                         }
                                       
                         
         }
                         
}   


int solve()
{
    int j,M,i,el,p,l;
    
    
    
    trovato=0;
    
    fscanf(x,"%d",&N);
    for(i=0;i<N;i++)
    for(j=0;j<N;j++)
    V[i][j]=0;
    for(i=0;i<N;i++)
    for(j=0;j<N;j++)
    ans[i][j]=0;
    
    
    for(j=0;j<N;j++)
    {
                  fscanf(x,"%d",&M);
                  for(i=0;i<M;i++)
                  {
                                  fscanf(x,"%d",&el);
                                  V[j][el-1]=1;
                                  ans[j][el-1]=1;
                  } 
    }
    
    
    
    
    for(j=0;j<N&&(!trovato);j++)
    {
                                for(i=0;i<N;i++)
                                {
                                                if(V[j][i])
                                                foo(j,i);
                                }
                    
    }
    
    
    if(trovato)
    fprintf(y,"Yes\n");
    else fprintf(y,"No\n");
}

int main()
{
    int i,T;
    x=fopen("input.txt","r");
    //x=fopen("-small-attempt0.in","r");
    //x=fopen("-large.in","r");
    y=fopen("output.txt","w");
    fscanf(x,"%d",&T);
    
    for(i=1;i<=T;i++)
    {
                     
                     fprintf(y,"Case #%d: ",i);
                     solve();
                     
    }
    //system("pause");
    fclose(x);
    fclose(y);
    return 0;
}
