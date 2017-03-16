#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int E, R, N;
int v[10000000];

long long dfs(int remainE, int startIndex) {
  if (startIndex == N)
    return 0;
  long long res = 0;
  for (int spend = 0; spend <= remainE; spend++) {
    res = max(res, spend * v[startIndex] + dfs(min(remainE - spend + R, E), startIndex + 1));
  }
  return res;
}

int main() {
  int T;
  cin >> T;
  for (int CASE = 1; CASE <= T; CASE++) {
    cin >> E >> R >> N;
    for (int i = 0; i < N; i++)
      cin >> v[i];
    cout << "Case #" << CASE << ": " << dfs(E, 0) << endl;
  }
}