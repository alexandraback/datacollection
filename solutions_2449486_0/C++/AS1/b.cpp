#include <cstdio>
#include <vector>


using namespace std;

void eq_fix (int *x, int y) {
  if (*x == 0) {
    *x = y;
    return;
  }
  if (*x != y) {
    *x = -1;
    return;
  }
}

bool get (vector <vector <int> > v, int h, int w) {
  for (int num = 1; num <= 100; num++) {
    vector <int> eq_h(h);
    vector <int> eq_w(w);
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        int x = v[i][j];
        eq_fix (&eq_h[i], x);
        eq_fix (&eq_w[j], x);
      }
    }

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        int x = v[i][j];
        if (x != num) {
          continue;
        }
        if (eq_h[i] != x && eq_w[j] != x) {
          return false;
        }
        v[i][j] = num + 1;
      }
    }
  }
  return true;
}
void solve() {
  int h, w;
  scanf ("%d%d", &h, &w);
  vector <vector <int> > v (h, vector <int> (w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      scanf ("%d", &v[i][j]);
    }
  }
 
  bool res = get (v, h, w);

  printf (res ? "YES\n" : "NO\n");
}
int main (void) {
  int tn;
  scanf ("%d", &tn);
  for (int ti = 1; ti <= tn; ti++) {
    printf ("Case #%d: ", ti);
    solve();
  }
  return 0;
}
