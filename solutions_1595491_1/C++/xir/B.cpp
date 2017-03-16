#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool comp (int i, int j) { return (j<i);}

int T=1,TC;
int N, S, p;
int n;

bool tt(int num, int p)
{
  
}

int main()
{
  for (scanf("%d ",&TC);T<=TC;++T)
  {
    int temp;
    vector<int> t;
    scanf("%d %d %d ",&N,&S,&p);
    for (int i=0;i<N;++i)
    {
      scanf("%d ",&temp);
      t.push_back(temp);
    }

    int count = 0;
    for (int i=0;i<N;++i)
    {
      int num = t[i];
      if (num == 0)
      {
        if (p == 0)
          ++count;
      }
      else if ((num+2)/3 >= p)
        ++count;
      else if (S>0 && (num+4)/3>=p)
      {
        ++count;
        --S;
      }
    }

    sort(t.begin(),t.end(),comp);
    printf("Case #%d: %d\n",T,count);
  }
  
  
}
