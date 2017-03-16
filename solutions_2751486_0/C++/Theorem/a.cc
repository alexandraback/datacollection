#include <map>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


int value[100000];
int accum[100000];
int   yes[100000];
int final[100000];

void solve (int a_case) {
  int n;
  string name;
  cin >> name >> n;

  for (int i = 0; i < name.size(); ++i) {
    char c = name[i];
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
      value[i] = 0;
    else
      value[i] = 1;
    accum[i] = (i > 0 && value[i]) ? value[i] + accum[i-1] : value[i];

    yes[i] = accum[i] >= n;
    final[i] = (i == 0 ? 0 : final[i-1]) + yes[i];

    fprintf(stderr, "[%d,%d,%d,%d]  ", value[i], accum[i], yes[i], final[i]);
  }

  fprintf(stderr, "\n");

  int total = 0;
  for (int i = 0; i < name.size(); ++i)
    for (int j = i+n-1; j < name.size(); ++j) {
      for (int k = i+n-1; k <= j; ++k)
        if (yes[k]) { ++total; break;}
    }

  printf("Case #%d: %d\n", a_case, total);
}

int main ()
{
  int n;
  string dummy;

  cin >> n;
  getline(cin, dummy);
  for (int i = 0; i < n; ++i) solve(i+1);

  return 0;
}

