#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

FILE *x;
FILE *y;

typedef struct x
{
        long long int a;
        int b;
} box;
int N,M;

box A[100];
box B[100];
long long int Mat[100][100];

long long int max(long long int a, long long int b)
{
     if(a>b)
     return a;
     return b;
}


long long int foo(int i, int j)
{
        box AppA[100];
        box AppB[100];
        long long int cont=0;
        int p;
        
        cont=Mat[i][j];
        
        if(cont==-1)
        cont=0;
        
        
        if(i==N||j==M)
        return 0;
        
        if(Mat[i][j]!=-1)
        return Mat[i][j];
        
        for(p=0;p<N;p++)
        {
        AppA[p].a=A[p].a;
        AppA[p].b=A[p].b;
        }
        for(p=0;p<M;p++)
        {
        AppB[p].a=B[p].a;
        AppB[p].b=B[p].b;
        }
        
        
        if(A[i].b==B[j].b)
        {
                          if(A[i].a>B[j].a)
                          {
                                           A[i].a=A[i].a-B[j].a;
                                           cont=B[j].a+foo(i,j+1);
                          }
                          else if(A[i].a<B[j].a)
                          {
                                           B[j].a=B[j].a-A[i].a;
                                           cont=A[i].a+foo(i+1,j);
                          }
                          else
                          {
                               cont=A[i].a+foo(i+1,j+1);
                          }
        }
        else
        {
            long long int e1,e2;
            e1=foo(i+1,j);
            for(p=0;p<N;p++)
            {
            A[p].a=AppA[p].a;
            A[p].b=AppA[p].b;
            }
            for(p=0;p<M;p++)
            {
            B[p].a=AppB[p].a;
            B[p].b=AppB[p].b;
            }
            e2=foo(i,j+1);
            cont=max(e1,e2);
        }
        Mat[i][j]=cont;
        return cont;
}




int solve()
{
    int i,j;
    long long int ans;
    fscanf(x,"%d",&N);
    fscanf(x,"%d",&M);
    
    for(i=0;i<N;i++)
    for(j=0;j<M;j++)
    Mat[i][j]=-1;
    
    
    for(i=0;i<N;i++)
    {
                    int a,aa;
                    fscanf(x,"%lld",&A[i].a);
                    fscanf(x,"%d",&A[i].b);                    
    }
    for(i=0;i<M;i++)
    {
                    int a,aa;
                    fscanf(x,"%lld",&B[i].a);
                    fscanf(x,"%d",&B[i].b);                   
    }
    
    ans=foo(0,0);
    fprintf(y,"%lld\n",ans);
    
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
    fclose(x);
    fclose(y);
    return 0;
    
}
