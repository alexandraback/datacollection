#include <map>
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;
int solvecase() {
  int L;
  cin >> L;
  vector< int > completed(L, 0);
  vector< pair<int, int> > stars;
  for (int x = 0; x < L; x++) {
    int a, b;
    cin >> a >> b;
    stars.push_back(make_pair(a, b));
  }

  int amount = 0, cstars = 0;
  while (1) {
    int oamount = amount;
    for (int x = 0; x < stars.size(); x++) {
      if (completed[x] == 2)
        continue;
      if (cstars >= stars[x].second) {
        cstars += (completed[x]) ? 1 : 2;
        completed[x] = 2;
        amount++;
      }
    }
    if (amount > oamount)
      continue;

    int minimal = -1, minimalx = -1;
    for (int x = 0; x < stars.size(); x++) {
      if (completed[x])
        continue;
      if (cstars >= stars[x].first && (minimal < stars[x].second)) {
        minimal = stars[minimalx = x].second;
      }
    }
    if (minimal == -1)
      break;

    cstars++, amount++, completed[minimalx] = 1;
  }

  for (int x = 0; x < completed.size(); x++) {
    if (completed[x] < 2) return -1;
  }
  return amount;
}
int main() {
  int N;
  cin >> N;
  for (int x = 1; x <= N; x++) {
    int s = solvecase();
    if (s == -1) 
      cout << "Case #" << x << ": Too Bad" << endl;
    else 
      cout << "Case #" << x << ": " << s << endl;
  }
  return 0;
}

