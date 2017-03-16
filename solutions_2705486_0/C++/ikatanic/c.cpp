#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

const int MAXQL = 4004;
const int M = 521197;
const int MAXL = 12;
const int MAXMEM = M*MAXL;

struct node {
  int c[26];
  bool finish;
};

struct Trie {
  node a[MAXMEM];
  int root, alloc;
  
  Trie() { root = 1, alloc = 2; }
  void insert(int x, char *s, int l) {
    if(l == 0) {
      a[x].finish = true;
      return;
    }
    
    int ch = s[0] - 'a';
    if(a[x].c[ch] == 0) a[x].c[ch] = alloc++;
    insert(a[x].c[ch], s+1, l-1);
  }
} T;

char q[22][MAXQL];
int dp[MAXQL][5];
int cur[M], cnt[M], last[M];
int curtmp[M], cnttmp[M], lasttmp[M];
char s[MAXL];

inline void prijelaz(int x, int &mtmp, int c, int k, int ind) {
  if(T.a[x].c[c] == 0) return;
  curtmp[mtmp] = T.a[x].c[c];
  cnttmp[mtmp] = k;
  lasttmp[mtmp++] = ind;
}

int main(void) {
  int t;
  scanf("%d", &t);
  for(int c = 1; c <= t; ++c)
    scanf("%s", q[c]);

  freopen("dict.txt", "r", stdin);
  
  for(int i = 0; i < M; ++i) {
    scanf("%s", s);
    T.insert(T.root, s, strlen(s));
  }
   
  for(int c = 1; c <= t; ++c) {
    int n = strlen(q[c]);
    for(int i = 0; i <= n; ++i)
      for(int j = 0; j < 5; ++j)
        dp[i][j] = 1000000;
    
    dp[0][4] = 0;
    for(int i = 0; i < n; ++i)
      for(int w = 0; w < 5; ++w) 
        if(dp[i][w] < 1000000) {
          int m = 0;
          cur[m] = T.root, cnt[m] = 0, last[m] = i-(w+1);
          m++;
          
          for(int j = i; j < n && m > 0; ++j) {
            int mtmp = 0;
            for(int k = 0; k < m; ++k) {
              if(last[k]+4 < j)
                for(int ch = 0; ch < 26; ++ch) 
                  if(q[c][j]-'a' != ch) prijelaz(cur[k], mtmp, ch, cnt[k]+1, j);
              prijelaz(cur[k], mtmp, (q[c][j] - 'a'), cnt[k], last[k]);
            }
            
            m = mtmp;
            for(int k = 0; k < m; ++k) {
              cur[k] = curtmp[k], cnt[k] = cnttmp[k], last[k] = lasttmp[k];
              if(T.a[cur[k]].finish) {
                int ww = min(j-last[k], 4);
                dp[j+1][ww] = min(dp[j+1][ww], dp[i][w] + cnt[k]);
              }
            }
        }
    }
 
    int ans = 1000000;
    for(int i = 0; i < 5; ++i)
      ans = min(ans, dp[n][i]);

    printf("Case #%d: %d\n", c, ans);
  }
  return 0;
}
