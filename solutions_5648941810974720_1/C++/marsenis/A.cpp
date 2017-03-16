#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char nums[10][10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
int order[] = { 0,  4,  6,  8,  5,  7,  3,  2,  1,  9 };
char dig[] =  {'Z','U','X','G','F','V','R','T','O','N'};
int h[30];
char s[2005], sol[2005];

int main() {
   int T, n;
   scanf("%d", &T);
   for (int t = 1; t <= T; t++) {
      for (int i = 0; i < 30; i++) h[i] = 0;
      n = 0;
      scanf(" %s", s);
      for (int i = 0; i < strlen(s); i++) h[s[i]-'A']++;
      for (int i = 0; i < 10; i++) {
         while (h[dig[i]-'A']) {
            for (int j = 0; j < strlen(nums[order[i]]); j++)
               h[nums[order[i]][j]-'A']--;
            sol[n++] = order[i] + '0';
         }
      }
      sol[n] = '\0';
      sort(sol, sol + n);
      printf("Case #%d: %s\n", t, sol);
   }
	return 0;
}
