/*
  ID: nigo1
  LANG: C++
  TASK: A
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>

using namespace std;

int T;
int N;
char s[1000010];

bool isVowel(char c) {
  // a, e, i, o, and u
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
    //freopen ("A.in", "r", stdin);
    //freopen ("A.out", "w", stdout);

    scanf("%d", &T);
    for (int test = 1; test <= T; test++) {
      scanf("%s", s);
      scanf("%d\n", &N);

      int ans = 0;
      int cnt = 0;
      int n = strlen(s);
      int l = 0;

      for (int i = 0; i < n; i++) {
        if (!isVowel(s[i])) {
          cnt++;
        } else {
          cnt = 0;
        }
        if (cnt == N) {
          for (int j = l; j <= i - cnt + 1; j++) {
            ans += n - i;
            l++;
          }
          cnt--;
        }
      }

      printf("Case #%d: %d\n", test, ans);
    }

    return 0;
}

