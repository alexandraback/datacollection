#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

#define MAX_N 4005
#define MAX_K 10

#define MAX_LEN 256

struct Trie {
  bool leaf;
  Trie* next[26];

  Trie() {
    leaf = false;
    for (int i = 0; i < 26; i++) next[i] = NULL;
  }
};

void readDictionary(void);
void input(void);
void solve(void);
Trie* insertTrie(Trie* node, int pos, string& word);
int dp(int pos, int k);
int search(Trie* node, int dist, int pos, int cnt);

int n, m;
string S;
vector <string> dict;
Trie* root;
int F[MAX_N][MAX_K];
int case_cnt = 1;

int main(void) {
  readDictionary();

  int t;
  scanf("%d", &t);
  while (t--) {
    input();
    solve();
  }

  return 0;
}

void readDictionary(void) {
  char buf[MAX_LEN];
  FILE* df = fopen("garbled_email_dictionary.txt", "r");
  
  dict.clear();
  while (fscanf(df, " %s", buf) == 1) {
    dict.push_back(buf);
  }
  m = dict.size();

  root = NULL;
  for (int i = 0; i < m; i++) {
    root = insertTrie(root, 0, dict[i]);
  }
}

void input(void) {
  char buf[MAX_N];
  scanf(" %s", buf);
  S = buf;
  n = S.size();
}

Trie* insertTrie(Trie* node, int pos, string& word) {
  if (node == NULL) {
    node = new Trie();
  }
  
  if (pos == word.size()) {
    node->leaf = true;
  } else {
    node->next[word[pos] - 'a'] = insertTrie(node->next[word[pos] - 'a'], pos + 1, word);
  }

  return node;
}

void solve(void) {
  memset(F, -1, sizeof(F));
  printf("Case #%d: %d\n", case_cnt++, dp(0, 5));
}

int dp(int pos, int k) {
  if (pos == n)        return 0;
  if (F[pos][k] != -1) return F[pos][k];
  return F[pos][k] = search(root, k, pos, 0);
}

int search(Trie* node, int dist, int pos, int cnt) {
  if (node == NULL) return MAX_N;
  if (pos > n)      return MAX_N;
 
  int best = MAX_N;
  if (node->leaf) {
    best = min(best, cnt + dp(pos, dist));
  }
  if (dist < 5) {
    best = min(best, search(node->next[S[pos] - 'a'], min(5, dist + 1), pos + 1, cnt));
  } else {
    for (int i = 0; i < 26; i++) {
      bool same = (i == S[pos] - 'a') ? true : false;
      best = min(best, search(node->next[i], same ? 5 : 1, pos + 1, same ? cnt : cnt + 1));
    }
  }
  return best;
}

