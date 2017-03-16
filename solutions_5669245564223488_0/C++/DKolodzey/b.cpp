#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> cars;
vector<bool> used;
vector<int> order;
long long ANS;

string getPattern(const string& s) {
  string ans;
  ans.push_back(s.front());
  for (auto it = s.begin() + 1; it != s.end(); ++it)
    if (*it != ans.back())
      ans.push_back(*it);
  return ans;
}

long long check() {
  string s;
  for (int i = 0; i < order.size(); ++i)
    s.append(cars[order[i]]);
  string s1 = getPattern(s);
  sort(s1.begin(), s1.end());
  string s2 = getPattern(s1);
  if (s2.size() == s1.size())
    return 1;
  return 0;
}
void gen(size_t done, size_t N) {
  if (done == N) {
    ANS += check();
    return;
  }
  for (size_t i = 0; i < N; ++i)
    if (!used[i]) {
      used[i] = true;
      order.push_back(i);
      gen(done + 1, N);
      used[i] = false;
      order.pop_back();
    }
}

int main() {
  int T;
  cin >> T;
  for (int testcase = 1; testcase <= T; ++testcase) {
    size_t N;
    cin >> N;
    ANS = 0;
    cars.clear();
    cars.resize(N);
    for (int i = 0; i < N; ++i) {
      cin >> cars[i];
      cars[i] = getPattern(cars[i]);
    }
    used.clear();
    used.resize(N, false);
    order.clear();
    gen(0, N);
    cout << "case #" << testcase << ": " << ANS << endl;
  }
  return 0;
}