#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T, cas;
  cin >> T;
  cas = 1;
  while (cas <= T) {
    int N;
    cin >> N;
    vector<int> num(N);
    vector<int> sums(2*(1e6), 0);
    for (int i = 0; i < N; ++i) cin >> num[i];
    cout << "Case #" << cas << ':' << endl;
    bool fi = false;
    for (int i = 1; i < 1<<20 and not fi; ++i) {
      int sum = 0;
      int cont = 0;
      for (int j = i; j > 0; j>>=1) {
        if (j&1 == 1) {
          //cerr << cont << endl;
          sum += num[cont];
        }
        cont++;
      }
      //cerr << sum << endl;
      if (sums[sum] == 0) sums[sum] = i;
      else {
        int cont = 0;
        bool primer = true;
        for (int j = sums[sum]; j > 0; j>>=1) {
          if (j&1 == 1) {
            if (primer) primer = false;
            else cout << ' ';
            cout << num[cont];
          }
          cont++;
        }
        cout << endl;
        cont = 0;
        primer = true;
        for (int j = i; j > 0; j>>=1) {
          if (j&1 == 1) {
            if (primer) primer = false;
            else cout << ' ';
            cout << num[cont];
          }
          cont++;
        }
        cout << endl;
        fi = true;
      }
    }
    if (fi == false) cout << "Impossible" << endl;
    ++cas;
  }
}