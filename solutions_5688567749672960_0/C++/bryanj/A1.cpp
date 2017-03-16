#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int answer[1000005];
const int MAX = 1000000;

int next(int n) {
  int answer = 0;
  while (n > 0) {
    answer *= 10;
    answer += (n % 10);
    n /= 10;
  }
  return answer;
}

void solve() {
  for (int i = 0; i <= MAX; i++)
    answer[i] = -1;
  queue< pair<int,int> > q;
  q.push(make_pair(1, 1));
  while (!q.empty()) {
    pair<int, int> front = q.front();
    q.pop();
    if (front.first <= MAX && answer[front.first] == -1) {
      answer[front.first] = front.second;
      q.push(make_pair(front.first + 1, front.second + 1));
      q.push(make_pair(next(front.first), front.second + 1));
    }
  }
}

int main() {
  solve();
  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ti++) {
    int n;
    cin >> n;
    cout << "Case #" << ti << ": " << answer[n] << endl;
  }
}
