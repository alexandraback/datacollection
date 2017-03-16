//program B

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int Get()
{
  char c;
  while(c=getchar(),c<'0'||c>'9');
  int X=0;
  while(c>='0'&&c<='9')
    {
      X=X*10+c-48;
      c=getchar();
    }
  return X;
}

int main()
{
  int TotalTest=Get(),Test=0;
  while(TotalTest--)
    {
      printf("Case #%d: ",++Test);
      int M=Get(),N=Get();
      static int A[100][100];
      for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
          A[i][j]=Get();
      static int X[100],Y[100];
      memset(X,0,sizeof(X));
      memset(Y,0,sizeof(Y));
      for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
          {
            X[i]=max(X[i],A[i][j]);
            Y[j]=max(Y[j],A[i][j]);
          }
      bool Ans=true;
      for(int i=0;Ans&&i<M;i++)
        for(int j=0;Ans&&j<N;j++)
          if(A[i][j]!=min(X[i],Y[j]))
            Ans=false;
      printf(Ans?"YES\n":"NO\n");
    }
  return 0;
}
