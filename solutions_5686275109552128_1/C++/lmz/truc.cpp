#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ul;

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(false);
  int total_tc;
  cin >> total_tc;
  int ps[2000];
  for (int tc = 1; tc <= total_tc; ++tc) {
    int d;
    cin >> d;
    int max_p = 0;
    for (int i = 0; i < d; ++i) {
      cin >> ps[i];
      max_p = max(max_p, ps[i]);
    }
    int res = max_p;
    for (int last = 1; last <= max_p; ++last) {
      int nb_div = 0;
      for (int i = 0; i < d; ++i) {
        nb_div += (ps[i]-1)/last;
      }
      int tmp = last + nb_div;
      res = min(tmp, res);
    }
    printf("Case #%d: %d\n", tc, res);
  }

  return 0;
}
