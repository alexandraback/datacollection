#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef int64_t i64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> ii;

struct Hiker {
  int degree;
  int minutes;

  double velocity() const {
    return 360.0 / static_cast<double>(minutes);
  }

  double mins_until_goal() const {
    return static_cast<double>(minutes) * static_cast<double>(360 - degree) / 360.0;
  }
};

typedef vector<Hiker> Hikers;

bool MeetOtherHikerUntilFirstGoal(const Hiker& me, const Hiker& other) {
  const double total_min = me.mins_until_goal();
  return other.degree + other.velocity() * total_min <= 360.0;
}
bool MeetOtherHikerUntilSecondGoal(const Hiker& me, const Hiker& other) {
  other.mins_until_goal
  const double total_min = me.minutes + me.mins_until_goal();
  return other.degree + other.velocity() * total_min <= 360.0;
}

bool Check(const Hiker& me, const Hiker& other) {
  return me.mins_until_goal() * other.velocity() + other.degree < 720.0;
}

int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);

  int T = 0;
  cin >> T;
  for (int tt = 1; tt <= T; ++tt) {
    Hikers hikers;

    int N = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
      int d = 0;
      int h = 0;
      int m = 0;
      cin >> d >> h >> m;

      for (int j = 0; j < h; ++j) {
        Hiker h;
        h.degree = d;
        h.minutes = m + j;
        hikers.push_back(h);
      }
    }

    int answer = 0;
    if (hikers.size() > 1) {
      const Hiker& low_degree = (hikers[0].degree > hikers[1].degree ? hikers[1] : hikers[0]);
      const Hiker& high_degree = (hikers[0].degree > hikers[1].degree ? hikers[0] : hikers[1]);
      if (high_degree.velocity() < low_degree.velocity()) {
        if (Check(high_degree, low_degree)) {
          answer = 1;
        }
      } else {
        if (Check(low_degree, high_degree)) {
          answer = 1;
        }
      }
    }
    cout << "Case #" << tt << ": " << answer << "\n";
  }
  
  return 0;
}
