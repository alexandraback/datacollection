#include <cstdio>

int n, s, p;

int solve(int score) {
  int mn = score / 3;
  int mx = mn + !!(score % 3);

  if (mx >= p) {
    return 1;
  }

  if (!s) { // ako nemam vise flipova
    return 0;
  }

  int flip = (score % 3 == 2) ? mx : mn;

  if (!flip) { // nemogu smanjit nulu.
    return 0;
  }

  if (flip + 1 <= mx) { // ako sa flipom necu povecat rezu.
    return 0;
  }

  if (flip + 1 >= p) { // ako s flipom idem iznad p-a.
    s--;
    return 1;
  }

  return 0;
}

void doo(int cs) {
  int score, sol = 0;
  scanf("%d%d%d", &n, &s, &p);
  for (int j = 0; j < n; ++j) {
    scanf("%d", &score);
    sol += solve(score);
  }
  printf("Case #%d: %d\n", cs, sol);
}

int main() {
  int casen;
  scanf("%d", &casen);
  for (int j = 0; j < casen; ++j)
    doo(j + 1);
  return 0;
}
