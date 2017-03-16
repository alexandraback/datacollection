//program C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>

using namespace std;

int Calc(int N,int P,int X,int LB)
{
  int T=X;set<int> All;
  for(int i=1;i<N;i++)
    {
	  T=T/10+T%10*P;
      if(T<X&&T>=LB)All.insert(T);
    }
  return All.size();
}

int main()
{
  freopen("Input.txt","r",stdin);
  freopen("Output.txt","w",stdout);
  int TotalTest,Test=0;scanf("%d",&TotalTest);
  while(Test++<TotalTest)
    {
      int A,B,Ans=0;scanf("%d%d",&A,&B);
      int N=1,S=1;while(A>=S*10){S*=10;N++;}
      for(int i=A;i<=B;i++)Ans+=Calc(N,S,i,A);
      printf("Case #%d: %d\n",Test,Ans);
    }
  return 0;
}
