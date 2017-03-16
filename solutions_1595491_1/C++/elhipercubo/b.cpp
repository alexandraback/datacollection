#include <cstdio>
using namespace std;

int main() {
  int cases;
  scanf("%i", &cases);
  for (int ncase = 1; ncase <= cases; ++ncase) {
    int n, surp, p;
    scanf("%i%i%i", &n, &surp, &p);

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      int total;
      scanf("%i", &total);

      if ((total + 2) / 3 >= p) ++cnt;
      else if (surp > 0) {
        int rem = total % 3;
        bool use_surp = false;
        if (rem == 0) {
          if (total >= 3 && total / 3 + 1 >= p) 
            use_surp = true;
        } else if (rem == 2) {
          if (total >= 2 && (total + 4) / 3 >= p)
            use_surp = true;
        }

        if (use_surp) {
          ++cnt;
          --surp;
        }
      }
    }
    printf("Case #%i: %i\n", ncase, cnt);
  }
  return 0;
}
