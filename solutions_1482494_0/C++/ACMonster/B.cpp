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
      int N;scanf("%d",&N);printf("Case #%d: ",Test);
      int X[1000],Y[1000],Flag[1000];
      for(int i=0;i<N;i++)
        scanf("%d%d",&X[i],&Y[i]);
      int Current=0,Ans=0;
      memset(Flag,0,sizeof(Flag));
      while(Current<N*2&&Ans!=-1)
        {
          int V=-1;Ans++;
          for(int j=0;V==-1&&j<N;j++)
            if(Flag[j]!=2&&Current>=Y[j])
              V=j;
          if(V!=-1){Current+=2-Flag[V];Flag[V]=2;continue;}
          int Max=V=-1;
          for(int j=0;j<N;j++)
            if(!Flag[j]&&Current>=X[j]&&Y[j]>Max)
              {Max=Y[j];V=j;}
          if(V==-1)
            Ans=-1;
          else
            {
              Flag[V]=1;
              Current++;
            }
        }
      if(Ans==-1)
        printf("Too Bad\n");
      else
        printf("%d\n",Ans);
    }
  return 0;
}
