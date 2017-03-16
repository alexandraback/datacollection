#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

FILE *x;
FILE *y;
double H,h1;
int N,M;
double terra[100][100];
double soffitto[100][100];
double ans[100][100];

void foo(int i, int j)
{
     double time;
     h1=H-10*ans[i][j];
     if(ans[i][j]!=0)
     {
                     if(h1-terra[i][j]>=20)
                     time=1;
                     else
                     time=10;
     }
     else
     {
         time=0;
     }
     if(i+1<N)
     {
              if(soffitto[i+1][j]-terra[i+1][j]>= 50 &&  soffitto[i+1][j]-terra[i][j] >=50 && soffitto[i][j]-terra[i+1][j] >=50)
              {
                                                  if(soffitto[i+1][j]-h1>=50)
                                                  {
                                                                             if(ans[i+1][j]>ans[i][j]+time || ans[i+1][j]==-1)
                                                                             {
                                                                                                       ans[i+1][j]=ans[i][j]+time;
                                                                                                       foo(i+1,j);
                                                                             }
                                                  }
                                                  else
                                                  {
                                                      time=(50-(soffitto[i+1][j]-h1))/10;
                                                      if(h1-10*time-terra[i][j]>=20)
                                                      time=time+1;
                                                      else time=time+10;
                                                      if(ans[i+1][j]>ans[i][j]+time || ans[i+1][j]==-1)
                                                                             {
                                                                                                       ans[i+1][j]=ans[i][j]+time;
                                                                                                       foo(i+1,j);
                                                                             }
                                                  }
              }
     }
     if(i-1>=0)
     {
              if(soffitto[i-1][j]-terra[i-1][j]>= 50 &&  soffitto[i-1][j]-terra[i][j] >=50 && soffitto[i][j]-terra[i-1][j] >=50)
              {
                                                  if(soffitto[i-1][j]-h1>=50)
                                                  {
                                                                             if(ans[i-1][j]>ans[i][j]+time || ans[i-1][j]==-1)
                                                                             {
                                                                                                       ans[i-1][j]=ans[i][j]+time;
                                                                                                       foo(i-1,j);
                                                                             }
                                                  }
                                                  else
                                                  {
                                                      time=(50-(soffitto[i-1][j]-h1))/10;
                                                      if(h1-10*time-terra[i][j]>=20)
                                                      time=time+1;
                                                      else time=time+10;
                                                      if(ans[i-1][j]>ans[i][j]+time || ans[i-1][j]==-1)
                                                                             {
                                                                                                       ans[i-1][j]=ans[i][j]+time;
                                                                                                       foo(i-1,j);
                                                                             }
                                                  }
              }
     }
     if(j+1<M)
     {
              if(soffitto[i][j+1]-terra[i][j+1]>= 50 &&  soffitto[i][j+1]-terra[i][j] >=50 && soffitto[i][j]-terra[i][j+1] >=50)
              {
                                                  if(soffitto[i][j+1]-h1>=50)
                                                  {
                                                                             if(ans[i][j+1]>ans[i][j]+time || ans[i][j+1]==-1)
                                                                             {
                                                                                                       ans[i][j+1]=ans[i][j]+time;
                                                                                                       foo(i,j+1);
                                                                             }
                                                  }
                                                  else
                                                  {
                                                      time=(50-(soffitto[i][j+1]-h1))/10;
                                                      if(h1-10*time-terra[i][j]>=20)
                                                      time=time+1;
                                                      else time=time+10;
                                                      if(ans[i][j+1]>ans[i][j]+time || ans[i][j+1]==-1)
                                                                             {
                                                                                                       ans[i][j+1]=ans[i][j]+time;
                                                                                                       foo(i,j+1);
                                                                             }
                                                  }
              }
     }
     if(j-1>=0)
     {
              if(soffitto[i][j-1]-terra[i][j-1]>= 50 &&  soffitto[i][j-1]-terra[i][j] >=50 && soffitto[i][j]-terra[i][j-1] >=50)
              {
                                                  if(soffitto[i][j-1]-h1>=50)
                                                  {
                                                                             if(ans[i][j-1]>ans[i][j]+time || ans[i][j-1]==-1)
                                                                             {
                                                                                                       ans[i][j-1]=ans[i][j]+time;
                                                                                                       foo(i,j-1);
                                                                             }
                                                  }
                                                  else
                                                  {
                                                      time=(50-(soffitto[i][j-1]-h1))/10;
                                                      if(h1-10*time-terra[i][j]>=20)
                                                      time=time+1;
                                                      else time=time+10;
                                                      if(ans[i][j-1]>ans[i][j]+time || ans[i][j-1]==-1)
                                                                             {
                                                                                                       ans[i][j-1]=ans[i][j]+time;
                                                                                                       foo(i,j-1);
                                                                             }
                                                  }
              }
     }
}

int solve()
{
    int i,j;
    fscanf(x,"%lf",&H);
    fscanf(x,"%d",&N);
    fscanf(x,"%d",&M);
    
    
    
    for(i=0;i<N;i++)
    for(j=0;j<M;j++)
    fscanf(x,"%lf",&soffitto[i][j]);
    
    for(i=0;i<N;i++)
    for(j=0;j<M;j++)
    fscanf(x,"%lf",&terra[i][j]);
    
    for(i=0;i<N;i++)
    for(j=0;j<M;j++)
    ans[i][j]=-1;
    
    
    ans[0][0]=0;
    
    foo(0,0);
    
    fprintf(y,"%.1lf\n",ans[N-1][M-1]);
    
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
