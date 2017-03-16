#include <iostream>
#include <string.h>
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


int graph[1001][1001];
int ngraph[1001];

bool visited[1001];

bool mark (int n)
{
  if (visited[n]) return true;
  visited[n] = true;

  for (int i = 0; i < ngraph[n]; ++i) {
    int w = graph[n][i];
    if (mark(w)) return true;
  }

  return false;
}

void solve (int a_case)
{
  int N;
  cin >> N;

  for (int i = 1; i <= N; ++i) {
    cin >> ngraph[i];
    for (int j = 0; j < ngraph[i]; ++j) cin >> graph[i][j];
  }

  bool diamond = false;
  for (int i = 1; i <= N; ++i) {
    memset(visited, 0, sizeof(visited));

    if (mark(i)) {
      diamond = true;
      break;
    }
  }

  printf("Case #%d: %s\n", a_case, diamond ? "Yes" : "No");
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

