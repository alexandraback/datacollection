#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int M = 1000;

int nbTests;

struct T{
   int d, n, e, w, s, delta_d, delta_p, delta_s;
   bool operator<(const T &x) const
   {
      return d > x.d;
   }
};

int h1[1000];
int h2[1000];

int main()
{
   scanf("%d", &nbTests);
   for(int test=0; test<nbTests; test++)
   {
      priority_queue<T> tr;
      int N;
      scanf("%d", &N);
      fill(h1, h1+1000, 0);
      fill(h2, h2+1000, 0);
      for(int i=0; i<N; i++)
      {
         T t;
         scanf("%d%d%d%d%d%d%d%d", &t.d, &t.n, &t.w, &t.e, &t.s, &t.delta_d, &t.delta_p, &t.delta_s);
         tr.push(t);
      }
      int nb = 0;
      int day = 0;
      while(!tr.empty())
      {
         T t = tr.top();
         tr.pop();
        // printf("%d %d %d %d   %d\n", t.d, t.w, t.e, t.s, nb);
         if(t.d > day)
         {
            day = t.d;
            for(int i=0; i<1000; i++)
               h1[i] = h2[i];
         }
         for(int i=t.w; i<t.e; i++)
            if(h1[500+i] < t.s)
            {
               nb++;
               break;
            }
         for(int i=t.w; i<t.e; i++)
            h2[500+i] = max(h2[500+i], t.s);
         if(t.n > 1)
         {
            t.n = t.n - 1;
            t.d = t.d + t.delta_d;
            t.s = t.s + t.delta_s;
            t.e = t.e + t.delta_p;
            t.w = t.w + t.delta_p;
            tr.push(t);
         }
      }
      printf("Case #%d: %d\n", test+1, nb);
   }
}
