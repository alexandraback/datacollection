#include <cstdio>
using namespace std;

int n;
int s[201], sum;

typedef long long LL;
const double EPS = 1e-12;
bool ok(int pos, double fraction) {
     double score = s[pos]+sum*(fraction/100);
     double total = 0;
     for(int i = 0; i < n; i++) {
             if(s[i]>score) continue;
             total += (score-s[i])/(double)sum;
     }
     return total>1.0;
}


int main() {
    freopen("A-small-attempt7.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    
    for(int testcase = 1; testcase <= t; testcase++) {
               scanf("%d", &n);
               
               sum = 0;
               for(int i = 0; i < n; i++) {
                       scanf("%d", &s[i]);
                       sum += s[i];
               }
               
               printf("Case #%d:", testcase);
               for(int i = 0; i < n; i++) {
                       double l = 0, r = 100;
                       while((r-l)>=EPS) {
                          double mid = l +(r-l)/2;               
                          if(!ok(i, mid))
                            l = mid;
                          else
                            r = mid;
                       }
                       printf(" %.6lf", l);
               }
               printf("\n");
    }
}
