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
  static int Fac[13];
  Fac[0]=1;
  for(int i=1;i<=12;i++)
    Fac[i]=Fac[i-1]*i;
  for(int Test=1;Test<=TotalTest;Test++)
    {
      printf("Case #%d:\n",Test);
      int R=Get(),N=Get(),M=Get(),K=Get();
      while(R--)
        {
          int C2=0,C3=0,C5=0,C7=0;
          for(int i=0;i<K;i++)
            {
              int X=Get();
              while(!(X%2)){X/=2;C2++;}
              while(!(X%3)){X/=3;C3++;}
              while(!(X%5)){X/=5;C5++;}
              while(!(X%7)){X/=7;C7++;}
            }
          C2=(C2+3)/6;
          C3=(C3+3)/6;
          C5=(C5+3)/6;
          C7=(C7+3)/6;
          int Rest=12-C5-C7,Total=0;
          static int A[10000][9],Poss[10000];
          for(int X4=0;X4*2<=C2;X4++)
            for(int X8=0;X8*3<=C2;X8++)
              for(int X3=0;X3<=C3;X3++)
                {
                  int X6=C3-X3;
                  int X2=C2-X6-X8*3-X4*2;
                  if(X2<0)
                    continue;
                  if(X2+X3+X4+X6+X8!=Rest)
                    continue;
                  A[Total][2]=X2;
                  A[Total][3]=X3;
                  A[Total][4]=X4;
                  A[Total][6]=X6;
                  A[Total][8]=X8;
                  Poss[Total]=Fac[Rest]/Fac[X2]/Fac[X3]/Fac[X4]/Fac[X6]/Fac[X8];
                  Total++;
                }
          if(!Total)
            {
              printf("222222222222\n");
              continue;
            }
          int Sum=0;
          for(int i=0;i<Total;i++)
            Sum+=Poss[i];
          int X=Random(Sum)+1;
          int X2,X3,X4,X6,X8;
          for(int i=0,j=0;i<Total;i++)
            {
              j+=Poss[i];
              if(j>=X)
                {
                  X2=A[i][2];
                  X3=A[i][3];
                  X4=A[i][4];
                  X6=A[i][6];
                  X8=A[i][8];
                  break;
                }
            }
          while(X2--)putchar('2');
          while(X3--)putchar('3');
          while(X4--)putchar('4');
          while(C5--)putchar('5');
          while(X6--)putchar('6');
          while(C7--)putchar('7');
          while(X8--)putchar('8');
          putchar('\n');
        }
    }
  return 0;
}
