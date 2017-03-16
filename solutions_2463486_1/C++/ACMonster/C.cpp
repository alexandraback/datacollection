//program C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int Ans[10000001];

bool OK(long long N)
{
  int Len=0,Data[20];
  while(N)
    {
      Data[Len++]=N%10;
      N/=10;
    }
  for(int i=0,j=Len-1;i<j;i++,j--)
    if(Data[i]!=Data[j])
      return false;
  return true;
}

void Init()
{
  Ans[0]=0;
  for(int i=1;i<=10000000;i++)
    {
      Ans[i]=Ans[i-1];
      if(OK(i)&&OK((long long)i*i))
        Ans[i]++;
    }
}

int Solve(long long X)
{
  int T=(int)sqrt(X);
  while((long long)(T+1)*(T+1)<=X)
    T++;
  return Ans[T];
}

int main()
{
  int TotalTest,Test=0;
  scanf("%d",&TotalTest);
  Init();
  while(TotalTest--)
    {
      long long L,R;
      cin>>L>>R;
      printf("Case #%d: %d\n",++Test,Solve(R)-Solve(L-1));
    }
  return 0;
}
