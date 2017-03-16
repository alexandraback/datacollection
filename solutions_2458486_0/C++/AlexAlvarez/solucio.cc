#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int key[200];
int open_key[20], chest_key[20][200];
bool M[1 << 20][20];
int kk[1 << 20][20], path[1 << 20][20];
int cas, n;

bool dp(int m, int u) {
  if (__builtin_popcount(m) == n) return true;
  bool &ans = M[m][u];
  if (kk[m][u] != cas) {
    vector<int> qtt(200, 0);
    for (int i = 0; i < 200; ++i) qtt[i] = key[i];
    for (int i = 0; i < n; ++i) {
      if ((m >> i)&1) {
        --qtt[open_key[i]];
        for (int j = 0; j < 200; ++j) qtt[j] += chest_key[i][j];
      }
    }
    
    kk[m][u] = cas;
    ans = false;
    for (int i = 0; i < n; ++i) {
      if (((m >> i)&1) == 0 and qtt[open_key[i]] > 0) {
        if (dp(m | (1 << i), i)) {
          ans = true;
          path[m][u] = i;
          break;
        }
      }
    }
  }
  return ans;
}

void print(int m, int u) {
  cout << " " << u + 1;
  if (__builtin_popcount(m) == n) return;
  int v = path[m][u];
  print(m | (1 << v), v);
}

int main() {
  int casos;
  cin >> casos;
  for (cas = 1; cas <= casos; ++cas) {
    memset(key, 0, sizeof(key));
    memset(chest_key, 0, sizeof(chest_key));
    
    int k;
    cin >> k >> n;
    
    for (int i = 0; i < k; ++i) {
      int aux;
      cin >> aux;
      ++key[aux - 1];
    }
    
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> open_key[i] >> a;
      --open_key[i];
      for (int j = 0; j < a; ++j) {
        int aux;
        cin >> aux;
        ++chest_key[i][aux - 1];
      }
    }
    
    bool ok = false;
    for (int i = 0; i < n and not ok; ++i) {
      if (key[open_key[i]] > 0 and dp(1 << i, i)) {
        ok = true;
        cout << "Case #" << cas << ":";
        print(1 << i, i);
        cout << endl;
      }
    }
    
    if (not ok) cout << "Case #" << cas << ": IMPOSSIBLE" << endl;
  }
}