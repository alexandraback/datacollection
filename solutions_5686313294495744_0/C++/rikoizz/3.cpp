#include <iostream>
#include <string>
#include <set>
#include <cstdio>

using namespace std;
const int N = 1000;
string str1[N], str2[N];
set <string> s1;
set <string> s2;
int n;
int main(){
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int t; scanf("%d", &t);
  while (t -- ){
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
      cin >> str1[i] >> str2[i];
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); ++ i){
      s1.clear(); s2.clear();
      for (int j = 1; j <= n; ++ j){
        if ((i >> (j - 1)) & 1){
          s1.insert(str1[j]);
          s2.insert(str2[j]);
        }
      }
      int tmp = 0;
      for (int j = 1; j <= n; ++ j){
        if (((i >> (j - 1)) & 1) == 0){
          if (s1.find(str1[j]) != s1.end() && s2.find(str2[j]) != s2.end()){
            tmp++;
          }
        }
      }
      ans = max(ans, tmp);
    }
    static int ca = 0;
    printf("Case #%d: %d\n", ++ca, ans);
  }
}
