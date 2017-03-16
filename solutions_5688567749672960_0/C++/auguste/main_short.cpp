#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int dist[10000001];

int main()
{
   int T;
   scanf("%d", &T);
   for(int _i=1; _i<=T; _i++)
   {
      int n;
      scanf("%d", &n);
      fill(dist, dist+10000000, -1);
      queue<int> file;
      file.push(1);
      dist[1] = 1;
      while(!file.empty()){
         int x = file.front();
         file.pop();
         if(x == n) 
            break;
         if(x >= 10000000)
            continue;
         if(dist[x+1] == -1)
         {
            dist[x+1] = dist[x] + 1;
            file.push(x+1);
         }
         int rev = 0, y = x;
         while(y > 0)
         {
            rev = rev*10 + (y % 10);
            y /= 10;
         }
         //printf("%d %d\n", x, rev);
         if(dist[rev] == -1)
         {
            dist[rev] = dist[x] + 1;
            file.push(rev);
         }
      }

      printf("Case #%d: %d\n",_i, dist[n]);
   }
   return 0;
}
