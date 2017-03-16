#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
  int T;

  scanf("%d\n", &T);
  for(int tc = 1; tc <= T; ++ tc)
  {
    int a;
    int b;
    scanf("%d %d", &a, &b);
    //printf("%d %d\n", a, b);
    float pa[100];
    for(int i = 0; i < a; ++i) 
    {
      float p;
      scanf("%f", &p);
      //printf("%f ", p);
      pa[i] = p;
    }
    //printf("\n");
    float correct = 1;
    float sum = 0;
    float pw[100];
    float allCorrectP;
    for(int i = 0; i <= a; ++i) 
    {
      if(i >= 1) {
        correct = correct * pa[i - 1];
      }
      float wrong = 1;
      if(i < a) {
        wrong = 1 - pa[i];
      } 
      float p = correct * wrong;
      //printf("%f ", p);
      sum += p;
      if(i < a) {
        pw[i] = p;
      } else {
        allCorrectP = p;
      }
    }
    //printf(" = %f\n", sum);
    float expectedKeystrokes;
    // keep typing
    int keepTypingCorrectKeystrokes = b - a + 1;
    int keepTypingWrongKeystrokes   = b - a + 1 + b + 1;
    float keepTypingExpectedKeystrokes = allCorrectP * keepTypingCorrectKeystrokes + (1 - allCorrectP) * keepTypingWrongKeystrokes;
    //printf("keep typing = %f\n", keepTypingExpectedKeystrokes);
    expectedKeystrokes = keepTypingExpectedKeystrokes;
    // backspace
    float backspaceExpectedKeystrokes;
    float correctP = allCorrectP;
    for(int backspace = 1; backspace <= a; ++backspace)
    {
      int i = a - backspace;
      correctP += pw[i];
      int backspaceCorrectKeystrokes = b - (a - backspace) + backspace + 1;
      int backspaceWrongKeystrokes   = b - (a - backspace) + backspace + 1 + b + 1;
      float backspaceExpectedKeystrokes = correctP * backspaceCorrectKeystrokes + (1 - correctP) * backspaceWrongKeystrokes;
      //printf("backspace %d %f\n", backspace, backspaceExpectedKeystrokes);
      if(backspaceExpectedKeystrokes < expectedKeystrokes) {
        expectedKeystrokes = backspaceExpectedKeystrokes;
      }
    }
    // press enter right away
    float pressEnterRightAwayKeystrokes = 1 + b + 1;
    if(pressEnterRightAwayKeystrokes < expectedKeystrokes) {
      expectedKeystrokes = pressEnterRightAwayKeystrokes;
    }
    //printf("press enter %f\n", pressEnterRightAwayKeystrokes);
    //printf("ans %f\n", expectedKeystrokes);
    printf("Case #%d: %f\n", tc, expectedKeystrokes);

  }
}
