#include <string.h>
#include <string>
#include <vector>
#include <iostream>

#define MAXM 26
#define MAXN 105
#define LL long long

using namespace std;

int n;
vector<string> strs;

void init() {
  cin >> n;

  strs.clear();
  for (int i = 0; i < n; ++ i) {
    string temp; cin >> temp;
    strs.push_back(temp);
  }
}

LL ret;
void solve(int now, vector<string> &strs) {
  if (now == n) {
    bool charExist[MAXM]; memset(charExist, 0, sizeof(charExist));
    string temp = "";
    for (int i = 0, isize = strs.size(); i < isize; ++ i) temp += strs[i];

    charExist[temp[0] - 'a'] = true;
    bool flag = true;
    for (int i = 1, isize = temp.size(); i < isize; ++ i) {
      if (temp[i] != temp[i - 1]) {
        int num = temp[i] - 'a';
        if (charExist[num]) { flag = false; break; }
        else charExist[num] = true;
      }
    }

    ret += flag;
  } else {
    for (int i = now; i < n; ++ i) {
      string temp = strs[now];
      strs[now] = strs[i];
      strs[i] = temp;

      solve(now + 1, strs);

      temp = strs[now];
      strs[now] = strs[i];
      strs[i] = temp;
    }
  }
}

int main() {
  int t; cin >> t;
  for (int i = 1; i <= t; ++ i) {
    ret = 0;
    init();
    solve(0, strs);
    cout << "Case #" << i << ": " << ret << endl;
  }
  return 0;
}
