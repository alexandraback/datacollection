#include<iostream>
#include<cstdio>

using namespace std;
#define deb 0
#define eps 1e-10
int main() {
  int T;
  scanf("%d",&T);
  for(int kase=0;kase<T;kase++) {
    int N;
    scanf("%d",&N);
    int points[N];
    int sum=0;
    for(int i=0;i<N;i++) {
      scanf("%d",&points[i]);
      sum +=points[i];
    }
    if(deb) cout << "SUM: " << sum;
    double minreq [N];
    for(int i=0;i<N;i++) {
      double low=0;
      double high = 1;
      while(high - low >=  eps) {
        double mid = low + (high-low)/2;
        double mpoints = sum*mid + points[i];
        double sums = mid;
        for(int j=0;j<N;j++) {
          if (j!=i) {
            double minr = (mpoints - points[j]) / sum;
            sums += minr;
            if (sums >= 1.0) break;
          }
        }
        if (sums >= 1.0) {
          high = mid;
        } else {
          low = mid;
        }
      }
      minreq[i] = low;
    }
    printf("Case #%d: ",kase+1);
    for(int i=0;i<N;i++) {
      printf("%f", minreq[i]*100);
      if (i != N-1) printf(" ");
    }
    printf("\n");
  }
}
