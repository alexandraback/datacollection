#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> calculate(vector<int> bff, int start, int prev, vector<int> index, int count)
{
  if (index[bff[prev]] != 0) {
    if (index[bff[prev]] == count - 1) {
      //return pair<int, int>(count, min(prev, bff[prev]));
      return pair<int, int>(count, bff[prev]);
    }
    if (bff[prev] == start) {
      return pair<int, int>(count, -1);
    }
    return pair<int, int>(0, -1);
  }
  else {
    index[bff[prev]] = count + 1;
    return calculate(bff, start, bff[prev], index, count + 1);
  }
}

pair<int, int> calculate(vector<int> bff, int start)
{
  vector<int> index;
  for (int i = 0; i < bff.size(); i++) {
    index.push_back(0);
  }
  index[start] = 1;
  return calculate(bff, start, start, index, 1);
}

int solve(vector<int> bff)
{
  vector<bool> loner;
  for (int i = 0; i < bff.size(); i++) {
    loner.push_back(true);
  }
  for (int i = 0; i < bff.size(); i++) {
    loner[bff[i]] = false;
  }

  vector<int> length; // 0 if not a valid loop
  vector<int> loop; // -1 if is a full loop, index of smaller of looped pair at end otherwise
  for (int i = 0; i < bff.size(); i++) {
    pair<int, int> c = calculate(bff, i);
    length.push_back(c.first);
    loop.push_back(c.second);
  }
  //for (int i = 0; i < bff.size(); i++) {
  //  cout << length[i] << "\t" << loop[i] << "\n";
  //}
  int ans = 0;
  for (int i = 0; i < bff.size(); i++) {
    if (loop[i] == -1) {
      ans = max(ans, length[i]);
    }
  }

  int temp = 0;
  vector<bool> used;
  for (int i = 0; i < bff.size(); i++) {
    int t = 0;
    for (int j = 0; j < bff.size(); j++) {
      if (loop[j] == i) {
        t = max(t, length[j]);
      }
    }
    temp += t;
    used.push_back(t != 0);
  }
  for (int i = 0; i < bff.size(); i++) {
    if (used[i] && used[bff[i]]) {
      temp--;
    }
  }
  return max(ans, temp);
  return 0;
}

int main()
{
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<int> bff;
    for (int i = 0; i < N; i++) {
      int b;
      cin >> b;
      bff.push_back(b - 1);
    }
    cout << "Case #" << t << ": " << solve(bff) << "\n";
  }
  return 0;
}

