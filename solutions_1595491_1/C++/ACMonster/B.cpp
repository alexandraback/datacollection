//program B

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
      int N,M,Min,Ans=0;scanf("%d%d%d",&N,&M,&Min);
      for(int i=0;i<N;i++)
        {
          int X;scanf("%d",&X);
          int K=X/3;X%=3;
          if(X==0)
            if(K>=Min)Ans++;
            else if(K>0&&K+1>=Min&&M){Ans++;M--;}
          if(X==1)
            if(K+1>=Min)Ans++;
          if(X==2)
            {
              if(K+1>=Min)Ans++;
              else if(K+2>=Min&&M){Ans++;M--;}
            }
        }
      printf("Case #%d: %d\n",Test,Ans);
    }
  return 0;
}
