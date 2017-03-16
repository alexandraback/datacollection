#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<functional>
#include<sstream>
#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;

#define DEBUG(x...) printf(x)
#define allv(v) (v).begin(),(v).end()
#define rall(v) (v).begin(),(v).rend()
#define _foreach(it,b,e) for(__typeof__(b); it!=(e);++it)
#define foreach(x...) _foreach(x)

typedef long long int huge;

const int inf = 0x3f3f3f3f;
const huge hugeinf = 0x3f3f3f3f3f3f3f3fll;//dois L's
const double eps = 1e-9;
const int maxn = 2222;
int n;
int p[maxn][2];
int d[maxn];
int main ()
{
  int tt;
  scanf("%d",&tt);
  for(int pp=1;pp<=tt;pp++)
    {
      memset(d,0,sizeof(d));
      scanf("%d",&n);
      for(int i=0;i<n;i++)
        scanf("%d %d",&p[i][0],&p[i][1]);
      
      int s = 0;
      int ans = 0;
      while(1){
        int at = -1;
        for(int i=0;at==-1 && i<n;i++){
          if(d[i]!=2 && p[i][1]<=s){
            at = i;
          }
        }
        
        if(at==-1){
          int mel = -1;
          for(int i=0;i<n;i++){
            if(d[i]==0 && p[i][0] <=s && p[i][1]>=mel){
              mel = p[i][1];
              at = i;
            }
          }
        }

        if(at==-1)break;
        ans++;
        if(p[at][1]<=s){
          s+=2-d[at];
          d[at]=2;
        } else {
          s+=1;
          d[at]=1;
        }

      }
      
      printf("Case #%d: ",pp);
      if(s!=2*n)printf("Too Bad\n");
      else printf("%d\n",ans);
    }
  return 0;
}
