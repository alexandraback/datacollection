#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long num;

const int ML = 1000000;

struct attack {
  long long d;
  int s;
  int w, e;
};

bool cmp(const attack &a, const attack &b)
{
    return a.d < b.d;
}

bool test(attack &a, int *w) {
  for (int i = a.w; i <= a.e - 1; i++) {
    if (w[i] < a.s) return true;
  }
  return false;
}

void up(attack &a, int *w) {
  for (int i = a.w; i <= a.e - 1; i++) {
    if (w[i] < a.s) w[i] = a.s;
  }
}

int main() {
  int cases;
  cin >> cases;
  for (int c = 0; c < cases; c++) {
    num r = 0;
    int n;
    cin >> n;
    vector<attack> va;
    for (int i = 0; i < n; i++) {
      int d, m, w, e, s, dd, dp, ds;
      cin >> d >> m >> w >> e >> s >> dd >> dp >> ds;
      w += ML;
      e += ML;
      for (int j = 0; j < m; j++) {
        attack a;
        a.d = d;
        a.s = s;
        a.w = w;
        a.e = e;
        va.push_back(a);
        d += dd;
        s += ds;
        w += dp;
        e += dp;
      }
    }

    sort(va.begin(), va.end(), cmp);
    int *wall = (int*)calloc(2 * ML + 1, sizeof(int));

    int j = 0;
    vector<bool> succ(va.size(), false);
    while (j < va.size()) {      
      int d = va[j].d;
      // cerr << "d " << d << "\n";
      int k = j + 1;
      while (va[k].d == d) k++;
      
      for (int i = j; i < k; i++) {
        succ[i] = test(va[i], wall);
        if (succ[i]) r++;
      }
      for (int i = j; i < k; i++) {
        if (succ[i]) up(va[i], wall);
      }
      j = k;     
      // cerr << "r: " << r << "\n";
    }    

    // for (int i = 0; i < va.size(); i++) {
      // cerr << va[i].d << " " << va[i].s << " " << va[i].w - ML << ".." << va[i].e - ML << "; ";
    // }
    cout << "Case #" << c + 1 << ": " << r << "\n";
  }
  return 0;
}