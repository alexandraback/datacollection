#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

class result {
  public:
    result() {}
    int r[3], t;
};

result results[31], surprises[31];

bool comp_res(const result &a, const result &b) {
  if (a.r[0] != b.r[0])
    return a.r[0] > b.r[0];
  else if (a.r[1] != b.r[1])
    return a.r[1] > b.r[1];
  else
    return a.r[2] > b.r[2];
}

int main() {
  for (int i = 0; i <= 10; i++)
    for (int j = max(i - 1, 0); j <= i; j++)
      for (int k = max(i - 1, 0); k <= j; k++)
      {
        results[i + j + k].r[0] = i;
        results[i + j + k].r[1] = j;
        results[i + j + k].r[2] = k;
        results[i + j + k].t = i + j + k;
      }

  for (int i = 0; i <= 10; i++)
    for (int j = max(i - 2, 0); j <= i; j++)
      for (int k = max(i - 2, 0); k <= j; k++)
      {
        surprises[i + j + k].r[0] = i;
        surprises[i + j + k].r[1] = j;
        surprises[i + j + k].r[2] = k;
        surprises[i + j + k].t = i + j + k;
      }

  for (int i = 0; i < 31; i++) {
    //printf("%i: (%i, %i, %i)\n", i, results[i].r[0], results[i].r[1], results[i].r[2]);
    //printf("%i: (%i, %i, %i)\n", i, surprises[i].r[0], surprises[i].r[1], surprises[i].r[2]);
  }

  int ncases, n, s, p, t[100], count;
  result r[100];

  cin >> ncases;
  for (int caseno = 1; caseno <= ncases; caseno++)
  {
    cin >> n >> s >> p;
    for (int i = 0; i < n; i++)
    {
      cin >> t[i];
      r[i] = results[t[i]];
    }

    sort(r, r + n, comp_res);

    count = 0;
    for (int i = 0; i < n; i++)
    {
      if (r[i].r[0] >= p) {
        count++;
      } else if (s > 0 && surprises[r[i].t].r[0] >= p) {
        count++;
        s--;
      }
    }

    printf("Case #%i: %i\n", caseno, count);
  }
}
