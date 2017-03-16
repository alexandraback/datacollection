#include <bits/stdc++.h>

using namespace std;

int solveCase ()
{
  char S[101];
  scanf("%s\n", S);
  int len = strlen(S);

  const char HAPPY = '+', BLANK = '-';
  char looking = BLANK;
  int answer = 0;
  for (int i=len-1; i>=0; i--) {
    if (S[i] == looking) {
      answer++;
      looking = looking == HAPPY ? BLANK : HAPPY;
    }
  }
  return answer;
}

int main ()
{
  int T;
  scanf("%d\n", &T);
  for (int i=1; i<=T; i++) {
    printf("Case #%d: %d\n", i, solveCase());
  }
  return 0;
}
