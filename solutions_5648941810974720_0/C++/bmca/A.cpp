#include <bits/stdc++.h>

using namespace std;

#define ST first
#define ND second
#define CLR(x) memset(x, 0, sizeof x)

typedef pair<int, int> pii;

int arr[300];
vector<int> ans;

void sub(char c, string str, int num) {
  int aux = arr[c];
  for (int i = 0; i < aux; ++i) {
    ans.push_back(num);
  }
  for (int i = 0; i < str.size(); ++i) {
    arr[str[i]] -= aux;
  }
}

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    CLR(arr);
    ans.clear();
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); ++j) {
      arr[s[j]]++;
    }
    sub('Z', "ZERO", 0);
    sub('W', "TWO", 2);
    sub('X', "SIX", 6);
    sub('G', "EIGHT", 8);
    sub('S', "SEVEN", 7);
    sub('V', "FIVE", 5);
    sub('F', "FOUR", 4);
    sub('T', "THREE", 3);
    sub('O', "ONE", 1);
    sub('I', "NINE", 9);
    sort(ans.begin(), ans.end());
    cout << "Case #" << (i + 1) << ": ";
    for (int j = 0; j < ans.size(); ++j) {
      cout << ans[j];
    }
    cout << endl;
  }
  return 0;
}
