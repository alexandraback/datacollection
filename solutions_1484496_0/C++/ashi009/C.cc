#include <iostream>
#include <map>

using namespace std;

map<int, int> met;


bool dfs(int a[], int N, int start, int value, int mask) {
  if (mask ^ (1 << N)) {
    auto it = met.find(value);
    if (it != met.end() && mask != it->second) {
      int comm = it->second & mask;
      int mask1 = mask ^ comm;
      int mask2 = it->second ^ comm;
      for (int i = 0; i < N; i++)
        if (mask1 & (1 << i))
          cout << a[i] << ' ';
      cout << endl;
      for (int i = 0; i < N; i++)
        if (mask2 & (1 << i))
          cout << a[i] << ' ';
      cout << endl;
      return true;
    } else {
      met[value] = mask;
    }
  }
  if (start < N)
    if (dfs(a, N, start + 1, value + a[start], mask | (1 << start)) || 
        dfs(a, N, start + 1, value, mask))
      return true;
  return false;
}

int main (int argc, char const* argv[])
{
  int T;
  cin >> T;
  
  for (int Case = 1; Case <= T; Case++) {
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++)
      cin >> a[i];
    met.clear();
    cout << "Case #" << Case << ":" << endl;
    if (!dfs(a, N, 0, 0, 1 << N))
      cout << "Impossible" << endl;
  }
  
  return 0;
}
