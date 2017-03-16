#include <iostream>
#include <vector>
#include <cassert>

/**
 * 

5
0
1
2
11
1692

Case #1: INSOMNIA
Case #2: 10
Case #3: 90
Case #4: 110
Case #5: 5076
 */
#include <set>
using namespace std;

std::set<int> get_all_digits(int n) {
  std::set<int> ret;
  while (n>0) {
    int tmp = n % 10;
    ret.insert(tmp);
    n = n/10;
  }
  return ret;
}

void solve(int N) {
  if (N == 0) {
    cout << "INSOMNIA";
    return;
  }
  std::set<int> done;
  int multiple = 1;
  while (true) {
    std::set<int> news = get_all_digits(multiple * N);
    done.insert(news.begin(), news.end());
    if (done.size() == 10) {
      cout << multiple * N;
      return;
    }
    multiple++;
  }
}


int main() {
  int T;
  cin >> T;
  for (int i=0;i<T;i++) {
    int N;
    cin >> N;
    cout << "Case #" << i+1 << ": ";
    solve(N);
    cout  << "\n";
  }
  return 0;
}
