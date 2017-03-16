#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
  int T, N, x;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int biggestLoop = 0;
    vector<pair<int, int>> tuplets;
    map<int, int> tuplet_lengths;
    //cout << "Case #" << t << endl;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
      cin >> p[i];
      p[i] = p[i] - 1;
    }
    // Find all the tuplets.
    for (int i = 0; i < N; i++) {
      if (i == p[p[i]] and tuplet_lengths.count(i) == 0) {
        tuplets.push_back(make_pair(i, p[i]));
        tuplet_lengths[i] = 0;
        tuplet_lengths[p[i]] = 0;
      }
    }

    // Follow the paths up to the tuplet.
    for (int i = 0; i < N; i++) {
      if (tuplet_lengths.count(i) == 1) {
        continue;
      }
      map<int, int> seen;
      seen[i] = 1;
      int cur = p[i];
      int length = 1;
      while (true) {
        if (tuplet_lengths.count(cur) == 1) {
          tuplet_lengths[cur] = max(tuplet_lengths[cur], length);
          break;
        }
        if (seen.count(cur) == 1) {
          biggestLoop = max(biggestLoop, length - seen[cur] + 1);
          break;
        }
        length++;
        seen[cur] = length;
        cur = p[cur];
      }
    }

    // Find the maximum tuplet thing...
    int result = 0;
    for (int i = 0; i < tuplets.size(); i++) {
      result += tuplet_lengths[tuplets[i].first] + tuplet_lengths[tuplets[i].second] + 2;
    }
    printf("Case #%d: %d\n", t, max(result, biggestLoop));
    //cout << max(result, biggestLoop) << endl;  
  }

}
