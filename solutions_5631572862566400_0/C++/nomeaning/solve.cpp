#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int a[100];
int used[100];
int N;
int ans = 0;
vector<int> t;
int recur() {
  bool ok = true;
  for(int i = 0; i < t.size(); i++) {
    int bff = a[t[i]];
    if(t[(i + 1) % t.size()] == bff || t[(i + t.size() -1) % t.size()] == bff) continue;
    if(i > 0 && i < t.size() -1) return 0;
    ok = false;
  }
  if(ok) ans = max<int>(ans, t.size());
  for(int i = 0; i < N; i++) {
    if(!used[i]) {
      t.push_back(i);
      used[i] = true;
      recur();
      used[i] = false;
      t.pop_back();
    }
  }
}
int main() {
  int T;
  cin >> T;
  for(int caze = 1; caze <= T; caze++) {
    cout << "Case #" << caze << ": ";
    cin >> N;
    for(int i = 0; i < N; i++) {
      cin >> a[i];
      a[i]--;
    }
    memset(used, 0, sizeof(used));
    ans = 0;
    t.clear();
    recur();
    cout << ans << endl;
  }
}
