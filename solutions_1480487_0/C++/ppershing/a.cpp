#include <stdio.h>
#define FOR(q,n) for(int q=0; q<n; q++)

void solve(int _case) {
  double res[100];
  int data[100];
  int n;
  int sum = 0;
  scanf("%d", &n);
  FOR(q, n) {
    scanf("%d", &data[q]);
    sum += data[q];
  }

  FOR(q, n) {
    double l = 0;
    double r = 1;
    FOR(i, 50) {
      double m = (l+r)/2;
      double mine_score = data[q] + sum * m;
      double s = 0;
      //printf("testing %lf\n", m);
      FOR(w, n) {
        double share = (mine_score - data[w])/sum;
        //printf("%lf\n", share);
        if (share > 0) {
            s += share;
        }
      }
      if (s < 1) {
        l = m;
      } else {
        r = m;
      }
    }
    res[q]=l;
  }

  printf("Case #%d:", _case);
  FOR(q, n) printf(" %lf", res[q] * 100);
  printf("\n");
}

int main() {
  int n;
  scanf("%d", &n);
  FOR(q, n) {
    solve(q+1);
  }
}
