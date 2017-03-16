#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 200;
char str1[N], str2[N];
char ans1[N], ans2[N];
int n;
ll ansn;
void dfs(int len, int flag){
  if (len == n + 1){
    ll a = 0, b = 0;
    for (int i = 1; i <= n; ++ i) a = a * 10 + str1[i] - '0';
    for (int i = 1; i <= n; ++ i) b = b * 10 + str2[i] - '0';
    if (abs(a - b) < ansn){
      for (int i = 1; i <= n; ++ i) ans1[i] = str1[i];
      for (int i = 1; i <= n; ++ i) ans2[i] = str2[i];
      ans1[n + 1] = ans2[n + 1] = '\0';
      ansn = abs(a - b);
    }
    return;
  }
  if (flag == 1){
    int flag1 = (str1[len] == '?');
    int flag2 = (str2[len] == '?');
    if (str1[len] == '?') str1[len] = '0';
    if (str2[len] == '?') str2[len] = '9';
    dfs(len + 1, 1);
    if (flag1) str1[len] = '?';
    if (flag2) str2[len] = '?';
    return;
  }
  if (flag == -1){
    int flag1 = (str1[len] == '?');
    int flag2 = (str2[len] == '?');
    if (str1[len] == '?') str1[len] = '9';
    if (str2[len] == '?') str2[len] = '0';
    dfs(len + 1, -1);
    if (flag1) str1[len] = '?';
    if (flag2) str2[len] = '?';
    return;
  }
  if (str1[len] != '?' && str2[len] != '?'){
    if (str1[len] > str2[len]) dfs(len + 1, 1);
    if (str2[len] > str1[len]) dfs(len + 1, -1);
    if (str1[len] == str2[len])dfs(len + 1, 0);
  }else if (str1[len] != '?'){
    if (str1[len] > '0'){
      str2[len] = str1[len] - 1;
      dfs(len + 1, 1);
    }
    str2[len] = str1[len];
    dfs(len + 1, 0);
    if (str1[len] < '9'){
      str2[len] = str1[len] + 1;
      dfs(len + 1, -1);
    }
    str2[len] = '?';
  }else if (str2[len] != '?'){
    if (str2[len] > '0'){
      str1[len] = str2[len] - 1;
      dfs(len + 1, -1);
    }
    str1[len] = str2[len];
    dfs(len + 1, 0);
    if (str2[len] < '9'){
      str1[len] = str2[len] + 1;
      dfs(len + 1, 1);
    }
    str1[len] = '?';
  }else{
    str1[len] = '0'; str2[len] = '0';
    dfs(len + 1, 0);
    str1[len] = '0'; str2[len] = '1';
    dfs(len + 1, -1);
    str1[len] = '1'; str2[len] = '0';
    dfs(len + 1, 1);
    str1[len] = str2[len] = '?';
  }
}
int main(){
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int t; scanf("%d", &t);
  while (t--){
    memset(str1, 0, sizeof str1);
    memset(str2, 0, sizeof str2);
    memset(ans1, 0, sizeof ans1);
    memset(ans2, 0, sizeof ans2);
    scanf("%s %s", str1 + 1, str2 + 1);
    n = strlen(str1 + 1);
    ansn = 1000000000000000000ll;
    dfs(1, 0);
    static int ca = 0;
    printf("Case #%d: %s %s\n", ++ca, ans1 + 1, ans2 + 1);
  }
}
