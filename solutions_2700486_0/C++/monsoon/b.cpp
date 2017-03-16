#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)



int brut(int n, int x, int y) {
   set<pair<int,int> > s;
   REP(i,n) {
      int xx=0, yy=10;
      while (yy > 0) {
         if (s.find(make_pair(xx,yy-2)) == s.end() && s.find(make_pair(xx-1,yy-1)) == s.end() && s.find(make_pair(xx+1,yy-1)) == s.end()) yy-=2;
         else if (s.find(make_pair(xx-1,yy-1)) != s.end() && s.find(make_pair(xx+1,yy-1)) != s.end()) {
            break;
         }
         else if (s.find(make_pair(xx-1,yy-1)) != s.end()) xx+=1, yy--;
         else if (s.find(make_pair(xx+1,yy-1)) != s.end()) xx-=1, yy--;
         else {
            xx += random()%2 ? -1 : 1;
            yy--;
         }
      }
      s.insert(make_pair(xx,yy));
   }
   return s.find(make_pair(x,y)) != s.end();
}
double probbrut(int n, int x, int y) {
   double pr = 0; int ile = 10000;
   REP(i,ile) {
      pr += brut(n,x,y);
   }
   return pr / ile;
}



int dowarstwy(int k) { return (k+1)*(2*k+1); }

double binom(int n, int k) {
   double p = 1;
   REP(i,k) {
      p = p * (n-i) / (k-i);
   }
   return p;
}

double rob(int n, int x, int y) {
   if ((abs(x)+y)%2==1 || y < 0) return 0;
   int k = (abs(x)+y)/2;
   if (dowarstwy(k) <= n) return 1;
   if (dowarstwy(k-1) >= n) return 0;

   int m = n - dowarstwy(k-1);
//   printf("k=%d m=%d\n",k,m);
   double pr = 0, sr = 0;
   for(int i = y+1; i <= min(m, 2*k); ++i) {
      if (0<= m-i && m-i <= 2*k)
//      printf("bin %d %d\n",m,i);
      pr += binom(m,i);
   }
   for(int i = 0; i <= 2*k; ++i)
      if (0<= m-i && m-i <= 2*k)
         sr += binom(m,i);
   //printf("pr=%lf sr=%lf\n",pr,sr);
   return pr / sr;
}

int main() {
   int Te;
   scanf("%d",&Te);
   REP(te,Te) {
      int n,x,y;
      scanf("%d%d%d",&n,&x,&y);
      //double prob = rob(n,x,y);
      double pr2 = probbrut(n,x,y);
      double best = 1000, odl = 1000;
      REP(i,33) {
         if (fabs(pr2 - i/32.) < odl) { best = i/32., odl = fabs(pr2-i/32.); }
      }
      printf("Case #%d: %.9lf\n", te+1, best);
      //printf("Case #%d: %lf   %lf\n", te+1, prob, pr2);
      //if ( fabs(prob-pr2) > 1e-2) printf("ZLE!!\n");
   }
}
