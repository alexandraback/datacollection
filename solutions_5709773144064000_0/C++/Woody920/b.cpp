#include <cstdio>
using namespace std;

int counter = 0;

double c; //farm cost
double f; //farm rate
double x; //needed for win


void runCase() {
    printf("Case #%d: ", ++counter);
    scanf("%lf %lf %lf", &c, &f, &x);
    
    
    double cps = 2;
    double t = 0;
    while(true) {
       double timeToRepay = x / (cps + f) + (c / cps);
       double timeToWin = x / cps;
       
       if(timeToRepay < timeToWin) {
        //  printf("timeToRepay < timeToWin\n");
         // printf("%lf < %lf\n", timeToRepay, timeToWin);
          
          t += (c/cps);
          cps += f;
          continue;
       } else {
          t += timeToWin;
          printf("%.7f\n", t);
          return;
       }
    
    }
   
    
    
    
    return;
}
void preprocess() {
   
}
int main() {
   preprocess();
   
    int t; scanf("%d", &t);
    while(t--) {
        runCase();
    }
    return 0;
}


//  n, m, 2 numbers per line
//    int n, m; scanf("%d %d", &n, &m);


/* GRID - N x M  
int n, m; scanf("%d %d", &n, &m);
 for (int i=0; i<n; ++i) {
     for (int j=0; j<m; ++j) {
         scanf("%d", &t[i][j]);
     }
 }
 */