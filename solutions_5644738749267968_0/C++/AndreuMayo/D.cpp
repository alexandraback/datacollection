#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  for (int cas = 1; cas <= cases; ++cas) {
    cout << "Case #" << cas << ":";
    int n;
    cin >> n;
    vector<double> naomi(n);
    for (int i = 0; i < n; ++i) cin >> naomi[i];
    sort(naomi.begin(), naomi.end());
    vector<double> ken(n);
    for (int i = 0; i < n; ++i) cin >> ken[i];
    sort(ken.begin(), ken.end());
    
//     cout << endl;
//     cout.setf(ios::fixed);
//     cout.precision(3);
//     for (int i = 0; i < n; ++i) cout << naomi[i] << ' ';
//     cout << endl;
//     for (int i = 0; i < n; ++i) cout << ken[i] << ' ';
//     cout << endl;
    
    //Naomi plays Deceitful War
    int total = 0;
    int in = 0;
    int ik = 0;
    while (ik < n) {
      while (in < n and naomi[in] < ken[ik]) ++in;
      if (in == n) break;
      ++total;
      ++ik;
      ++in;
    }
    cout << ' ' << total;
    
    //Naomi plays War
    in = 0;
    ik = 0;
    while (in < n) {
      while (ik < n and ken[ik] < naomi[in]) ++ik;
      if (ik == n) break;
      ++in;
      ++ik;
    }
    cout << ' ' << n - in << endl;
  }
}
