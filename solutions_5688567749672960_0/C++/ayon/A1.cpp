#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<ctime>
#include<assert.h>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<limits.h>

using namespace std;

#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define EPS 1e-9
#define asdf exit(0);
#define AB(a) ((a)<(0) ? (-(a)) : (a))
#define EQ(a,b) ( (fabs((a)-(b))<EPS) ? (1) : (0))





typedef long long LL;
//typedef __int64 LL;





int dis[1000010];
queue<int> Q;




int rev(int now)
{
  int ret=0;
  while(now)
  {
    ret*=10;
    ret+=now%10;
    now/=10;
  }
  return ret;
}


vector<int> get(int now)
{
  vector<int> ret;
  ret.push_back(now+1);
  ret.push_back(rev(now));
  return ret;
}


int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int i,j,k;


    Q.push(1);
    dis[1]=1;

    while(!Q.empty())
    {
      int f=Q.front();Q.pop();
      vector<int> nextvals=get(f);
      for(i=0;i<nextvals.size();i++)
      {
        if(nextvals[i]<=1000000 && dis[nextvals[i]]==0)
        {
          dis[nextvals[i]]=dis[f]+1;
          Q.push(nextvals[i]);
        }
      }
    }




    int T;
    scanf("%d",&T);
    for(int cs=1;cs<=T;cs++)
    {
      printf("Case #%d: ",cs);
      int val;
      scanf("%d",&val);
      printf("%d\n",dis[val]);
    }

    return 0;
}
