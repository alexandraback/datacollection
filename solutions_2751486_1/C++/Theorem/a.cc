#include <map>
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


int value[1000000];
int accum[1000000];
int   yes[1000000];
int index[3000001];

void solve (int a_case) {
  int n;
  string name;
  cin >> name >> n;

  int M = name.size();

  for (int i = 0; i < M; ++i) {
    char c = name[i];
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
      value[i] = 0;
    else
      value[i] = 1;

    accum[i] = (i > 0 && value[i]) ? value[i] + accum[i-1] : value[i];
    yes[i] = accum[i] >= n;
  }

  for (int i = M; i < M + n; ++i)
    index[i] = M;

  for (int i = M -1; i >= 0; --i) {
    index[i] = yes[i] ? i : index[i+1];
  }

  //for (int i = 0; i < M; ++i)
  //  fprintf(stderr, "[%d,%d]  ", yes[i], index[i]);
  //fprintf(stderr, "\n");

  unsigned long long int total = 0;
  for (int i = 0; i < M; ++i) {
    total += M - index[i+n-1];
  }

  printf("Case #%d: %llu\n", a_case, total);
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

