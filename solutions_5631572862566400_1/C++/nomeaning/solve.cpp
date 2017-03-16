#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<int> rev[2000];
int a[2000];
int N;
bool used[2000];
int get_circle_len(int cur, int start = -1) {
  if(cur == start) return 0;
  if(used[cur]) return -1000000;
  used[cur] = true;
  if(start == -1) start = cur;
  return get_circle_len(a[cur], start) + 1;
}

int dfs(int pos, int fob) {
  int ans = 0;
  for(int v: rev[pos]) {
    if(v == fob)continue;
    ans = max(ans, dfs(v, pos) + 1);
  }
  return ans;
}
int main() {
  int T;
  cin >> T;
  for(int caze = 1; caze <= T; caze++) {
    cout << "Case #" << caze << ": ";
    cin >> N;
    for(int i =0 ; i < N; i++) rev[i].clear();
    for(int i = 0; i < N; i++) {
      cin >> a[i];
      a[i]--;
      rev[a[i]].push_back(i);
    }
    int ans = 0;
    // maximum circle
    for(int i = 0; i < N; i++) {
      memset(used, 0, sizeof(used));
      ans =max(ans, get_circle_len(i));
    }
    // length 2 circle
    int sum = 0;
    for(int i = 0; i < N; i++) {
      if(a[a[i]] == i && a[i] > i) {
        sum += dfs(i, a[i]) + dfs(a[i], i) + 2;
      }
    }
    ans = max(ans, sum);
    cout << ans << endl;
  }
}
