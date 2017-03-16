#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

struct Trie {
  bool is_word;
  int next[26];

  Trie() {
    is_word = false;
    memset(next, -1, sizeof(next));
  }
};

Trie dict[2000005];
int index = 0;

int flag[1200005][50][5];

void insert(string &word) {
  int idx = 0;
  for (int i = 0; i < word.length(); i++) {
    int w = word[i] - 'a';
    if (dict[idx].next[w] == -1) {
      while (i < word.length()) {
        w = word[i] - 'a';
        dict[idx].next[w] = ++index;
        idx = index;
        i++;
      }
    } else {
      idx = dict[idx].next[w];
    }
  }
  dict[idx].is_word = true;
}

int ans;
string word;

void dfs(int idx, int s_idx, int dist, int res) {
  if (idx == -1 || res >= ans || (flag[idx][s_idx][dist] != -1 && res >= flag[idx][s_idx][dist]))
    return;

  flag[idx][s_idx][dist] = res;

  if (s_idx == word.length()) {
    if (dict[idx].is_word)
      ans = res;
    return;
  }

  if (dict[idx].is_word) {
    dfs(0, s_idx, dist, res);
  }

  int w = word[s_idx] - 'a';
  dfs(dict[idx].next[w], s_idx + 1, dist == 0 ? 0 : dist - 1, res);

  if (dist == 0) {
    for (int i = 0; i < 26; i++) {
      if (i != w) {
        dfs(dict[idx].next[i], s_idx + 1, 4, res + 1);
      }
    }
  }
  
}

int main() {
  freopen("C-small-attempt2.in", "r", stdin);
  freopen("C-small-attempt2.out", "w", stdout);

  ifstream dict_in;
  dict_in.open("garbled_email_dictionary.txt", ifstream::in);
  while (dict_in >> word) {
    insert(word);
  }

  int T;
  cin >> T;

  for (int cas = 1; cas <= T; cas++) {
    memset(flag, -1, sizeof(flag));
    cin >> word;
    ans = 100000;

    dfs(0, 0, 0, 0);
    cout << "Case #" << cas << ": " << ans << "\n";

  }

  // system("pause");
  return 0;
}
