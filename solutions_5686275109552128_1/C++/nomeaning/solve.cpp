#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int T;
  cin >> T;
  for(int tc = 1; tc <= T; tc++) {
    cout << "Case #" << tc << ": ";
    int d;
    cin >> d;
    vector<int> p(d);
    for(auto &a: p)cin >> a;
    int result = *max_element(p.begin(), p.end());
    for(int c = 1; c < result; c++) {
      priority_queue<int> queue;
      for(auto a: p){
        queue.push(a);
      }
      int cnt = 0;
      for(cnt = 0; queue.top() > c; cnt++) {
        int cur = queue.top();queue.pop();
        queue.push(cur - c);
        queue.push(c);
      }
      result = min(result, cnt + c);
    }
    cout << result << endl;
  }
}
