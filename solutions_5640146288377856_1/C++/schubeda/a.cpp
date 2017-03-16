#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <tuple>
#include <numeric>
#include <cstring>

using namespace std;

typedef long long int ll;

int main() {

  freopen("in", "r", stdin);
  freopen("out", "w", stdout);

  int T;
  scanf("%d", &T);

  for (int t=1; t<=T; ++t) {
    printf("Case #%d: ", t);
    ll R, C, W;
    cin >> R >> C >> W;
    if (W==1) {cout << (R*C) << endl; continue;}
    ll result = C/W;
    if (C%W!=0) ++result;
    result += (W-1);
    result *= R;
    cout << result << endl;
  }
}
