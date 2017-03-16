//program A

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  freopen("Input.txt","r",stdin);
  freopen("Output.txt","w",stdout);
  int TotalTest,Test=0;scanf("%d",&TotalTest);
  while(Test++<TotalTest)
    {
      int N,M;scanf("%d%d",&N,&M);
      double P=1,Ans=M+2;
      for(int i=1;i<=N;i++)
        {
          double X;scanf("%lf",&X);P*=X;
          Ans=min(Ans,N-i+P*(M-i)+(1-P)*(M*2-i+1)+1);
        }
      printf("Case #%d: %0.10lf\n",Test,Ans);
    }
  return 0;
}
