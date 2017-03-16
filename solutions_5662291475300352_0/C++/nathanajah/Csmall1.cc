#include <bits/stdc++.h>
using namespace std;

int t;
vector <long long> d;
vector <long long> m;
int n;


int main() {
  int t =0;
  int n;
  scanf("%d", &t);
    int cs = 0;
  while (t--) {
    d.clear();
    m.clear();
    ++cs;
    printf("Case #%d: ", cs);
    int tmpn;
    scanf("%d", &tmpn);
    while (tmpn--) {
      int dd, hh, mm;
      scanf("%d %d %d", &dd, &hh, &mm);
      for (int i = 0; i < hh; i++) {
        d.push_back(dd);
        m.push_back(mm + i);
      }
    }
    n = (int)d.size();
    if (n == 1) {
      printf("0\n");
    } else if (n == 2) {
      if (m[0] > m[1]) {
        swap(m[0], m[1]);
        swap(d[0], d[1]);
      }
      if ((720LL - d[0]) * m[0] > (360LL - d[1]) * m[1]) {
        printf("0\n");
      } else {
        printf("1\n");
      }
    }
  }
}
