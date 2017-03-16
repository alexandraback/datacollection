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
  int TotalTest=Get();
  for(int Test=1;Test<=TotalTest;Test++)
    {
      long long E=Get(),R=Get();
      int N=Get();
      static int Value[10000];
      for(int i=0;i<N;i++)
        Value[i]=Get();
      static int DP[11][6];
      memset(DP,0,sizeof(DP));
      for(int i=N-1;i>=0;i--)
        for(int j=0;j<=E;j++)
          for(int k=0;k<=j;k++)
            DP[i][j]=max(DP[i][j],k*Value[i]+DP[i+1][min(j-k+R,E)]);
      printf("Case #%d: %d\n",Test,DP[0][E]);
    }
  return 0;
}
