#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct X
{
  int H, N, M;
  vector<vector<int> > ce, fl, sec;
  struct S
  {
    int r, c, s;
  };
  queue<S> q;

  void push(int r, int c, int s)
  {
    S x = { r, c, s };
    q.push(x);
  }

  void loop()
  {
    while (!q.empty()) {
      S x = q.front();
      q.pop();
      run(x.r, x.c, x.s);
    }
  }

  void run(int r, int c, int s)
  {
    if (sec[r][c] >= 0 && sec[r][c] <= s) return;

    sec[r][c] = s;
    run2(r, c, +1,  0);
    run2(r, c, -1,  0);
    run2(r, c,  0, +1);
    run2(r, c,  0, -1);
  }

  void run2(int r, int c, int dr, int dc)
  {
    int r2 = r + dr;
    int c2 = c + dc;
    if (0 > r2 || r2 >= N || 0 > c2 || c2 >= M) {
      return;
    }
    int s1 = sec[r][c];
    int ce1 = ce[r][c];
    int fl1 = fl[r][c];
    int ce2 = ce[r2][c2];
    int fl2 = fl[r2][c2];
    int h = H - s1;
    /*
    cout << r << ",";
    cout << c << ",";
    cout << r2 << ",";
    cout << c2 << ",";
    cout << s1 << ",";
    cout << h << endl;
    */

    if (0 > h) h = 0;
    if (ce2 - fl1 < 50) {
      return;
    }
    if (ce2 - fl2 < 50) {
      return;
    }
    if (ce1 - fl2 < 50) {
      return;
    }
    int wait = 0;
    if (ce2 - h < 50) {
      wait = 50 - (ce2 - h);
      h = ce2 - 50;
    }
    int s2 = 0;
    if (h - fl1 < 20) {
      s2 = s1 + wait + 100;
    } else {
      s2 = s1 + wait + 10;
    }
    if (s1 + wait == 0) {
      s2 = 0;
    }
    /*
    cout << wait << ",";
    cout << s2 << endl;
    */
    push(r2, c2, s2);
  }
};

int main()
{
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; cas++) {
    X x;
    cin >> x.H >> x.N >> x.M;

    for (int i = 0; i < x.N; i++) {
      x.ce.push_back(vector<int>());
      for (int j = 0; j < x.M; j++) {
        int y;
        cin >> y;
        x.ce.back().push_back(y);
      }
    }
    for (int i = 0; i < x.N; i++) {
      x.fl.push_back(vector<int>());
      for (int j = 0; j < x.M; j++) {
        int y;
        cin >> y;
        x.fl.back().push_back(y);
      }
    }
    vector<vector<int> > sec;
    for (int i = 0; i < x.N; i++) {
      x.sec.push_back(vector<int>());
      for (int j = 0; j < x.M; j++) {
        x.sec.back().push_back(-1);
      }
    }
    x.push(0, 0, 0);
    x.loop();

    double result = x.sec.back().back();
    cout << "Case #" << cas << ": " << result / 10 << endl;
  }

  return 0;
}
