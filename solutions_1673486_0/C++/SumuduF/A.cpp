#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  cout << fixed << setprecision(8);
  int nc; cin >> nc; cin.ignore(100, '\n');
  for (int cur = 1; cur <= nc; ++cur) {
    int a, b; cin >> a >> b;
    
    vector<double> p(a);
    for (int i = 0; i < a; ++i)
      cin >> p[i];

    double best = 1 + b + 1;

    vector<double> probCorrect(a+1);
    probCorrect[0] = 1;
    for (int i = 1; i <= a; ++i)
      probCorrect[i] = probCorrect[i-1]*p[i-1];

    best = min(best, b-a + 1 + (1-probCorrect[a])*(b + 1));
    for (int i = 1; i < a; ++i)
      best = min(best, i + b-a + i + 1 + (1-probCorrect[a-i])*(b + 1));

    cout << "Case #" << cur << ": " << best << '\n';
    }
  }

