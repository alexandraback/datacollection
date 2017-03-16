#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Hk
{
  int d;
  int m;
};

int main()
{
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; cas++) {
    int N;
    cin >> N;
    vector<Hk> vs;
    for (int i = 0; i < N; i++) {
      int D, H, M;
      cin >> D >> H >> M;
      for (int j = 0; j < H; j++) {
        Hk x;
        x.d = D;
        x.m = M + j;
        vs.push_back(x);
      }
    }
    int res = 114514;

    if (vs.size() <= 1) {
      res = 0;
    } else if (vs.size() == 2) {
      Hk h0 = vs[0];
      Hk h1 = vs[1];
      if (h0.d > h1.d) swap(h0, h1);
      else if (h0.d == h1.d && h0.m < h1.m) swap(h0, h1);
      
      // t1 = (360 - h0.d) / 360 * h0.m
      // d3 = h1.d + t1 / h1.m * 360
      // d3 < 720 ???
      //   h1.d + t1 / h1.m * 360 < 720
      //   h1.d + ((360 - h0.d) / 360 * h0.m) / h1.m * 360 < 720
      //   h1.d + ((360 - h0.d) * h0.m) / h1.m < 720
      //   ((360 - h0.d) * h0.m) < (720 - h1.d) * h1.m
      //
      if ((360 - h0.d) * h0.m < (720 - h1.d) * h1.m) {
        res = 0;
      } else {
        res = 1;
      }
    }
    cout << "Case #" << cas << ": " << res << endl;
  }
  return 0;
}
