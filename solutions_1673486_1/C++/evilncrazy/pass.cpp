#include <cstdio>
#include <algorithm>

double probs[100002];

int main() {
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
   
   int tc; scanf("%d", &tc);
   
   for(int t = 1; t <= tc; t++) {
      int a, b;
      scanf("%d %d", &a, &b);
      
      double ac = 1;
      for(int i = 0; i < a; i++) {
         scanf("%lf", &probs[i]);      
         ac *= probs[i];
      }
      
      double keep = ac * ((b-a) + 1) + (1 - ac) * ((b-a)+b+2);
      double quit = b+2;
      double p = probs[0], best = 1 << 29;
      for(int i = 1; i < a; i++) {
         double bs = p * ((b-i)+1) + (1-p) * ((b-i)+b+2) + (a-i);
         p *= probs[i];
         best = std::min(bs, best);
         //printf("bs to %d char: %lf\n", i, bs);
      }
      
      //printf("keep: %lf\n", keep);
      //printf("quit: %lf\n", quit);
      printf("Case #%d: %.6lf\n", t, std::min(best, std::min(keep, quit)));
   }
}
