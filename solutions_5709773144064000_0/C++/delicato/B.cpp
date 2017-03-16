#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define all(c) (c).begin(), (c).end()

void solve(const int testcaseIndex) {
  cout << "Case #" << testcaseIndex + 1 << ": ";

  double C, F, X;

  cin >> C >> F >> X;

  vector<double> solutionTimes;

  double currentTime = 0.0;
  for (int numberOfFarms = 0; ; ++numberOfFarms) {
    const double currentCookieRate = 2.0 + numberOfFarms * F;

    const double winWaitTime = currentTime + X / currentCookieRate;
    if (!solutionTimes.empty() && winWaitTime >= solutionTimes.back()) {
      cout.precision(10);
      cout << solutionTimes.back() << endl;
      return;
    }

    solutionTimes.push_back(winWaitTime);

    const double waitTimeToNextFarm = C / currentCookieRate;
    currentTime += waitTimeToNextFarm;
  }
  
}


int main() {

  int T;
  cin >> T;

  rep(i, T) {
    solve(i);
  }

  return 0;
}
