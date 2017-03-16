#include <iostream>
#include <cstring>
#define SIZE 20
using namespace std;

int buf[SIZE];
bool f[SIZE * 100000];
int prev[SIZE * 100000];
int main() {
  int T; cin>>T;
  for (int cN = 1; cN <= T; cN++) {
    cout << "Case #" << cN << ":" << endl;
    memset(f, 0, sizeof(f)); memset(prev, 0, sizeof(prev));
    f[0] = true;
    int N; cin>>N;
    for (int i = 0; i < N; ++i) cin>>buf[i];
    bool done = false;
    for (int i = 0; i < N && !done; ++i) {
      for (int j = SIZE * 100000; j >= 0 && !done; --j) {
        if (!f[j]) continue;
        if (f[j + buf[i]]) {
          //cout << "Found! f[" << j + buf[i] << ", prev is " << j << endl;
          done = true;
          int next = j + buf[i];
          while (next != 0) {
            int sub = next - prev[next];
            if (sub == 0) break;
            cout << sub;
            if (next != sub) cout << " ";
            else cout << endl;
            next -= sub;
          }
          next = j + buf[i]; prev[next] = j;
          while (next != 0) {
            int sub = next - prev[next]; if (sub == 0) break;
            cout << sub;
            if (next != sub) cout << " ";
            else cout << endl;
            next -= sub;
          }
        }
        f[j + buf[i]] = true; prev[j + buf[i]] = j;
        //cout << "Setting f[" << j + buf[i] << ", prev = " << j << endl;
      }
    }
    if (!done) cout << "Impossible" << endl;
  }
}
