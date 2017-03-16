#include<bits/stdc++.h>

#define s(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)

#define MP           make_pair
#define PB           push_back
#define REP(i, n)    for(int i = 0; i < n; i++)
#define INC(i, a, b) for(int i = a; i <= b; i++)
#define DEC(i, a, b) for(int i = a; i >= b; i--)
#define CLEAR(a)     memset(a, 0, sizeof a)

using namespace std;

typedef long long          LL;
typedef unsigned long long ULL;
typedef vector<int>        VI;
typedef pair<int, int>     II;
typedef vector<II>         VII;

int main()
{
      int t,n,a,b,c;
      double eps = 1e-10;
      s(t);
      REP(tt,t)
      {
            s(n);
            VII inp;
            REP(i,n)
            {
                  s(a);s(b);s(c);
                  INC(i,1,b)
                        inp.PB(MP(a,c+i-1));
            }
            if(inp.size()<=1)
            {
                  printf("Case #%d: 0\n",tt+1);
            }
            else
            {
                  sort(inp.begin(),inp.end());
                  int d0 = inp[0].first;
                  int d1 = inp[1].first;
                  int t0 = inp[0].second;
                  int t1 = inp[1].second;
                  if(inp[1].second==inp[0].second)
                        printf("Case #%d: 0\n",tt+1);
                  else
                  {
                        if(t0>t1)
                        {
                              double temp = d1 + (360.0/t1)*(t0*1.0*(360.0-d0)/360.0)-360;
                              if(temp>=360+eps)
                                    printf("Case #%d: 1\n",tt+1);
                              else
                                    printf("Case #%d: 0\n",tt+1);
                        }
                        else
                        {
                              double temp = d0 + (360.0/t0)*(t1*1.0*(360.0-d1)/360.0)-360;
                              if(temp>=360+eps)
                                    printf("Case #%d: 1\n",tt+1);
                              else
                                    printf("Case #%d: 0\n",tt+1);
                              
                        }
                  }
            }
      }     
      return 0;
}
