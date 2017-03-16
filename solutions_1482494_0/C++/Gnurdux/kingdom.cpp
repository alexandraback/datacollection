#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> twoStarPosesForOneStar[2001];
int numStarsFromDoubleAt[2001];

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    for (int i = 0; i <= 2000; i++) {
      twoStarPosesForOneStar[i].clear();
      numStarsFromDoubleAt[i] = 0;
    }
    for (int i = 0; i < N; i++) {
      int a, b;
      cin >> a >> b;
      twoStarPosesForOneStar[a].push_back(b);
      numStarsFromDoubleAt[b] += 2;
    }
    int numStars = 0;
    int ans = N;
    priority_queue<int> gettableStars;

    for (int pos : twoStarPosesForOneStar[0]) {
      gettableStars.push(pos);
    }

    int newStars = numStarsFromDoubleAt[0];
    for (;;) {
      while (numStars < newStars) {
        newStars += numStarsFromDoubleAt[++numStars];
        for (int pos : twoStarPosesForOneStar[numStars]) {
          gettableStars.push(pos);
        }
      }

      if (gettableStars.empty() || gettableStars.top() <= numStars) {
        break;
      }
      ans++;

      int pos = gettableStars.top();
      gettableStars.pop();
      numStarsFromDoubleAt[pos]--;
      newStars += 1 + numStarsFromDoubleAt[++numStars];
      for (int pos : twoStarPosesForOneStar[numStars]) {
        gettableStars.push(pos);
      }
    }

    cout << "Case #" << t << ": ";
    if (numStars < 2 * N) {
      cout << "Too Bad\n";
    } else {
      cout << ans << '\n';
    }
  }
  return 0;
}
