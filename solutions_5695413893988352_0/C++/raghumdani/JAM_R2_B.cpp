#include <bits/stdc++.h>

using namespace std;

const int N = 20;
char s1[N], s2[N];

bool isGood(char s[], int n) {
  char ar[10];
  int nn = strlen(s);
  for(int i = nn - 1; i >= 0; --i) {
    ar[i] = n % 10 + '0';
    n /= 10;
  }
  for(int i = 0; i < nn; ++i) {
    if(s[i] == '?') continue;
    if(s[i] != ar[i]) return false;
  }
  return true;
} 

int main()
{
  freopen("IN.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int t;
  scanf("%d", &t);
  
  for(int tt = 1; tt <= t; ++tt) {
    scanf("%s %s", s1, s2);
    int n = strlen(s1);
    bool done = false; 
    int l = 1;
    for(int i = 0; i < n; ++i) l *= 10;
    for(int i = 0; i < l; ++i) {
      for(int j = 0; i + j < l; ++j) {
        if(isGood(s1, j) && isGood(s2, j + i)) {
          printf("Case #%d: %.*d %.*d", tt, n, j, n, j + i);
          done = true;
          break;
        }
        if(isGood(s1, j + i) && isGood(s2, j)) {
          printf("Case #%d: %.*d %.*d", tt, n, j + i, n, j);
          done = true;
          break;
        }
      }
      if(done) break;
    }
    printf("\n");
  }
  return (0);
}
