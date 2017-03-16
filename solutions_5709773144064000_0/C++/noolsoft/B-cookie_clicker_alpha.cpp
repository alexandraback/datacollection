#include <cmath>
#include <iostream>

using namespace std;

int t = 0;
double c = 0.0, f = 0.0, x = 0.0;

int NumOfFarmNeeded() {
  double dNumOfFarm = x / c - 2 / f - 1;

  return static_cast<int>(dNumOfFarm);
}

double TotalTimeByNumOfFarm(int numOfFarm) {
  double totalTime = 0.0;

  for (int i = 0; i < numOfFarm; ++i) {
    totalTime += (c / (2 + i * f));
  }

  totalTime += (x / (2 + numOfFarm * f));

  return totalTime;
}

double MinNumOfSeconds() {
  int numOfFarmNeeded = NumOfFarmNeeded() - 1;

  if (numOfFarmNeeded < 0) {
    numOfFarmNeeded = 0;
  }

  double totalTime1 = TotalTimeByNumOfFarm(numOfFarmNeeded);
  double totalTime2 = TotalTimeByNumOfFarm(numOfFarmNeeded + 1);
  double totalTime3 = TotalTimeByNumOfFarm(numOfFarmNeeded + 2);

  double minTotalTime = totalTime1;

  if (totalTime2 < minTotalTime) {
    minTotalTime = totalTime2;
  }

  if (totalTime3 < minTotalTime) {
    minTotalTime = totalTime3;
  }

  return minTotalTime;
}

int main() {
  cout.precision(7);
  cout << fixed;

  cin >> t;

  for (int caseNum = 1; caseNum <= t; ++caseNum) {
    cin >> c >> f >> x;

    cout << "Case #" << caseNum << ": " << MinNumOfSeconds() << endl;
  }

  return 0;
}

