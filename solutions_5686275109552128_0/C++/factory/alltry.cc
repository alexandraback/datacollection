#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;

void rec(std::vector<int> v, int accum, int* answer) {
  std::nth_element(v.begin(), v.begin() + v.size() - 1, v.end());
  const int o = v.back();
  *answer = std::min(*answer, accum + o);

  if (o <= 2) {
    return;
  }

  {
    v.pop_back();
    v.push_back((o / 2));
    v.push_back((o / 2) + (o % 2));
    rec(v, accum + 1, answer);
    v.pop_back();
    v.pop_back();
    v.push_back(o);
  }

  {
    v.pop_back();
    v.push_back((o / 3));
    v.push_back((o / 3) + (o % 3 >= 1 ? 1 : 0));
    v.push_back((o / 3) + (o % 3 >= 2 ? 1 : 0));
    rec(v, accum + 2, answer);
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.push_back(o);
  }

  /*
  for (int& i : v) {
    --i;
  }
  rec(v, accum + 1, answer);
  for (int& i : v) {
    ++i;
  }
  */
}

int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);

  int T = 0;
  cin >> T;
  for (int tt = 1; tt <= T; ++tt) {
    std::vector<int> els;

    int current_max = 0;
    int D = 0;
    cin >> D;
    els.reserve(D);
    for (int i = 0; i < D; ++i) {
      int p = 0;
      cin >> p;
      els.push_back(p);

      current_max = std::max(current_max, p);
    }

    int answer = current_max;
    rec(els, 0, &answer);

    cout << "Case #" << tt << ": " << answer << "\n";
  }
  
  return 0;
}

