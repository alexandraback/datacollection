#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<double> naomi;
vector<double> ken;

int nscore;
int kscore;

int nlow, nhigh;
int klow, khigh;

void badgame()
{
  while (nlow <= nhigh && klow <= khigh) {
    if (naomi[nlow] > ken[klow]) {
      nlow++;
      klow++;
      nscore++;
    } else {
      nlow++;
    }
  }
}

void turn()
{
  double n = naomi[nhigh];
  nhigh--;
  double k;
  if (ken[khigh] > n) {
    k = ken[khigh--];
    kscore++;
  } else {
    k = ken[klow++];
    nscore++;
  }
}

void resetgame(int n)
{
  nscore = kscore = 0;
  nlow = klow = 0;
  nhigh = khigh = n - 1;
}

void game()
{
  naomi.clear();
  ken.clear();

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    double input;
    scanf("%lf", &input);
    naomi.push_back(input);
  }

  for (int i = 0; i < n; i++) {
    double input;
    scanf("%lf", &input);
    ken.push_back(input);
  }

  sort(naomi.begin(), naomi.end());
  sort(ken.begin(), ken.end());

  nlow = klow = 0;
  nhigh = khigh = n - 1;

  resetgame(n);
  badgame();

  printf("%d ", nscore);

  resetgame(n);
  while (nlow <= nhigh) {
    turn();
  }

  printf("%d\n", nscore);
}

int main ()
{
  int T;
  scanf("%d", &T);

  for (int t = 1; t <= T; t++) {
    printf("Case #%d: ", t);
    game();
  }

  return 0;
}
