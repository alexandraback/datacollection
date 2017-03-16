#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 2010;
char s[N];
int num[26];
int ans[10];
string str[10];
int ord[10];
int main(){
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int t; scanf("%d", &t);
  str[0] = "ZERO";
  str[1] = "ONE";
  str[2] = "TWO";
  str[3] = "THREE";
  str[4] = "FOUR";
  str[5] = "FIVE";
  str[6] = "SIX";
  str[7] = "SEVEN";
  str[8] = "EIGHT";
  str[9] = "NINE";
  ord[0] = 0; ord[1] = 4; ord[2] = 8; ord[3] = 6;
  ord[4] = 7; ord[5] = 5; ord[6] = 9; ord[7] = 1;
  ord[8] = 3; ord[9] = 2;
  while (t--){
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    memset(num, 0, sizeof num);
    memset(ans, 0, sizeof ans);
    //printf("%d\n", n);
    for (int i = 1; i <= n; ++ i){
      num[s[i] - 'A'] ++;
    }
    //for (int i = 0; i < 26; ++ i) printf("%d ", num[i]); puts("");
    for (int i = 0; i < 10; ++ i){
      int p = ord[i];
      int flag = 1;
      //printf("%d\n", p);
      while (1){
        for (int j = 0; j < str[p].length(); ++ j){
          if (num[str[p][j] - 'A'] == 0) flag = 0;
          //if (flag == 0) printf("%d %d %c\n", p, str[p][j] - 'A', str[p][j]);
        }
        if (flag == 0) break;
        ans[p] ++;
        for (int j = 0; j < str[p].length(); ++ j){
          num[str[p][j] - 'A'] --;
        }
      }
    }
    static int ca = 0;
    printf("Case #%d: ", ++ ca);
    for (int i = 0; i < 10; ++ i){
      for (int j = 0; j < ans[i]; ++ j){
        printf("%d", i);
      }
    }
    printf("\n");
  }
}
