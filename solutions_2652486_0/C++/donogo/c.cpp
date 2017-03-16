#include <iostream>
#include <vector>
#include <string>

using namespace std;


int val(int x, int p) {
  int v = 0;
  while (x % p == 0) {
    v++;
    x /= p;
  }
  return v;
}

vector <int> guess(vector <int> prod) {
  int v2, v3, v5;
  int v2max, v3max, v5max;
  int i;
  int rem;
  vector <int> g;
  v2max = v3max = v5max = 0;
  for (i = 0; i < prod.size(); i++) {
    v2 = val(prod[i], 2);
    if (v2max < v2) v2max = v2;
    v3 = val(prod[i], 3);
    if (v3max < v3) v3max = v3;
    v5 = val(prod[i], 5);
    if (v5max < v5) v5max = v5;
  }
  rem = 3;

  for (i = 0; i < v5max; i++) {
    g.push_back(5);
    rem--;
  }
  for (i = 0; i < v3max; i++) {
    g.push_back(3);
    rem--;
  }

  if (rem == 0) {
    return g;
  }

  switch(rem) {
  case 1:
    if (v2max == 2) g.push_back(4);
    else g.push_back(2);
    return g;
  case 2:
    if (v2max == 4) { g.push_back(4); g.push_back(4); return g; }
    else if (v2max == 3) { g.push_back(4); g.push_back(2); return g; }
    else if (v2max == 2) { g.push_back(2); g.push_back(2); return g; }
    else { g.push_back(2); g.push_back(2); return g; }
  default:
    if (v2max > 4) { g.push_back(4); g.push_back(4); g.push_back(4);return g; }
    else if (v2max == 4) { g.push_back(4); g.push_back(4); g.push_back(2);return g; }
    else if (v2max == 3) { g.push_back(2); g.push_back(2); g.push_back(4); return g; }
    else if (v2max == 2) { g.push_back(2); g.push_back(2); g.push_back(4); return g; }
    else { g.push_back(2); g.push_back(2); g.push_back(2); return g; }
    return g;
  }

  return g;
  
}

int main(void) {
  int T, c;
  int R, N, M, K, r, k;


  cin >> T;
  cin >> R;
  cin >> N;
  cin >> M;
  cin >> K;

  cout << "Case #" << c << ": " << 1 << endl;

  for (r = 0; r < R; r++) {
    vector <int> prod;
    for (k = 0; k < K; k++) {
      int p;
      cin >> p;
      prod.push_back(p);
    }
    vector <int> ans;
    ans = guess(prod);
    int i;
    for (i = 0; i < ans.size(); i++) {
      cout << ans[i];
    }
    cout << endl;
  }

  return 0;
}
