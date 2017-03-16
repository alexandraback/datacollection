#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <list>
#include <map>

using namespace std;

unsigned long long int values[20];

void solve (int a_case)
{
  int N;
  cin >> N;

  map<unsigned long long int, int> visited;

  for (int i = 0; i < N; ++i) cin >> values[i];

  printf("Case #%d:\n", a_case);
  for (int i = 1; i < (2 << N); ++i) {
    unsigned long long int sum = 0;
    for (int j = 0; j < N; ++j) if (i & (1 << j)) sum += values[j];

    // printf("%d -> %llu\n", i, sum);

    map<unsigned long long int, int>::iterator it = visited.find(sum);
    if (it != visited.end()) {
      vector<unsigned long long int> v;
      for (int j = 0; j < N; ++j) if (i & (1 << j)) v.push_back(values[j]);
      for (int j = 0; j < v.size(); ++j) printf("%llu%s", v[j], j + 1 == v.size() ? "\n" : " ");

      v.clear();
      i = it->second;
      for (int j = 0; j < N; ++j) if (i & (1 << j)) v.push_back(values[j]);
      for (int j = 0; j < v.size(); ++j) printf("%llu%s", v[j], j + 1 == v.size() ? "\n" : " ");
      
      return;
    }

    visited[sum] = i;
  }


  puts("Impossible");
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

