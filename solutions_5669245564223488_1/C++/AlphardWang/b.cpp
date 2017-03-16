#include <cstdio>
#include <cstring>
using namespace std;

char cars[120][3];
bool del[120];
int ans, n;
int pure_cnt[50];
int m;
int mask_l[120], mask_a;
int debug = 0;

void input(){
  ans = 0;
  m = 0;
  mask_a = 0;
  memset(pure_cnt, 0, sizeof(pure_cnt));
  scanf("%d", &n);
  char str[200];
  for (int i = 0; i < n; ++ i){
    scanf("%s", str);
    int mask = 0, kind_cnt = 0, l = 0;
    for (int i = 0; str[i] != '\0'; ++ i, ++ l) {
      if ((mask & (1 << (str[i] - 'a'))) == 0) {
        ++ kind_cnt;
      } else {
        if (i > 0 && str[i] != str[i - 1]) {
          ans = -1;
        }
      }
      mask |= (1 << (str[i] - 'a'));
    }
    if (kind_cnt == 1){
      ++ pure_cnt[str[0] - 'a'];
    } else {
      cars[m][0] = str[0];
      cars[m][1] = str[l - 1];
      mask ^= (1 << (str[0] - 'a'));
      mask ^= (1 << (str[l - 1] - 'a'));
      mask_l[m] = mask;
      ++ m;
    }
  }  
}

void solve(){
  if (ans == -1) {
    ans = 0;
    return;
  }
  long long pure_t = 1;
  int k = 0;
  for (int i = 0; i < 26; ++ i){
    for (int j = 2; j <= pure_cnt[i]; ++ j) {
      pure_t *= j;
      pure_t %= 1000000007;
    }
  }
  if (m == 0) {
    for (int i = 0; i < 26; ++ i){
      if (pure_cnt[i] > 0) ++ m;
    }
    for (int j = 2; j <= m; ++ j){
      pure_t *= j;
      pure_t %= 1000000007;
    }
    ans = pure_t;
  } else {
    int mask_a = 0, mask_p = (1 << 26) - 1;
    for (int i = 0; i < m; ++ i) {
      mask_a |= mask_l[i];
      mask_p &= mask_l[i];
    }
    if (m > 1 && mask_p > 0) {
      if (debug == 1) puts("1");
      return;
    }
    for (int i = 0; i < 26; ++ i) {
      if (pure_cnt[i] > 0 && (mask_a & (1 << i)) > 0) {
        if (debug == 1) puts("1.2");
        return;
      }
    }
    int mask_h = 0;
    for (int i = 0; i < m; ++ i){
      if ((mask_h & (1 << (cars[i][0] - 'a'))) > 0) {
        if (debug == 1) puts("2");
        return;
      }
      mask_h |= (1 << (cars[i][0] - 'a'));
    }
    if ((mask_h & mask_a) > 0) {
      if (debug == 1) puts("3");
      return;
    }
    int mask_t = 0;
    for (int i = 0; i < m; ++ i){
      if ((mask_t & (1 << (cars[i][1] - 'a'))) > 0) {
        if (debug == 1) puts("4");
        return;
      }
      mask_t |= (1 << (cars[i][1] - 'a'));
    }
    if ((mask_t & mask_a) > 0) {
      if (debug == 1) puts("5");
      return;
    }
    if ((mask_t & mask_h) == ((mask_t | mask_h))){
      if (debug == 1) puts("6");
      return;
    }
    for (char c = 'a'; c <= 'z'; ++ c){
      bool t_c = (mask_t & (1 << (c - 'a'))) > 0;
      bool h_c = (mask_h & (1 << (c - 'a'))) > 0;
      if (t_c && h_c) {
        -- m;
      }
      if (t_c || h_c) {
        pure_cnt[c - 'a'] = 0;
      }
    }
    for (int i = 0; i < 26; ++ i){
      if (pure_cnt[i] > 0) ++ m;
    }
    //printf("m %d pure_t %lld\n", m, pure_t);
    for (int j = 2; j <= m; ++ j){
      pure_t *= j;
      pure_t %= 1000000007;
    }
    ans = pure_t;
  }
  
}


int main() {
  int T;
  scanf("%d", &T);
  for (int ca = 1; ca <= T; ++ ca){
    input();
    solve();
    printf("Case #%d: %d\n", ca, ans);
  }
  return 0;
}
