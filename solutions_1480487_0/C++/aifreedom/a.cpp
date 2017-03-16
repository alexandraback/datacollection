#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 207;
const double eps = 1e-8;
int n, m;
int s;
double ai;
int d[maxn];
double avg;
double p[maxn];
double q[maxn];
bool vi[maxn];
void init()
{
     s = 0;
     scanf("%d", &n);
     for (int i=0; i<n; i++) {
          scanf("%d", &d[i]);
          s += d[i];
     }
     for (int i=0; i<n; i++) {
          p[i] = double(d[i]) * 100 / s;
          // cout << p[i] << ' ';
     }
     // cout << endl;
}

void calc()
{
     m = n;
     for (int i=0; i<n; i++) {
          double l = 0.0, r = 100.0;
          
          while (fabs(r - l) > eps) {
               q[i] = (l + r) / 2;
               
               double ai = 100.0 - p[i];
               int rem = n - 1;
               double avg = (ai + 100.0 - q[i]) / rem;

               // memset(vi, 1, sizeof(vi));
               // vi[i] = 0;

               for (int j=0; j<n; j++) {
                    if (j != i && p[j] > avg) {
                         // flag = false;
                         vi[j] = 0;
                         ai -= p[j];
                         rem--;
                    }  
               }
               avg = (ai + 100.0 - q[i]) / rem;
               
               // if (i == 0)
               //      printf("%.5lf %.5lf %d %.5lf\n", q[i], p[i] + q[i], rem, avg);
               if (p[i] + q[i] >= avg) {
                    r = q[i];
               } else {
                    l = q[i];
               }
          }
          // if (i == 0)
          //      cout << endl;
          printf(" %.6lf", q[i]);
     }
     putchar('\n');
}


int main()
{
     int T;
     // cin >> T;
     scanf("%d", &T);
     for (int i=1; i<=T; i++) {
          init();
          printf("Case #%d:", i);
          calc();
     }
     return 0;
}
