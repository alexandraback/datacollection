#include <cstdio>
#include <queue>
#include <set>

using namespace std;

int main()
{
   int T, t, N, a, b, i, x, y;
   priority_queue< pair<int,int> > L1, L2;
   set<int> D1, D2;
   
   for(scanf("%d", &T), t=1; t<=T; t++)
   {
      scanf("%d", &N);
      while(!L1.empty()) L1.pop();
      while(!L2.empty()) L2.pop();
      D1.clear();
      D2.clear();
      for(i=N; i--; )
      {
         scanf("%d %d", &a, &b);
         L1.push(make_pair(-a, i));
         L2.push(make_pair(-b, i));
      }
      
      for(x=y=0; ; )
      {
         while(!L2.empty() && L2.top().first>=x)
         {
            x-=D1.find(L2.top().second)==D1.end()?2:1;
            y++;
            D2.insert(L2.top().second);
            L2.pop();
         }
         if(L2.empty()) break;
         
         while(!L1.empty() && D2.find(L1.top().second)!=D2.end()) L1.pop();
         if(L1.empty() || L1.top().first<x) break;
         
         x--;
         y++;
         D1.insert(L1.top().second);
         L1.pop();
      }
      
      if(x==-2*N)
         printf("Case #%d: %d\n", t, y);
      else
         printf("Case #%d: Too Bad\n", t);
   }
   
   return 0;
}
