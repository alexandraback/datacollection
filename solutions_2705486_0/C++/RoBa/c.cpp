#include <cstdio>
#include <string>
#include <vector>
using namespace std;

const int INF = 1000100100;
vector<string> dict;
char tmp_buf[1024];
char s[4010];
int dp[4010][6];

void read_dict() {
  FILE *fp = fopen("dict.txt", "r");
  while (fscanf(fp, "%s", tmp_buf) != EOF) {
    dict.push_back((string)tmp_buf);
  }
}

int main() {
  read_dict();
  int T;
  scanf("%d",&T);
  for (int ca = 1 ; ca <= T ; ++ca) {
    scanf("%s", s);
    memset(dp, 0x3f, sizeof(dp));
    dp[0][5] = 0;
    int len = strlen(s);
    for (int i = 0 ; i < len ; ++i) {
      for (int prev = 0 ; prev <= 5 ; ++prev) {
        if (dp[i][prev] >= INF) continue;
        for (int j = 0 ; j < dict.size() ; ++j) {
          int last_error = prev;
          int k, cost = 0;
          for (k = 0 ; dict[j][k] && i+k < len ; ++k) {
            // if (i == 0) printf("j:%d k:%d error:%d\n",j,k,last_error);
            if (dict[j][k] != s[i+k]) {
              if (last_error < 5) break;
              else {++cost; last_error = 0;}
            }
            if (++last_error > 5) last_error = 5;
          }
          if (k == dict[j].size()) {
            // printf("Dklagl\n");
            if (dp[i][prev] + cost < dp[i+k][last_error])
              dp[i+k][last_error] = dp[i][prev] + cost; 
          }
        }
      }
    }
    /*
    for (int i = 0 ; i <= len ; ++i) {
      printf("i: %d", i);
      for (int j = 0 ; j <= 5 ; ++j)
        printf(" %d", dp[i][j]);
      printf("\n");
    }
    */
    int best = INF;
    for (int i = 0 ; i <= 5 ; ++i)
      if (dp[len][i] < best) best = dp[len][i];
    printf("Case #%d: %d\n", ca, best);
  }
  return 0;
}

