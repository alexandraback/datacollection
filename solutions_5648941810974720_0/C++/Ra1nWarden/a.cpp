#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int tc;
const int maxl = 2000;
char str[maxl+5];
int len;
string words[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int cnt[26];

void reduce(int num) {
  for(int i = 0; i < words[num].length(); i++) {
    cnt[words[num][i] - 'A']--;
  }
}

vector<int> solve() {
  memset(cnt, 0, sizeof cnt);
  for(int i = 0; i < len; i++) {
    cnt[str[i] - 'A']++;
  }
  vector<int> ans;
  while(cnt['Z' - 'A']) {
    ans.push_back(0);
    reduce(0);
  }
  while(cnt['W' - 'A']) {
    ans.push_back(2);
    reduce(2);
  }
  while(cnt['X' - 'A']) {
    ans.push_back(6);
    reduce(6);
  }
  while(cnt['G' - 'A']) {
    ans.push_back(8);
    reduce(8);
  }
  while(cnt['T' - 'A']) {
    ans.push_back(3);
    reduce(3);
  }
  while(cnt['R' - 'A']) {
    ans.push_back(4);
    reduce(4);
  }
  while(cnt['F' - 'A']) {
    ans.push_back(5);
    reduce(5);
  }
  while(cnt['O' - 'A']) {
    ans.push_back(1);
    reduce(1);
  }
  while(cnt['S' - 'A']) {
    ans.push_back(7);
    reduce(7);
  }
  while(cnt['I' - 'A']) {
    ans.push_back(9);
    reduce(9);
  }
  return ans;
}

int main() {
  scanf("%d\n", &tc);
  for(int kase = 1; kase <= tc; kase++) {
    scanf("%s\n", str);
    len = strlen(str);
    printf("Case #%d: ", kase);
    vector<int> ans = solve();
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) {
      printf("%d", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
