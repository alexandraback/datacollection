//program D

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>

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
      int K=Get(),N=Get();
      static int Count[200];
      memset(Count,0,sizeof(Count));
      for(int i=0;i<K;i++)
        Count[Get()-1]++;
      static int Type[20];
      static vector<int> List[20];
      for(int i=0;i<N;i++)
        List[i].clear();
      for(int i=0;i<N;i++)
        {
          Type[i]=Get()-1;
          int Total=Get();
          while(Total--)
            List[i].push_back(Get()-1);
        }
      static bool DP[1048576];
      static int Best[1048576];
      memset(DP,0,sizeof(DP));
      DP[(1<<N)-1]=true;
      for(int i=(1<<N)-2;i>=0;i--)
        {
          static int Key[200];
          for(int j=0;j<200;j++)
            Key[j]=Count[j];
          for(int j=0;j<N;j++)
            if(i&(1<<j))
              {
                Key[Type[j]]--;
                for(int k=0;k<List[j].size();k++)
                  Key[List[j][k]]++;
              }
          for(int j=0;!DP[i]&&j<N;j++)
            if(~i&(1<<j)&&Key[Type[j]])
              if(DP[i|(1<<j)])
                {
                  DP[i]=true;
                  Best[i]=j;
                }
        }
      printf("Case #%d:",++Test);
      if(!DP[0])
        printf(" IMPOSSIBLE\n");
      else
        {
          int P=0;
          for(int i=0;i<N;i++)
            {
              printf(" %d",Best[P]+1);
              P|=1<<Best[P];
            }
          putchar('\n');
        }
    }
  return 0;
}
