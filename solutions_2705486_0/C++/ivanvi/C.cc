#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

#define MAX_N 128
#define MAX_K 10

#define MAX_LEN 256

void readDictionary(void);
void input(void);
void solve(void);
int dp(int pos, int k);

int n, m;
string S;
vector <string> dict;
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
}

void input(void) {
  char buf[MAX_N];
  scanf(" %s", buf);
  S = buf;
  n = S.size();
}

void solve(void) {
  memset(F, -1, sizeof(F));
  printf("Case #%d: %d\n", case_cnt++, dp(0, 5));
}

int dp(int pos, int k) {
  if (pos == n)        return 0;
  if (F[pos][k] != -1) return F[pos][k];

  int best = MAX_N;
  for (int i = 0; i < m; i++) {
    string& word = dict[i];
    int len = word.size();
    if (pos + len > n) continue;
    int cnt = 0;
    int dist = k;
    bool good = true;
    for (int j = 0; j < len; j++) {
      if (word[j] != S[pos + j]) {
        cnt++;
        if (dist < 5) {
          good = false;
          break;
        }
        dist = 1;
      } else {
        dist = min(5, dist + 1);
      }
    }
    if (good) {
      best = min(best, cnt + dp(pos + len, dist));
    }
  }

  return F[pos][k] = best;
}

