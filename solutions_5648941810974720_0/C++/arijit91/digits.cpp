#include<iostream>
#include<vector>
#include<string>
using namespace std;

int removed;

int Count(string&s, char c) {
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == c) {
      ans++;
    }
  }

  return ans;
}

int main() {
  int n;
  cin>>n;
  for (int cas = 1; cas <= n; cas++) {
    string s;
    cin>>s;

    string ans;
    removed = 0;

    int cnt[10];
    for (int i = 0; i < 10; i++) {
      cnt[i] = 0;
    }

    cnt[0] += Count(s, 'Z');
    cnt[2] += Count(s, 'W');
    cnt[6] += Count(s, 'X');
    cnt[4] += Count(s, 'U');
    cnt[8] += Count(s, 'G');
    cnt[1] += Count(s, 'O') - cnt[0] - cnt[2] - cnt[4];
    cnt[5] += Count(s, 'F') - cnt[4];
    cnt[7] += Count(s, 'V') - cnt[5];
    cnt[3] += Count(s, 'R') - cnt[0] - cnt[4];
    cnt[9] += Count(s, 'I') - cnt[5] - cnt[6] - cnt[8];

    for (int i = 0; i < 10; i++) {
      ans += string(cnt[i], '0' + i);
    }

    cout << "Case #" << cas << ": " << ans << endl;
  }
}
