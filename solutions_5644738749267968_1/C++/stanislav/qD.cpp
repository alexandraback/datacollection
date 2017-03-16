#include <iostream>
#include <set>

using namespace std;

set<double> read(int N) {
  set<double> input;
  for (int i = 0; i < N; i++) {
    double n; cin >> n;
    input.insert(n);
  }
  return input;
}

void run(int t) {
  int N; cin >> N;
  set<double> set1 = read(N);
  set<double> set2 = read(N);

  int dw = 0;
  auto min1 = set1.begin();
  auto min2 = set2.begin();
  while (min1 != set1.end()) {
    if (*min1 > *min2) {
      dw++;
      min2++;
    }
    min1++;
  }

  int w = 0;
  auto max1 = set1.rbegin();
  while (max1 != set1.rend()) {
    auto counter = set2.lower_bound(*max1);
    if (counter == set2.end()) {
      w++;
      set2.erase(set2.begin());
    } else {
      set2.erase(counter);
    }
    max1++;
  }

  cout << "Case #" << t << ": " << dw << " " << w << endl;
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    run(t);
  }
}
