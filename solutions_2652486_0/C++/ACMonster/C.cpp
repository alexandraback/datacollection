//program C

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

long long Choose(int N,int M)
{
  long long X=1;
  for(int i=0;i<M;i++)
    X*=N-i;
  for(int i=1;i<=M;i++)
    X/=i;
  return X;
}

int Random(int T)
{
  int X=(rand()<<15)|rand();
  return X%T;
}

int main()
{
  int TotalTest=Get();
  for(int Test=1;Test<=TotalTest;Test++)
    {
      printf("Case #%d:\n",Test);
      int R=Get(),N=Get(),M=Get(),K=Get();
      while(R--)
        {
          static int P[1000];
          for(int i=0;i<K;i++)
            P[i]=Get();
          int Total=0;
          static long long Poss[10000];
          static int _A[10000],_B[10000],_C[10000];
          for(int A=2;A<=M;A++)
            for(int B=2;B<=M;B++)
              for(int C=2;C<=M;C++)
                {
                  int X[3]={A,B,C};
                  int Set[8];
                  for(int i=0;i<8;i++)
                    {
                      Set[i]=1;
                      for(int j=0;j<3;j++)
                        if(i&(1<<j))
                          Set[i]*=X[j];
                    }
                  _A[Total]=A;
                  _B[Total]=B;
                  _C[Total]=C;
                  Poss[Total]=1;
                  for(int i=0;i<K;i++)
                    {
                      int Count=0;
                      for(int j=0;j<8;j++)
                        if(Set[j]==P[i])
                          Count++;
                      Poss[Total]*=Count;
                    }
                  Total++;
                }
          long long Sum=0;
          for(int i=0;i<Total;i++)
            Sum+=Poss[i];
          int T=Random(Sum)+1;
          for(int i=0,j=0;i<Total;i++)
            {
              j+=Poss[i];
              if(j>=T)
                {
                  printf("%d%d%d\n",_A[i],_B[i],_C[i]);
                  break;
                }
            }
        }
    }
  return 0;
}
