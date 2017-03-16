#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;

int s[200];
bool used[200];
int main() {
  int T; cin>>T;
  for (int i = 0; i < T; i++) {
    double total = 0; int N; cin>>N;
    for (int j = 0; j < N; ++j) {
      cin>>s[j]; total += s[j]; used[j] = true;
    }
    bool changed = true; double pool = total * 2, np; int oldct = N, newct;
    while (changed) {
      changed = false; np = pool; newct = oldct;
      for (int j = 0; j < N; ++j) {
        if (!used[j]) continue;
        if (s[j]*oldct > (int) (pool+.5)) {
          np -= s[j]; newct--;
          used[j] = false; changed = true;
        }
      }
      oldct = newct; pool = np;
    }
    cout << "Case #" << (i+1) << ":" << fixed << setprecision(6);
    for (int j = 0; j < N; ++j) {
      if (!used[j]) cout << " " << 0.0;
      else {
        cout << " " << (np/newct-s[j])/total*100;
      }
    }
    cout << endl;
  }
}
