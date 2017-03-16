//program A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

long long Get()
{
  char c;
  while(c=getchar(),c<'0'||c>'9');
  long long X=0;
  while(c>='0'&&c<='9')
    {
      X=X*10+c-48;
      c=getchar();
    }
  return X;
}

bool OK(long long R,long long N,long long T)
{
  long double S=2*R-3;
  S*=N;
  long double _S=N*2;
  _S*=N+1;
  S+=_S;
  if(S-T>10000)
    return false;
  long long Size=2*R-1+2*N;
  Size*=N;
  return Size<=T;
}

int main()
{
  int TotalTest=Get();
  for(int Test=1;Test<=TotalTest;Test++)
    {
      long long R=Get(),T=Get();
      long long Left=0,Right=1;
      while(OK(R,Right,T))
        Right*=2;
      while(Left<Right)
        {
          long long Mid=(Left+Right+1)/2;
          if(OK(R,Mid,T))
            Left=Mid;
          else
            Right=Mid-1;
        }
      printf("Case #%d: ",Test);
      cout<<Left<<endl;
    }
  return 0;
}
